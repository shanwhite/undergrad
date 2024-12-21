//
//  Palindrome.cpp
//  CS264Assignment1
//
//  Created by Shannen White on 27/9/24.
//

#include <iostream>
using namespace std;

// 4.3 PALINDROME
int main() {

    // reused my own code from 4.1 reversed int, refer to comments there for further understanding
    cout << "Enter an integer: " << endl;       // ask for user input
    int num;                                    // declaring int variable
    cin >> num;                                 // takes user input as num (integer)

    int n = num;                                // store input number for later

    int reversed=0;                             // initialise reversed
    while (num!=0) {                            // while num is not 0 (i.e. num<0 or num>0)
        reversed = reversed*10 + num%10;        // modulus (remainder after dividing by 10) of input number to obtain last digit
                                                // reversed*10 to add 0 behind the "last digit" added to reversed num
        num = num/10;                           // divide by 10 to remove last number & continue the loop
    }

    // to check if palindrome
    if (reversed == n && n > 0) {               // if the reversed num is same as input num
                                                // and n>0 since negative nums aren't palindromes
        cout << "true" << endl;                 // print true
    } else {                                    // if num is not a palindrome
        cout << "false" << endl;                // print false
    }

    return 0;
}