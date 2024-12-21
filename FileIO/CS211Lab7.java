package FileIO;

import java.io.File;
import java.util.*;

public class CS211Lab7 {
    public static void main(String[] args) {
        Tree tree = new Tree();

        // load file document
        File file = new File("/Users/shan/Desktop/uni/y2s2/CS211/CS211Lab7/EnglishSpanish.csv");
        int inputSize = 28636;      // no. of rows in EnglishSpanish.csv

        // initialising elements
        String[] input = new String[inputSize];
        String[] english = new String[inputSize];
        String[] spanish = new String[inputSize];

        // loading file and sorting words into arrays
        try {
            Scanner sc = new Scanner(file);
            // split the input array into english and spanish arrays
            for (int i=0; i<inputSize; i++) {
                input[i] = sc.nextLine();
                String[] words = input[i].split(",");   // split at comma, al
                english[i] = words[0];
                spanish[i] = words[1];
            }
            sc.close();
        } catch (Exception e) {
            System.err.println(e);
        }

        System.out.println("Tree height: " + tree.height());
        Scanner in = new Scanner(System.in);
        System.out.println("Enter English text to be translated: ");
        String text = in.nextLine();
        in.close();

        // translate the text
        String[] text = text.split(" ");    // split the string at each word to translate individually
        for (int i=0; i<text.length; i++) {
            System.out.print(tree.translate(text[i]) + " ");
        }
        System.out.println();
        System.out.println("Steps: " + tree.steps());
    }
}

class Node {
    String english;
    String spanish;
    Node left, right;

    public Node(String english, String spanish) {
        this.english = english;
        this.spanish = spanish;
        left = right = null;
    }
}

class Tree {
    Node root;
    int steps=0;
    
    public Tree() {
        root = null;
    }

    public void insert(String english, String spanish) {
        root = insertRec(root, english, spanish);
    }

    // recursively insert nodes into tree
    public insertRec(Node current, String english, String spanish) {
        if (current==null) {
            return new Node(english, spanish);
        }

        // compare alphabetically
        if (english.compareTo(current.english) < 0) {
            current.left = insertRec(current.left, english, spanish);
        } else if (english.compareTo(current.english) > 0) {
            current.right = insertRec(current.left, english, spanish);
        } 
        return current;
    }

    public int height() {
        return heightRec(root);
    }

    // recursively calculate height
    public int heightRec(Node current) {
        if (current==null) {
            return 0;
        }
        int leftHeight = heightRec(current.left);
        int rightHeight = heightRec(current.right);
        return Math.max(leftHeight, rightHeight) + 1;
    }

    // method to translate
    public String translate (String word) {
        Node current = root;

        while(current.english != word) {
            steps++;
            if (word.equalsTo(current.english)) {
                return current.spanish;
            } else if (word.compareTo(current.english) < 0) {
                current = current.left;
            } else if (word.compareTo(current.english) > 0) {
                current = current.right;
            }

            if (current==null) {
                return null;
            }
        }
        return current.english;
    }

    public int steps() {
        return steps;
    }
}