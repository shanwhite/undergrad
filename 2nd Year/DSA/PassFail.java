// CS211 LAB 2
// Recursion (Check if a student should pass the course)

import java.util.*;

public class PassFail {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Student's Track Record: ");
        String record = sc.next().toUpperCase();
        sc.close();

        System.out.println((checkRecord(record) ? "PASS" : "FAIL"));
    }

    // A student passes the course if they
    // missed fewer than 2 labs (i.e. only missed 0 or 1)
    // never late for 3 consecutive labs

    // RECURSIVE METHOD
    public static boolean checkRecord(String record) {

        if (record.isEmpty()) {
            return true;
        }

        // if student is late for at least 3 labs in a row, or has more than 1 absence, they fail
        if ((record.length()>=3 && record.substring(0,3).equals("LLL")) || countAbsence(record) > 1) {
            return false;
        }

        // remove the first letter and check the rest of the record string
        return checkRecord(record.substring(1));
    }

    public static int countAbsence(String record) {

        // blank string means zero absences / no A
        if (record.isEmpty()) {
            return 0;
        }

        // check if character at start of the string is A (Absence)
        if ((record.charAt(0) == 'A')) {
            // recursion for the rest of the string (remove first char) and add 1 to absence count
            return countAbsence(record.substring(1)) + 1;  
        }

        // recursion for the rest of the string (remove first char)
        return countAbsence(record.substring(1));
    }

    // NON-RECURSIVE METHOD
    /* public static boolean checkRecord(String record) {
        int absences = 0;
        int consecutiveLate = 0;

        for (int i = 0; i < record.length(); i++) {
            char letter = record.charAt(i);
            if (letter == 'A') {
                absences++;
                consecutiveLate = 0;
            } else if (letter == 'L') {
                consecutiveLate++;
            } else {
                consecutiveLate = 0;
            }

            if (absences > 1 || consecutiveLate >= 3) {
                return false;
            }
        }
        return true;
    } */
}