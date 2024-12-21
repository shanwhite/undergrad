// CS211 LAB 2
// Recursion (Loan)

import java.util.*;

public class Loan {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Loan to be paid off: ");
        double loan = sc.nextDouble();
        System.out.println("Annual interest rate (in %): ");
        double annualInterest = sc.nextDouble();
        System.out.println("Monthly loan repayment: ");
        double monthlyRepayment = sc.nextDouble();
        sc.close();

        int result = monthsRequired(loan, annualInterest, monthlyRepayment);
        System.out.println("It will take " + result + " months to pay off the loan.");
    }

    public static int monthsRequired(double loan, double annualInterest, double monthlyRepayment) {
        // base case: loan fully paid off
        if (loan <= 0) {
            return 0;
        }

        double monthlyInterest = (annualInterest / 12 / 100) * loan;

        double remainingLoan = loan - monthlyRepayment + monthlyInterest;

        return monthsRequired(remainingLoan, annualInterest, monthlyRepayment) + 1;
    }
}