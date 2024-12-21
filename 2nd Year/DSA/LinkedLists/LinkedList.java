package LinkedLists;
// CS211 LAB 4
// Linked Lists

// java implementation of linked list from slides
public class LinkedList {
    private Link first;         // reference to first link

    public LinkedList() {       // constructor
        first = null;           // no links on that list yet
    }

    public boolean isEmpty() {  // true if list is empty
        return (first==null);
    }

    // insert at head
    public void insertHead(String word) {   // make new link
        Link newLink = new Link(word);
        newLink.next = first;               // newLink --> old first
        first = newLink;                    // first --> newLink
    }

    public Link removeHead() {      // delete first item (assumes list not empty)
        Link temp = first;          // save reference to link
        first = first.next;         // delete it; first --> old next
        return temp;                // return deleted link
    }

    public void display() {
        Link current = first;
        while (current!=null) {
            System.out.println(current.display());
            current = current.next;
        }
    }
}
