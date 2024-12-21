// tested with macOS (Sonoma 14.1.2)
// referenced w3schools (Node.js MongoDB & MongoDB Tutorial)
// reused user information from assignment 4 for customer information in this assignment

// *** NOTE: will need to drop table on MongoDB after every run of 'node assignment-05.js' bc same '_id'
// *** I already dropped the table before submitting this assignment
const { MongoClient, ServerApiVersion } = require('mongodb');
const url = ""; // enter your own mongoDB database url here

// Create a MongoClient with a MongoClientOptions object to set the Stable API version
const client = new MongoClient(url, {
    serverApi: {
        version: ServerApiVersion.v1,
        strict: true,
        deprecationErrors: true,
    }
});

async function run() {
    try {
        await client.connect();   // connect client to server
        const db = client.db("MobilePhoneStore");   // declare database
        console.log("You have successfully connected to MongoDB!");


        // CREATE
        // personal details
        const col0 = db.collection("CustomerInfo");     // can also createCollection() but I decided to create them in the insert process
        const col1 = db.collection("HomeAddress");
        const col2 = db.collection("ShippingAddress");
        await insertCustomer(col0,col1,col2);
        // item details
        const col3 = db.collection("ItemDetails");
        await insertItem(col3);
        // order details
        const col4 = db.collection("OrderDetails");
        await insertOrder(col4);


        // RETRIEVE
        // personal details
        await findCustomer(col0,col1,col2);
        // item details
        await findItem(col3);
        // order details
        await findOrder(col4);


        // UPDATE
        // personal details
        await updateCustomer(col0,col1,col2);
        // item details
        await updateItem(col3);
        // order details
        await updateOrder(col4);


        // DELETE
        // personal details
        await deleteCustomer(col0,col1,col2);
        // item details
        await deleteItem(col3);
        // order details
        await deleteOrder(col4);

    } finally {
        // Ensures that the client will close when you finish/error
        await client.close();
    }
}


// CREATE - personal details
// create the customer document (personal and address),
// and add it to the database using a method insertCustomer(<details>)
async function insertCustomer(col0,col1,col2) {
    // can also do insertMany but i wanted to separate it to
    // insert into customerinfo, homeaddress and shipping address for each customer
    // rather than insert multiple customers' details into each collection at the same time

    // FIRST CUSTOMER
    // CustomerInfo
    await col0.insertOne({      // creating collection through insert
        "_id": 1,               // _id to overwrite the one in mongoDB (so it won't be an object key string)
        "title": "Mr",
        "firstname": "Joe",
        "surname": "Bloggs",
        "mobile": "0891237890",
        "email": "joe.bloggs@somewhere.com"
    });
    console.log("1 customer inserted into CustomerInfo.");
    // HomeAddress
    await col1.insertOne({
        "_id": 1,
        "addressline1": "Number 123",
        "addressline2": "Brickwell Lane",
        "town": "Dublin 3",
        "countycity": "Dublin",
        "eircode": "D03 W92B"
    });
    console.log("1 customer inserted into HomeAddress.");
    // ShippingAddress
    await col2.insertOne({
        "_id": 1,
        "addressline1": "Number 123",
        "addressline2": "Brickwell Lane",
        "town": "Dublin 3",
        "countycity": "Dublin",
        "eircode": "D03 W92B"
    });
    console.log("1 customer inserted into ShippingAddress.");
    console.log();

    // SECOND CUSTOMER
    // CustomerInfo
    await col0.insertOne({
        "_id": 2,
        "title": "Dr",
        "firstname": "Julie",
        "surname": "James",
        "mobile": "0834918591",
        "email": "julie@james.com"
    });
    console.log("1 customer inserted into CustomerInfo.");
    // HomeAddress
    await col1.insertOne({
        "_id": 2,
        "addressline1": "94 Cedar Lane",
        "addressline2": "Maynooth Estates",
        "town": "Maynooth",
        "countycity": "Kildare",
        "eircode": "W23 L94Z"
    });
    console.log("1 customer inserted into HomeAddress.");
    // ShippingAddress
    await col2.insertOne({
        "_id": 2,
        "addressline1": "94 Cedar Lane",
        "addressline2": "Maynooth Estates",
        "town": "Maynooth",
        "countycity": "Kildare",
        "eircode": "W23 L94Z"
    });
    console.log("1 customer inserted into ShippingAddress.");
    console.log();

    // THIRD CUSTOMER
    // CustomerInfo
    await col0.insertOne({
        "_id": 3,
        "title": "Miss",
        "firstname": "Jocelyn",
        "surname": "Kim",
        "mobile": "0851894231",
        "email": "jocelyn.kim@mu.ie"
    });
    console.log("1 customer inserted into CustomerInfo.");
    // HomeAddress
    await col1.insertOne({
        "_id": 3,
        "addressline1": "789 Stonewood Alley",
        "addressline2": "Ballymote Residences",
        "town": "Ballymote",
        "countycity": "Sligo",
        "eircode": "F56 PV38"
    });
    console.log("1 customer inserted into HomeAddress.");
    // ShippingAddress
    await col2.insertOne({
        "_id": 3,
        "addressline1": "Maple 3A Courtyard Apartments",
        "addressline2": "Maynooth University",
        "town": "Maynooth",
        "countycity": "Kildare",
        "eircode": "W23 C6T0"
    });
    console.log("1 customer inserted into ShippingAddress.");
    console.log();


    // *** FOURTH CUSTOMER -- only added in to test deleteCustomer(), so will not include in the random selections 
    // CustomerInfo
    await col0.insertOne({
        "_id": 4,
        "title": "Mr",
        "firstname": "Bob",
        "surname": "Dylan",
        "mobile": "0878298274",
        "email": "bob.dylan@mail.com"
    });
    console.log("1 customer inserted into CustomerInfo.");
    // HomeAddress
    await col1.insertOne({
        "_id": 4,
        "addressline1": "Cedar 2B Courtyard Apartments",
        "addressline2": "Maynooth University",
        "town": "Maynooth",
        "countycity": "Kildare",
        "eircode": "W23 C6T0"
    });
    console.log("1 customer inserted into HomeAddress.");
    // ShippingAddress
    await col2.insertOne({
        "_id": 4,
        "addressline1": "Cedar 2B Courtyard Apartments",
        "addressline2": "Maynooth University",
        "town": "Maynooth",
        "countycity": "Kildare",
        "eircode": "W23 C6T0"
    });
    console.log("1 customer inserted into ShippingAddress.");
    console.log();
}

// CREATE - item details
async function insertItem(col3) {
    await col3.insertOne({
        "_id": 1,
        "manufacturer": "Apple",
        "model": "iPhone 11",
        "price": "€300"
    });
    console.log("1 item inserted into ItemDetails.");

    await col3.insertOne({
        "_id": 2,
        "manufacturer": "Apple",
        "model": "iPhone 14",
        "price": "€600"
    });
    console.log("1 item inserted into ItemDetails.");

    await col3.insertOne({
        "_id": 3,
        "manufacturer": "Samsung",
        "model": "Galaxy S22",
        "price": "€750"
    });
    console.log("1 item inserted into ItemDetails.");

    await col3.insertOne({
        "_id": 4,
        "manufacturer": "Samsung",
        "model": "Galaxy A34",
        "price": "€400"
    });
    console.log("1 item inserted into ItemDetails.");

    await col3.insertOne({
        "_id": 5,
        "manufacturer": "Xiaomi",
        "model": "Redmi 13C",
        "price": "€150"
    });
    console.log("1 item inserted into ItemDetails.");
    console.log();
}

// CREATE - order details
async function insertOrder(col4) {
    await col4.insertOne({
        "_id": 1,
        "customerID": 1,
        "phones": ["iPhone 14"]    // 'phones' is the name of the array (for future functions)
    })
    console.log("1 order inserted into OrderDetails.");

    await col4.insertOne({
        "_id": 2,
        "customerID": 2,
        "phones": ["iPhone 11", "Galaxy A34", "Redmi 13C"]
    })
    console.log("1 order inserted into OrderDetails.");

    await col4.insertOne({
        "_id": 3,
        "customerID": 1,
        "phones": ["Galaxy S22"]
    })
    console.log("1 order inserted into OrderDetails.");

    await col4.insertOne({
        "_id": 4,
        "customerID": 3,
        "phones": ["iPhone 11", "Redmi 13C"]
    })
    console.log("1 order inserted into OrderDetails.");

    await col4.insertOne({
        "_id": 5,
        "customerID": 2,
        "phones": ["Galaxy A34"]
    })
    console.log("1 order inserted into OrderDetails.");
    console.log();
}


// RETRIEVE - personal details
// randomly select a customer and output (not raw object) the details (log to console) using findCustomer(<details>)
async function findCustomer(col0,col1,col2) {
    var num = Math.floor(Math.random()*3)+1;  // generate number from 1-3 (randomly select customer)
    console.log("CUSTOMER DETAILS:");
    // CustomerInfo
    var result = await col0.find({            // doesn't work if const (either this line or num on top but just changed both to var anyway)
        _id: num
    }).toArray();                             // add values to array (to print)
    // print results (from CustomerInfo) by logging to console
    console.log("PERSONAL INFORMATION");
    console.log("Customer ID: " + result[0]._id);  // result[0] since selected customer will appear as first entry (so entry 0)
    console.log("Title: " + result[0].title);
    console.log("First Name: " + result[0].firstname);
    console.log("Surname: " + result[0].surname);
    console.log("Mobile: " + result[0].mobile);
    console.log("Email: " + result[0].email);

    // HomeAddress
    result = await col1.find({    // already declared as variable in CustomerInfo, just updating the value to print output again
        _id: num
    }).toArray();
    // print results (from HomeAddress) by logging to console
    console.log("HOME ADDRESS");
    console.log("Customer ID: " + result[0]._id);
    console.log("Address Line 1: " + result[0].addressline1);
    console.log("Address Line 2: " + result[0].addressline2);
    console.log("Town: " + result[0].town);
    console.log("County/City: " + result[0].countycity);
    console.log("Eircode: " + result[0].eircode);
    
    // ShippingAddress
    result = await col2.find({
        _id: num
    }).toArray();
    // print results (from ShippingAddress) by logging to console
    console.log("SHIPPING ADDRESS");
    console.log("Customer ID: " + result[0]._id);
    console.log("Address Line 1: " + result[0].addressline1);
    console.log("Address Line 2: " + result[0].addressline2);
    console.log("Town: " + result[0].town);
    console.log("County/City: " + result[0].countycity);
    console.log("Eircode: " + result[0].eircode);
    console.log();
}

// RETRIEVE - item details
async function findItem(col3) {
    var num = Math.floor(Math.random()*5)+1;  // generate number from 1-5 (randomly select item)
    console.log("ITEM DETAILS:");
    // add values to array (to print)
    var result = await col3.find({
        _id: num
    }).toArray();
    // print results (from ItemDetails) by logging to console
    console.log("Item ID: " + result[0]._id);
    console.log("Manufacturer: " + result[0].manufacturer);
    console.log("Model: "  + result[0].model);
    console.log("Price: " + result[0].price);
    console.log();
}

// RETRIEVE - order details
async function findOrder(col4) {
    var num = Math.floor(Math.random()*5)+1;  // generate number from 1-5 (randomly select order)
    console.log("ORDER DETAILS:");
    // add values to array (to print)
    var result = await col4.find({
        _id: num
    }).toArray();
    // print results (from ItemDetails) by logging to console
    console.log("Order ID: " + result[0]._id);
    console.log("Customer ID: " + result[0].customerID);
    // print array ('phones' from insertOrder)
    var arr = result[0].phones;
    for (var i=0; i<arr.length; i++) {
        console.log("Order: " + arr[i]);
    }
    console.log();
}


// UPDATE - personal details
// randomly select a customer and update three elements of their personal (title, mobile, email)
// and all or any of their address data using updateCustomer(<details>)
// *** NOTE: did not log the updated information to console but on cloud.mongodb.com, the values changed
async function updateCustomer(col0,col1,col2) {
    var num = Math.floor(Math.random()*3)+1;  // generate number from 1-3 (randomly select customer)
    // update CustomerInfo collection
    await col0.updateOne ({
        _id: num
    }, {
        $set: {
            title: "Dr",
            mobile: "0873746294",
            email: "hello@bye.com"
        }
    });
    // update HomeAddress collection
    await col1.updateOne ({
        _id: num
    }, {
        $set: {
            countycity: "Galway"
        }
    });
    // update ShippingAddress collection
    await col2.updateOne ({
        _id: num
    }, {
        $set: {
            countycity: "Galway"
        }
    });
    console.log("The details of 1 customer (Customer ID: " + num + ") have been been updated.");
}

// UPDATE - item details
async function updateItem(col3) {
    var num = Math.floor(Math.random()*5)+1;  // generate number from 1-5 (randomly select item)
    await col3.updateOne ({
        _id: num
    }, {
        $set: {
            price: "€500"
        }
    });
    console.log("The details of 1 item (Item ID: " + num + ") have been updated.");
}

// UPDATE - order details
async function updateOrder(col4) {
    var num = Math.floor(Math.random()*5)+1;  // generate number from 1-5 (randomly select order)
    await col4.updateOne ({
        _id: num
    }, {
        $set: {
            phones: "iPhone 14"
        }
    });
    console.log("The details of 1 order (Order ID: " + num + ") have been updated.");
    console.log();
}

// DELETE - personal details
// delete all records for a customer matching a specified email, phone and name using deleteCustomer(<details>)
async function deleteCustomer(col0,col1,col2) {
    // search for specified customer
    var result = await col0.find({
        firstname: "Bob",    
        surname: "Dylan",
        mobile: "0878298274",
        email: "bob.dylan@mail.com"
    }).toArray();

    var id = result[0]._id;    // match _id from CustomerInfo to HomeAddress & ShippingAddress

    // delete from CustomerInfo
    await col0.deleteOne({
        _id: id
    });
    // delete from HomeAddress
    await col1.deleteOne({
        _id: id
    });
    // delete from ShippingAddress
    await col2.deleteOne({
        _id: id
    });
    console.log("1 customer ('Bob Dylan') has been deleted.");
}

// DELETE - item details
// chose to randomly delete an item
async function deleteItem(col3) {
    var num = Math.floor(Math.random()*5)+1;
    await col3.deleteOne({
        _id: num
    });
    console.log("1 item (Item ID: " + num + ") has been deleted.");
}

// DELETE - order details
// chose to randomly delete an order
async function deleteOrder(col4) {
    var num = Math.floor(Math.random()*5)+1;
    await col4.deleteOne({
        _id: num
    })
    console.log("1 order (Order ID: " + num + ") has been deleted.");
}

run().catch(console.dir);



// DATA MODELLING APPROACH:
/* I followed what I did for Assignment 04 and created 3 collections for Personal Details,
namely CustomerInfo, HomeAddress and ShippingAddress, then 1 each for Item Details and Order Details.

The more logical way for inserting data into the 3 collections would be to add in data into each collection,
such that it'd be CustomerInfo x3 -> HomeAddress x3 -> ShippingAddress x3 but it flowed better to me as
(CustomerInfo -> HomeAddress -> ShippingAddress) x3. I was also thinking between using insertOne() and
insertMany() but decided to go with insertOne().

The CustomerInfo, HomeAddress and ShippingAddress collections all share the same id (_id), so that the
data for each customer is linked among the three collections and can be easily referenced.

The entries in the ItemDetails collection have a unique id, which is linked to the OrderDetails collection.
OrderDetails also includes the id from the CustomerInfo collection so that the customer who made the order
can be easily identified.

I also standardised the spacings in each function as a personal preference since I prefer my code to be
organised. Making the code look more organised helps me to skim through my code and spot any outliers,
which is helpful when I am trying to debug my code. 

I was facing a lot of issues with deleteCustomer so I ended up adding in an additional customer just
to test the deleteCustomer method. I know that we were meant to randomly select a customer and update
the details for them, but I only included customer with IDs 1, 2 or 3 as part of the random selection
and left out customer 4, if not I wouldn't know if the chosen customer to be deleted had gone through
the updateCustomer function and had their mobile & email changed. */