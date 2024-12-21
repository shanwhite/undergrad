package Others;
import java.util.Scanner;

public class CS210Lab3Sieve {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        System.out.println("Enter the lower limit of the range: ");
        int lower = in.nextInt();
        System.out.println("Enter the upper limit of the range: ");
        int upper = in.nextInt();

        long start = System.nanoTime();

        boolean[] prime = new boolean[upper];
     
        for (int i=0; i<prime.length; i++) {
            prime[i] = true;
        }

        for (int i=2; i<Math.sqrt(upper); i++) {
            if(prime[i]==true) {
                for(int j = (i*i); j<upper; j = j+i) {
                prime[j] = false;
                }
            }
        }

        int count=0;
        for (int i=2; i<prime.length; i++) {
            if(prime[i]==true) {
                //System.out.println(i);
                count++;
            }
        }

        System.out.println("Number of primes: " +count);

        long end = System.nanoTime();
    
        System.out.println("Time taken: " +(end-start));    // (end-start) is running duration (in nanoseconds)
    }
}

