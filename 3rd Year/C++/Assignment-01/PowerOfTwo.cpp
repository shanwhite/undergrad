//
//  PowerOfTwo.cpp
//  CS264Assignment1
//
//  Created by Shannen White on 27/9/24.
//

#include <iostream>
using namespace std;

// 4.5 POWER OF TWO

int main() {

    int num;                        // initialise num variable
    cout << "Enter number: ";       // ask for user input
    cin >> num;                     // store input as num

    if (num>0) {
        // keep dividing the number by 2 using bitwise shift, while it is even
        while (!(num&1)) {          // num&1 is the same as num%2
                                    // if num is even, num&1 will result in 0 (false)
                                    // therefore, while(!even), i.e. while true for an even num
            num = num>>1;           // shift num by 1 bit to the right (i.e. num/=2)
        }

        if (num==1) {               // if num results in 1 (after dividing all the way from input num to 1)
            cout << "true" << endl; // print true (is a power of two)
        }
    }

    // 0 cannot be a power of two bc the smallest value will be 2^0 which equals to 1
    if (num==0 || num!=1) {         // if the resulting number after going through the loop is not equal to 1
                                    // this means the number is not a power of two
        cout << "false" << endl;    // print false (not a power of two)
    }

    return 0;                       // end program
}

