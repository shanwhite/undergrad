package Others;
import java.util.Scanner;

public class CS210Lab3 {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        System.out.println("Enter the lower limit of the range: ");
        int lower = in.nextInt();
        System.out.println("Enter the upper limit of the range: ");
        int upper = in.nextInt();

        int count=0;
        long start = System.nanoTime();

        for (int num=lower; num<=upper; num++) {
            if (isPrime(num)) {
                //System.out.println("number:" +num);
                count++;
            }
        }
        System.out.println("Number of prime numbers in the range: " +count);

        long end = System.nanoTime();
    
        System.out.println("Time taken: " +(end-start));    // (end-start) is running duration (in nanoseconds)

    }

    public static boolean isPrime(int n) {

        if (n==0||n==1) {
            return false;
        } 

        else {
            for (int i=2; i<=Math.sqrt(n); i++) {
                if(n%i==0) {
                    return false;
                }
            }
            return true;
        }

    }

}
