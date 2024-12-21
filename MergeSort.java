// CS211 LAB 3
// Merge Sort

import java.util.*;

public class MergeSort {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the first word: ");
        String word1 = in.next().toLowerCase();
        System.out.println("Enter the second word: ");
        String word2 = in.next().toLowerCase();
        in.close();
        
        mergeSort(word1, word2);
    }

    public static void mergeSort(String word1, String word2) {
        // char array from both the input strings
        char[] mergedArray = new char[word1.length() + word2.length()]; // array size is length of both words
        int i = 0, j = 0, k = 0;

        // runs through characters till the same index
        while (i < word1.length() && j < word2.length()) {
            // checks for alphabetical order
            // if char at word1 is smaller than that of word2, add to mergedArray
            if (word1.charAt(i) <= word2.charAt(j)) {
                mergedArray[k++] = word1.charAt(i++);
              // else, if it's larger, add char from word2 to mergedArray instead
            } else {
                mergedArray[k++] = word2.charAt(j++);
            }
        }

        // to account for the rest of word1 (if word2 is shorter than word1)
        while (i < word1.length()) {
            mergedArray[k++] = word1.charAt(i++);
        }

        // to account for the rest of word1 (if word1 is shorter than word2)
        while (j < word2.length()) {
            mergedArray[k++] = word2.charAt(j++);
        }

        // print out result (char array after merge sort)
        for (char merge : mergedArray) {
            System.out.print(merge + "");
        }
    }
}