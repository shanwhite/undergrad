// CS211 LAB 4
// Linked Lists

// link class to represent each element of the linked list
class Link {
    public String data; // data item
    public Link next;   // next link in list

    public Link(String data) {  // constructor
        this.data = data;       // initialise data
                                // 'next' is automatically set to null
    }   

    public String display() {   // print out data
        return data;
    }
}

