package Others;
import java.util.Scanner;

public class CS210Lab2 {
	public static void main(String[] args) {

		// takes user input for credit card number
		Scanner in = new Scanner(System.in);
		String cardnum = in.nextLine();
		in.close();

		// if isValid is true, print valid, else print invalid
		if(isValid(cardnum)) {
			System.out.println("VALID");
		} else {
			System.out.println("INVALID");
		}
	}

	// method to check if credit card number is valid by taking the total sum of both sums
	public static boolean isValid(String cardnum) {

		// converting input string into integer array
		int[] cardnumArr = new int[cardnum.length()];
		
		for (int i=0; i<cardnum.length(); i++) {
			cardnumArr[i] = Integer.parseInt(cardnum.substring(i,i+1)); // substring of each digit from the string and puts it into the array
		}

		// goes through the credit card number from back to front
		// array length starts from len-1 bc first digit is arr[0]
		for (int i=cardnumArr.length-1; i>=0; i--) {

			// for even numbers, checks if result of doubling operation is bigger than 9
			// if yes, add digits of result together or subtract 9 from result
			if (i%2==0) {						// for every even digit in the credit card number
				int num = cardnumArr[i];		// temporarily stores num in array
				num=num*2;						// doubling operation
				if(num>9) {
					num=num-9;					// subtract 9 from result if greater than 9 
				}
				cardnumArr[i] = num;			// stores final num in array
			}
		}

		int total=0;
		for (int i=0; i<cardnumArr.length; i++) {
			total += cardnumArr[i];
		}

		// credit card number is valid if the total is a multiple of 10
		if(total%10==0) {
			return true;
		} else {
			return false;
		}

	}
}