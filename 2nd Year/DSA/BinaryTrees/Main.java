// CS211 LAB 5
// Binary Trees

package BinaryTrees;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        BinaryTrees tree = new BinaryTrees();
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the numbers to insert: ");
        // String numbers = "8,3,1,6,4,7,10,14,13";
        String numbers = in.next();     // takes in user input
        String[] values = numbers.split(",");   // splits the string into separate numbers for array
        in.close();

        for (String num : values) {    // runs through all elements in the String array
            tree.insert(Integer.parseInt(num.trim()));    // convert String[] to int[]
        }
        System.out.println("The resulting binary tree has " + tree.maxDepth(tree.root) + " levels.");
    }
}