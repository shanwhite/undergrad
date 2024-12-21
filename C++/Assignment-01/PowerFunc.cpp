//
//  PowerFunc.cpp
//  CS264Assignment1
//
//  Created by Shannen White on 27/9/24.
//

#include <iostream>
using namespace std;

// 4.4 POWER FUNCTION
int main() {

    int num, power, result=1;   // initialise number, power and result variables
    cout << "Enter number: ";
    cin >> num;                 // set input number
    cout << "Enter power: ";
    cin >> power;               // set power

    // loop until power reaches 0
    while (power>0) {
        // if power is an odd number
        if (power & 1) {        // power&1 (bitwise operations) is the same as power%2
                                // returns 1 or 0 depending if odd or even num respectively
                                // if odd num, will return 1 which means true so the if condition is fulfilled
            result *= num;      // multiply result by the number once
        }

        // power is now an even number
        power >>= 1;            // shift power by 1 bit to the right (i.e. power /= 2)
        num *= num;             // square the num to prepare for next iteration
    }

    cout << result << endl;     // print out result
    return 0;
}

// The time complexity here is O(logn) because:
// the power decreases exponentially as it is halved (power>>=1 which is essentially power/=2) during each iteration
// this suggests that in each iteration, the initial value of power is n, then n/2, n/4 etc., until power is 0
// the number of times that n can be halved is proportional to log (n) with base 2
// (^ not sure how to type it in CLion but log2(n))
// therefore, the number of iterations and hence time complexity is Olog(n)