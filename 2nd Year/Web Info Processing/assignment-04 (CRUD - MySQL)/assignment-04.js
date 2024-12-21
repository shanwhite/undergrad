// used Node.js and MySQL with reference from CS230 lecture slides/videos
// and w3schools: Node.js, MySQL, JSON

// NOTE: commands used in terminal: 'npm start' (which runs 'nodemon assignment-04.js')
// NOTE: might say port already in use so just control+c to restart and 'npm start' again

// REQUIREMENT (i): BACKEND
var express = require('express');
var mysql = require('mysql');
var cors = require('cors');

var app = express();

// connecting to SQL database
var con = mysql.createConnection({
    // enter your own details here
    host: "",
    user: "",       // when logging into phpmyadmin, username
    password: "",   // password
    database: ""       
});

app.use(express.json());
app.use(cors());                    // CORS to connect frontend to backend

// code referenced from Week 05 (Lecture 09) Slide 9 + w3schools
con.connect(function(err) {
    if (err) throw err;
    console.log("Connected to XXX database.\n");

    // CRUD ACTIVITY
    // C (CREATE):  create user record and add to database
    // table already created in phpMyAdmin, first user example
    // insert user information
    if (err) throw err;
    var insertInfo = "INSERT INTO UserInfo (UserID, Title, FirstName, Surname, Mobile, Email) VALUES ('1','Mr','Aidan','Plover','0859273916','aidanplover@email.com')";
    con.query(insertInfo, function(err,result) {
        if (err) throw err;
        console.log("1 record added to user info table.");
    });
    // insert home address
    if (err) throw err;
    var insertHome = "INSERT INTO HomeAddress (UserID, AddressLine1, AddressLine2, Town, CountyCity, Eircode) VALUES ('1', '10 Castle Street','Wexford','Enniscorthy', 'Wexford', 'Y21 WR89')";
    con.query(insertHome, function(err,result) {
        if (err) throw err;
        console.log("1 record added to home address table.");
    });
    // insert mailing address
    if (err) throw err;
    var insertShipping = "INSERT INTO ShippingAddress (UserID, AddressLine1, AddressLine2, Town, CountyCity, Eircode) VALUES ('1', '10 Castle Street','Wexford','Enniscorthy', 'Wexford', 'Y21 WR89')";
    con.query(insertShipping, function(err,result) {
        if (err) throw err;
        console.log("1 record added to shipping address table.\n");
    });

    // second user example
    // insert user information
    if (err) throw err;
    var insertInfo = "INSERT INTO UserInfo (UserID, Title, FirstName, Surname, Mobile, Email) VALUES ('2','Mr','John','Doe','0877482648','johndoe@email.com')";
    con.query(insertInfo, function(err,result) {
        if (err) throw err;
        console.log("1 record added to user info table.");
    });
    // insert home address
    if (err) throw err;
    var insertHome = "INSERT INTO HomeAddress (UserID, AddressLine1, AddressLine2, Town, CountyCity, Eircode) VALUES ('2', '79 Jamestown Road','Fingal','Swords', 'Dublin', 'D11 DT98')";
    con.query(insertHome, function(err,result) {
        if (err) throw err;
        console.log("1 record added to home address table.");
    });
    // insert mailing address
    if (err) throw err;
    var insertShipping = "INSERT INTO ShippingAddress (UserID, AddressLine1, AddressLine2, Town, CountyCity, Eircode) VALUES ('2', '79 Jamestown Road','Fingal','Swords', 'Dublin', 'D11 DT98')";
    con.query(insertShipping, function(err,result) {
        if (err) throw err;
        console.log("1 record added to shipping address table.\n");
    });

    // third user example
    // insert user information
    if (err) throw err;
    var insertInfo = "INSERT INTO UserInfo (UserID, Title, FirstName, Surname, Mobile, Email) VALUES ('3','Ms','Ciara','Boyle','0831946294','ciaraboyle@email.com')";
    con.query(insertInfo, function(err,result) {
        if (err) throw err;
        console.log("1 record added to user info table.");
    });
    // insert home address
    if (err) throw err;
    var insertHome = "INSERT INTO HomeAddress (UserID, AddressLine1, AddressLine2, Town, CountyCity, Eircode) VALUES ('3', '98 Brickwell Lane','Dublin 4','Dublin', 'Dublin', 'D04 WR89')";
    con.query(insertHome, function(err,result) {
        if (err) throw err;
        console.log("1 record added to home address table.");
    });
    // insert mailing address
    if (err) throw err;
    var insertShipping = "INSERT INTO ShippingAddress (UserID, AddressLine1, AddressLine2, Town, CountyCity, Eircode) VALUES ('3', '98 Brickwell Lane','Dublin 4','Dublin', 'Dublin', 'D04 WR89')";
    con.query(insertShipping, function(err,result) {
        if (err) throw err;
        console.log("1 record added to shipping address table.\n");
    });


    // R (RETRIEVE/SEARCH): select and return all users matching supplied name
    var name = "Aidan";    // chose 'Aidan' for supplied name
    con.query("SELECT * FROM UserInfo WHERE FirstName = ?", [name], function(err,result) {  // ? acts as placeholder so that it'd read as string value instead of column name (that error occurs if '"FirstName = " + name,' is written)
        if (err) throw err;
        console.log("Retrieved Info: \n", result);    // result -> all users with matching name, result[0] means the first in the list
        console.log("");
    });


    // U (UPDATE): update three elements of specified user record (title, mobile, email) and all/any address data
    con.query("Update UserInfo SET Mobile = '0870148172', Email = 'aidanplover24@email.com', Title = 'Dr' WHERE UserId = '1'", function (err, result){
        if (err) throw err;
        console.log("1 record updated for user info table.");

    });
    con.query("Update HomeAddress SET AddressLine1 = '26 Great Strand St', AddressLine2 = 'Dublin 1', Town = 'Dublin', CountyCity = 'Dublin', Eircode = 'D01R3P6' WHERE UserId = '1'", function (err, result){
        if (err) throw err;
        console.log("1 record updated for home address table.");

    });
    con.query("Update ShippingAddress SET AddressLine1 = '26 Great Strand St', AddressLine2 = 'Dublin 1', Town = 'Dublin', CountyCity = 'Dublin', Eircode = 'D01R3P6' WHERE UserId = '1'", function (err, result){
        if (err) throw err;
        console.log("1 record updated for shipping address table.\n");

    });


    // D (DELETE): delete all records for a user matching a combi of name, mobile, email
    // change the values in the SELECT line for firstname, mobile & email to delete other users (I hardcoded it)
    con.query("SELECT * FROM UserInfo WHERE FirstName = 'Ciara' AND Mobile = '0831946294' AND Email = 'ciaraboyle@email.com'", function (err, result) {
        if (err) throw err;
        con.query("DELETE FROM UserInfo WHERE UserID = " + result[0].UserID, function (err, result) {
            if (err) throw err;
            console.log("1 record deleted from user info table.");
        });
        con.query("DELETE FROM HomeAddress WHERE UserID = " + result[0].UserID, function (err, result) {
            if (err) throw err;
            console.log("1 corresponding record deleted from home address table.");
        });
        con.query("DELETE FROM ShippingAddress WHERE UserID = " + result[0].UserID, function (err, result) {
            if (err) throw err;
            console.log("1 corresponding record deleted from shipping address table.\n");
        });
    });
});



// REQUIREMENT (ii): FRONTEND
// source: resources from inter-semester break section on Moodle
var http = require("http");                         // create API using http
var url = require("url");                           // use url to extract route ('/' or '/api/user')
var querystring = require("querystring");           // contain body of POST req
var fs = require("fs");                             // file handling to read html file for '/' route (file system)
var port = 1101;

var server = http.createServer();                   // create server

var userDatabase = []                               // in-memory database to hold JSON records

// listen for requests from clients
server.on("request", function (request, response) {
    var currentRoute = url.format(request.url);     // route ('/' or '/api/user')
    var currentMethod = request.method;             // http req type (POST/GET for create/retrieve)
    var requestBody = "";                           // to contain extracted POST data

    switch(currentRoute) {
        // if no API call is made; default route
        case "/":
            fs.readFile(__dirname + "/assignment-04.html", function (err, data) {
                // get the file and add to data
                var headers = {
                    // set the appropriate headers
                    "Content-Type": "text/html",
                    "Access-Control-Allow-Origin": "*",      // CORS to link frontend & backend
                };
                response.writeHead(200, headers);
                response.end(data);                          // return the data (assignment-04html)
            }); // as part of the response

            break;

        // paths for CRUD activity
        case "/api/user": 
            // C (CREATE):  create user record and add to database
            if (currentMethod === "POST") {
                // read body of POST request
                request.on ("data", function (chunk) {
                    requestBody += chunk.toString();
                });

                const { headers } = request;
                let ctype = headers["content-type"];
                console.log("RECEIVED Content-Type: " + ctype + "\n");

                // finished reading the body of the request
                request.on("end", function () {
                    var userData = "";
                    // saving the user from the body to the database
                    if (ctype.match(new RegExp("^application/x-www-form-urlencoded"))) {
                        userData = querystring.parse(requestBody);
                    } else {
                        userData = JSON.parse(requestBody);
                    }
                    userDatabase.push(userData);
                
                    // log the user data to console
                    console.log(
                        "USER DATA RECEIVED: \n\n" +
                        JSON.stringify(userData, null, 2) +
                        "\n"
                    );

                    var headers = {
                        "Content-Type": "text/plain",
                        "Access-Control-Allow-Origin": "*",
                    };
                    response.writeHead(200, headers);
                    response.end("User (" + userData.firstname + " " + userData.surname + ") data added to the Database!");
                });
            } 

            // R (RETRIEVE/SEARCH): select and return all users matching supplied name
            else if (currentMethod === "GET") {
                var headers = {
                    "Content-Type": "application/json",
                    "Access-Control-Allow-Origin": "*",
                };
                console.log(
                    "USER DATABASE REQUESTED: \n\n" +
                        JSON.stringify(userDatabase, null, 2) +
                        "\n"
                );
                response.writeHead(200, headers);
                response.end(JSON.stringify(userDatabase));
            }

            // EXTRA CREDIT
            // U (UPDATE): update three elements of specified user record (title, mobile, email) and all/any address data
            else if (currentMethod === "PUT") {
                // read body of POST request
                request.on ("data", function (chunk) {
                    requestBody += chunk.toString();
                });

                const { headers } = request;
                let ctype = headers["content-type"];
                console.log("RECEIVED Content-Type: " + ctype + "\n");

                // finished reading the body of the request
                request.on("end", function () {
                    var userData = "";
                    // saving the user from the body to the database
                    if (ctype.match(new RegExp("^application/x-www-form-urlencoded"))) {
                        userData = querystring.parse(requestBody);
                    } else {
                        userData = JSON.parse(requestBody);
                    }
                    userDatabase.push(userData);
                
                    // log the user data to console
                    console.log(
                        "USER DATA RECEIVED: \n\n" +
                        JSON.stringify(userData, null, 2) +
                        "\n"
                    );

                    var headers = {
                        "Content-Type": "text/plain",
                        "Access-Control-Allow-Origin": "*",
                    };
                    response.writeHead(200, headers);
                    response.end("User (" + userData.firstname + " " + userData.surname + ")'s information has been updated in the Database!");
                });
            }

            // D (DELETE): delete all records for a user matching a combi of name, mobile, email
            else if (currentMethod === "DELETE") {
                var headers = {
                    "Content-Type": "application/json",
                    "Access-Control-Allow-Origin": "*",
                };
                
                response.writeHead(200, headers);
                response.end(JSON.stringify(userDatabase));
            }

            break;
    }
});


// set up HTTP server and listen on port 1101
server.listen(port, function () {
  console.log("Server running on port: " + port + "\n");
});
