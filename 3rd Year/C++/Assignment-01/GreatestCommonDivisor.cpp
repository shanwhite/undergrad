//
//  GreatestCommonDivisor.cpp
//  CS264Assignment1
//
//  Created by Shannen White on 27/9/24.
//

#include <iostream>
using namespace std;

// 4.2 GREATEST COMMON DIVISOR
int main() {

    int x, y;                               // initialise variables for the two integers
    int gcd = 1;                            // & greatest common divisor
    cout << "First integer: ";
    cin >> x;                               // set user input as first integer (x)
    cout << "Second integer: ";
    cin >> y;                               // set user input as second integer (y)

    // i must start from 1, since dividing by 0 will give a zero error
    for(int i=1; i<=x && i<=y; i++) {       // gcd must be smaller than or equal to both integers
        if(x%i==0 && y%i==0) {              // if both x and y are divisible by the current number (i)
            gcd = i;                        // set gcd as i
        }
    }                                       // will loop until the biggest possible value of i is found

    // print out gcd of x and y
    cout << "The Greatest Common Divisor of " << x << " and " << y << " is " << gcd << endl;
    return 0;
}
