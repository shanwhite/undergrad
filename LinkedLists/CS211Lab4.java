package LinkedLists;
// CS211 LAB 4
// Linked Lists

import java.util.*;

public class CS211Lab4 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        LinkedList list  = new LinkedList();

        String input;
        while (true) {
            System.out.print("Enter a word (enter 'END' to stop): ");
            input = in.nextLine();
            if (input.equals("END")) {
                break;  // breaks the loop of asking for user input once user says END
            }
            list.insertHead(input); // adds word to the list
        }
        list.display(); // prints out word
        in.close();
    }
}