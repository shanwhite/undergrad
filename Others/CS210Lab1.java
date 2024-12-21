package Others;
import java.util.Scanner;

public class CS210Lab1 {
	public static void main(String[] args) {

		do {
			Scanner in = new Scanner(System.in);
			System.out.println("Choose an option:")               
			System.out.println("1. Check if a number is prime");
			System.out.println("2. List prime numbers in a range");
			System.out.println("3. Exit");
			int option = in.nextInt();

			System.out.println("Enter a number: ");
			int num = in.nextInt();

			if (option==1) {					
				if(isPrime(num)) {
					System.out.println(num + " is a prime number.");		// if isPrime is true, it is a prime number
				} else {
					System.out.println(num + " is not a prime number.");		// else if false, it's not
				}
			}

			else if (option==2) {
				System.out.println("Enter the start of the range: ");
				int start = in.nextInt();
				System.out.println("Enter the end of the range: ");
				int end = in.nextInt();

				System.out.print("Prime numbers in the range [" +start+ ", " +end+ "]: ");

				for (int i=start; i<=end; i++) {
					if (isPrime(i)) {
						System.out.println(i);
					}
				}
			}

		} while (option!=3);		// NAURRR THIS PART IS WRONG it doesn't include this in the loop
	}

	public static boolean isPrime(int num) {

		if (num==0||num==1) {		// prime number must be at least 2
			return false;
		}

		else {
			for (int i=2; i<num/2; i++) {		// only need to check till half of the number bc 2 is the smallest prime number
				if (num%i==0) {		// if the number can be divided by i, it is not a prime number 
					return false;
				}
			}
			return true;		// else return true (it's a prime number)
		}
	}

}