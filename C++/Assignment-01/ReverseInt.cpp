//
//  ReverseInt.cpp
//  CS264Assignment1
//
//  Created by Shannen White on 27/9/24.
//

#include <iostream>
using namespace std;

// 4.1 REVERSE AN INTEGER
int main() {

    cout << "Enter an integer: " << endl;       // ask for user input
    int num;                                    // declaring int variable
    cin >> num;                                 // takes user input as num (integer)

    int reversed=0;                             // initialise reversed
    while (num!=0) {                            // while num is not 0 (i.e. num<0 or num>0)
        reversed = reversed*10 + num%10;        // modulus (remainder after dividing by 10) of input number to obtain last digit
                                                // reversed*10 to add 0 behind the "last digit" added to reversed num
        num = num/10;                           // divide by 10 to remove last number & continue the loop
    }

    cout << "Reversed integer: \n" << reversed << endl;     // print out reversed integer
    return 0;
}

// how the reversing works is as follows:
// for e.g. the input num is 123

// while num is not 0, the new reversed number is multiplied by 10 (e.g. 0*10=0 at the start)
// then takes the last digit of input num (e.g. 3) and adds it to the reversed variable 3
// the input num is divided by 10 to get rid of the last digit
// loop through all digits of the number
// 2nd time it's looped, reversed*10 to make a new slot for the incoming digit (e.g. 3*10=30)
// 0 will be replaced by new digit, which is now 12%10 aka 2, hence reserved is now 32
// keep looping until num reaches 0