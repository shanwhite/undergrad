// CS211 LAB 6
// Collatz Conjecture

import java.util.*;

public class CollatzConjecture {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the starting number: ");
        long num = in.nextInt();
        in.close();

        System.out.println("Number of steps required for " + num + " is " + countSteps(num));

        System.out.println();       // print break line, just separating the two parts of the question
    
        searchForGroup(num);           // implement method for finding largest group of consecutive numbers
    }

    public static int countSteps(long num) {
        int steps = 0;
        while (num!=1) {
            if (num%2==0) {             // if num is even
                num = num/2;            // multiply by 3 and +1
            } else {                    // if it's not even
                num = (num*3)+1;        // half it
            }
            steps++;
        } 
        return steps;
    }

    public static void searchForGroup(long num) {
        
        long start = 0;          // starting number of the group
        int maxGroupSize = 0;   // for comparison later on
        int steps = 0;

        // started from 103 bc example was 98-102 so i just skipped everything before that
        // i think 50 mil is the biggest limit it can take
        // anything bigger i probably need to change this from long to big integer???
        for (long i=103; i<=50000000; i++) {
            steps = countSteps(i);
            int groupSize = 1;      // size of the group of consecutive numbers
            
            for (long j=i+1; j<=50000000; j++) {
                if (countSteps(j)==steps) {     // check for the number after i, if it's the same step as the previous num
                    groupSize++;                // add 1 to group size
                } else {
                    break;                // reset group size       
                }
            }

            if (groupSize > maxGroupSize) {
                maxGroupSize = groupSize;
                start = i;                      // set i as the start num of group
            }
        }

        steps = countSteps(start);          // calculate steps of the num
        long lastNum = start+maxGroupSize-1;

        System.out.println("First number: " + start);
        System.out.println("Last number: " + lastNum);
        System.out.println("Size of group: " + maxGroupSize);              // later need to count what's the last number of the group
        System.out.println("Step count: " + steps);

        // for checking if same step count
        // for (long i=start; i<start+maxGroupSize; i++) {
        //     System.out.println("Number of steps required for " + i + " is " + countSteps(i));
        // }
    }
}