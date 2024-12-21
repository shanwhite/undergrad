//
// Created by Shannen White on 7/11/24.
//

#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"

// test case for initialising matrix
void Test_Case_1_Constructor() {
    cout << "Test_Case_1_Constructor" << endl;

    // initialise a matrix of size 3x3
    Matrix mat(3,3);

    // print out each element of matrix
    for (unsigned int i=0; i<3; i++) {      // loop through each row
        for (unsigned int j=0; j<3; j++) {  // (nested) loop through each col
            cout << mat.get(i,j) << " ";    // print out element at (i,j)
        }
        cout << endl;                       // move onto next line after each row
    }
    cout << "*************************" << endl;
}

// test case for copying matrix
void Test_Case_2_Copy() {
    cout << "Test_Case_2_Copy" << endl;

    // initialise original matrix
    Matrix mat(3,3);
    // set values for each element of mat
    mat.set(0,0,1);
    mat.set(0,1,4);
    mat.set(0,2,3);
    mat.set(1,0,7);
    mat.set(1,1,2);
    mat.set(1,2,9);
    mat.set(2,0,1);
    mat.set(2,1,8);
    mat.set(2,2,3);

    // assign elements from mat to copy of mat
    Matrix new_mat = mat;

    // print out each element of original matrix
    cout << "matrix:" << endl;
    for (unsigned int i=0; i<3; i++) {          // loop through each row
        for (unsigned int j=0; j<3; j++) {      // (nested) loop through each col
            cout << mat.get(i,j) << " ";        // print out element at (i,j)
        }
        cout << endl;                           // move onto next line after each row
    }

    // print out each element of new matrix
    cout << "copy of matrix:" << endl;
    for (unsigned int i=0; i<3; i++) {          // loop through each row
        for (unsigned int j=0; j<3; j++) {      // (nested) loop through each col
            cout << new_mat.get(i,j) << " ";    // print out element at (i,j)
        }
        cout << endl;                           // move onto next line after each row
    }

    cout << "*************************" << endl;
}

// test case for initialising current matrix using 2d array
void Test_Case_3_Array() {
    cout << "Test_Case_3_Array" << endl;

    // initialise 2d array with 3 rows & 3 cols
    // dynamic allocate memory
    int** array = new int*[3];          // allocate memory in each row
    for (unsigned int i=0; i<3; i++) {  // loop through each row
        array[i] = new int[3];          // allocate memory for each col in each row
    }

    // assign values to each element of the 2D array
    // reused values from Test_Case_2_Copy
    array[0][0] = 1;
    array[0][1] = 4;
    array[0][2] = 3;
    array[1][0] = 7;
    array[1][1] = 2;
    array[1][2] = 9;
    array[2][0] = 1;
    array[2][1] = 8;
    array[2][2] = 3;

    // initialise matrix using 2D array from above
    Matrix mat(array,3,3);

    // print out matrix (expected to have same values as 2D array
    for (unsigned int i=0; i<3; i++) {      // loop through each row
        for (unsigned int j=0; j<3; j++) {  // (nested) loop through each col
            cout << mat.get(i,j) << " ";    // print out element at (i,j)
        }
        cout << endl;                       // move onto next line after each row
    }
    ~Matrix(mat);                           // deallocate memory to prevent memory leak

    cout << "*************************" << endl;
}

// test case for returning number of rows in matrix
void Test_Case_4_Rows() {
    cout << "Test_Case_4_Rows" << endl;

    // initialise matrix of size 3x4
    Matrix mat(3,4);

    // output num of rows matrix has
    cout << "For a matrix of size 3x4," << endl;
    cout << "Number of rows: " << mat.rows() << endl;

    cout << "*************************" << endl;
}

// test case for returning number of columns in matrix
void Test_Case_5_Columns() {
    cout << "Test_Case_5_Columns" << endl;

    // initialise matrix of size 3x4
    Matrix mat(3,4);

    // output num of columns matrix has
    cout << "For a matrix of size 3x4," << endl;
    cout << "Number of columns: " << mat.columns() << endl;

    cout << "*************************" << endl;
}

// test case for returning element at row i & col j
void Test_Case_6_Get() {
    cout << "Test_Case_6_Get" << endl;

    // initialise matrix of size 3x3
    Matrix mat(3,3);
    // set some elements
    mat.set(0,0,5);
    mat.set(1,0,2);
    mat.set(2,2,7);

    // print out matrix
    for (unsigned int i=0; i<3; i++) {          // loop through each row
        for (unsigned int j=0; j<3; j++) {      // (nested) loop through each col
            cout << mat.get(i,j) << " ";        // print out element at (i,j)
        }
        cout << endl;                           // move onto next line after each row
    }

    // output value of chosen elements
    cout << "Element at (0,0) is " << mat.get(0,0) << "." << endl;
    cout << "Element at (1,0) is " << mat.get(1,0) << "." << endl;
    cout << "Element at (2,2) is " << mat.get(2,2) << "." << endl;

    cout << "*************************" << endl;
}

// test case for updating value at row i & col j
void Test_Case_7_Set() {
    cout << "Test_Case_7_Set" << endl;

    // initialise matrix of size 3x3
    Matrix mat(3,3);
    // print out matrix
    for (unsigned int i=0; i<3; i++) {          // loop through each row
        for (unsigned int j=0; j<3; j++) {      // (nested) loop through each col
            cout << mat.get(i,j) << " ";        // print out element at (i,j)
        }
        cout << endl;                           // move onto next line after each row
    }
    // output initial value of element at (0,1) and (2,2)
    cout << "Element at (0,1) is " << mat.get(0,1) << "." << endl;
    cout << "Element at (2,2) is " << mat.get(2,2) << "." << endl;

    // update value of element at (0,1) to be 25
    // and value of element at (2,2) to be 40
    mat.set(0, 1, 2);
    mat.set(2,2, 4);
    // print out matrix
    cout << "After updating," << endl;
    for (unsigned int i=0; i<3; i++) {          // loop through each row
        for (unsigned int j=0; j<3; j++) {      // (nested) loop through each col
            cout << mat.get(i,j) << " ";        // print out element at (i,j)
        }
        cout << endl;                           // move onto next line after each row
    }
    // output updated value of element at (0,1) and (2,2)
    cout << "Element at (0,1) is " << mat.get(0,1) << "." << endl;
    cout << "Element at (2,2) is " << mat.get(2,2) << "." << endl;

    cout << "*************************" << endl;
}

// test case for matrix operation +
void Test_Case_8_Plus() {
    cout << "Test_Case_8_Plus" << endl;

    // initialise two matrices
    Matrix mat1(2,2);
    Matrix mat2(2,2);

    // set values for both matrices
    // first matrix
    mat1.set(0,0,2);
    mat1.set(0,1,4);
    mat1.set(1,0,1);
    mat1.set(1,1,7);
    // second matrix
    mat2.set(0,0,1);
    mat2.set(0,1,9);
    mat2.set(1,0,3);
    mat2.set(1,1,1);

    // print out matrices to be added
    cout << "mat1:" << endl;
    for (unsigned int i=0; i<2; i++) {      // loop through each row
        for (unsigned int j=0; j<2; j++) {  // (nested) loop through each col
            cout << mat1.get(i,j) << " ";   // print out element at (i,j)
        }
        cout << endl;                       // move onto next line after each row
    }
    cout << "mat2:" << endl;
    for (unsigned int i=0; i<2; i++) {      // loop through each row
        for (unsigned int j=0; j<2; j++) {  // (nested) loop through each col
            cout << mat2.get(i,j) << " ";   // print out element at (i,j)
        }
        cout << endl;                       // move onto next line after each row
    }

    // add the two matrices together (using + operator)
    Matrix add_mat = mat1 + mat2;

    // print out each element of new matrix
    cout << "mat1+mat2:" << endl;
    for (unsigned int i=0; i<2; i++) {          // loop through each row
        for (unsigned int j=0; j<2; j++) {      // (nested) loop through each col
            cout << add_mat.get(i,j) << " ";    // print out element at (i,j)
        }
        cout << endl;                           // move onto next line after each row
    }

    cout << "*************************" << endl;
}

// test case for matrix operation -
void Test_Case_9_Minus() {
    cout << "Test_Case_9_Minus" << endl;

    // initialise two matrices
    Matrix mat1(2,2);
    Matrix mat2(2,2);

    // set values for both matrices (same values as Test_Case_8_Plus)
    // first matrix
    mat1.set(0,0,2);
    mat1.set(0,1,4);
    mat1.set(1,0,1);
    mat1.set(1,1,7);
    // second matrix
    mat2.set(0,0,1);
    mat2.set(0,1,9);
    mat2.set(1,0,3);
    mat2.set(1,1,1);

    // print out matrices to be subtracted
    cout << "mat1:" << endl;
    for (unsigned int i=0; i<2; i++) {      // loop through each row
        for (unsigned int j=0; j<2; j++) {  // (nested) loop through each col
            cout << mat1.get(i,j) << " ";   // print out element at (i,j)
        }
        cout << endl;                       // move onto next line after each row
    }
    cout << "mat2:" << endl;
    for (unsigned int i=0; i<2; i++) {      // loop through each row
        for (unsigned int j=0; j<2; j++) {  // (nested) loop through each col
            cout << mat2.get(i,j) << " ";   // print out element at (i,j)
        }
        cout << endl;                       // move onto next line after each row
    }

    // subtract the two matrices together (using - operator)
    Matrix sub_mat = mat1 - mat2;

    // print out each element of new matrix
    cout << "mat1-mat2:" << endl;
    for (unsigned int i=0; i<2; i++) {          // loop through each row
        for (unsigned int j=0; j<2; j++) {      // (nested) loop through each col
            cout << sub_mat.get(i,j) << " ";    // print out element at (i,j)
        }
        cout << endl;                           // move onto next line after each row
    }

    cout << "*************************" << endl;
}

// test case for matrix operation *
void Test_Case_10_Multiply() {
    cout << "Test_Case_10_Multiply" << endl;

    // initialise two matrices
    Matrix mat1(2,2);
    Matrix mat2(2,2);

    // set values for both matrices (same values as Test_Case_8_Plus, Test_Case_9_Minus)
    // first matrix
    mat1.set(0,0,2);
    mat1.set(0,1,4);
    mat1.set(1,0,1);
    mat1.set(1,1,7);
    // second matrix
    mat2.set(0,0,1);
    mat2.set(0,1,9);
    mat2.set(1,0,3);
    mat2.set(1,1,1);

    // print out matrices to be subtracted
    cout << "mat1:" << endl;
    for (unsigned int i=0; i<2; i++) {      // loop through each row
        for (unsigned int j=0; j<2; j++) {  // (nested) loop through each col
            cout << mat1.get(i,j) << " ";   // print out element at (i,j)
        }
        cout << endl;                       // move onto next line after each row
    }
    cout << "mat2:" << endl;
    for (unsigned int i=0; i<2; i++) {      // loop through each row
        for (unsigned int j=0; j<2; j++) {  // (nested) loop through each col
            cout << mat2.get(i,j) << " ";   // print out element at (i,j)
        }
        cout << endl;                       // move onto next line after each row
    }

    // multiply the two matrices together
    Matrix multiply_mat = mat1 * mat2;

    // print out each element of new matrix
    cout << "mat1*mat2:" << endl;
    for (unsigned int i=0; i<2; i++) {          // loop through each row
        for (unsigned int j=0; j<2; j++) {      // (nested) loop through each col
            cout << multiply_mat.get(i,j) << " ";    // print out element at (i,j)
        }
        cout << endl;                           // move onto next line after each row
    }

    cout << "*************************" << endl;
}

// test case for transposing matrix
void Test_Case_11_Transpose() {
    cout << "Test_Case_11_Transpose" << endl;

    // initialise matrix of size 2x3
    // chose different m & n so it's easier to see the transposing
    Matrix mat(2,3);
    // set values for each element of mat
    mat.set(0,0,2);
    mat.set(0,1,9);
    mat.set(0,2,8);
    mat.set(1,0,1);
    mat.set(1,1,4);
    mat.set(1,2,2);

    // print out each element of new matrix
    cout << "mat:" << endl;
    for (unsigned int i=0; i<2; i++) {          // loop through each row
        for (unsigned int j=0; j<3; j++) {      // (nested) loop through each col
            cout << mat.get(i,j) << " ";    // print out element at (i,j)
        }
        cout << endl;                           // move onto next line after each row
    }

    // transpose the matrix using ~ operator
    Matrix trans_mat = ~mat;

    // print out each element of new matrix
    cout << "~mat:" << endl;
    for (unsigned int i=0; i<3; i++) {          // loop through each row
        for (unsigned int j=0; j<2; j++) {      // (nested) loop through each col
            cout << trans_mat.get(i,j) << " ";    // print out element at (i,j)
        }
        cout << endl;                           // move onto next line after each row
    }

    cout << "*************************" << endl;
}

// test case for checking if two matrices are the same
void Test_Case_12_Equal() {
    cout << "Test_Case_12_Equal" << endl;

    // initialise three matrices
    Matrix mat1(2,2);
    Matrix mat2(2,2);
    Matrix mat3(2,2);

    // set values for all matrices
    // (same values as Test_Case_8_Plus, Test_Case_9_Minus, Test_Case_10_Multiply)
    // first matrix
    mat1.set(0,0,2);
    mat1.set(0,1,4);
    mat1.set(1,0,1);
    mat1.set(1,1,7);
    // second matrix
    mat2.set(0,0,1);
    mat2.set(0,1,9);
    mat2.set(1,0,3);
    mat2.set(1,1,1);
    // third matrix
    mat3.set(0,0,2);
    mat3.set(0,1,4);
    mat3.set(1,0,1);
    mat3.set(1,1,7);

    // print out mat1 and mat2
    cout << "mat1:" << endl;
    for (unsigned int i=0; i<2; i++) {      // loop through each row
        for (unsigned int j=0; j<2; j++) {  // (nested) loop through each col
            cout << mat1.get(i,j) << " ";   // print out element at (i,j)
        }
        cout << endl;                       // move onto next line after each row
    }
    cout << "mat2:" << endl;
    for (unsigned int i=0; i<2; i++) {      // loop through each row
        for (unsigned int j=0; j<2; j++) {  // (nested) loop through each col
            cout << mat2.get(i,j) << " ";   // print out element at (i,j)
        }
        cout << endl;                       // move onto next line after each row
    }

    // check mat1 and mat2
    if (mat1 == mat2) {
        cout << "mat1 is EQUAL to mat2." << endl;
    } else {
        cout << "mat1 is NOT EQUAL to mat2." << endl;    // expected output
    }

    cout << "**********" << endl;

    // print out mat1 and mat3
    cout << "mat1:" << endl;
    for (unsigned int i=0; i<2; i++) {      // loop through each row
        for (unsigned int j=0; j<2; j++) {  // (nested) loop through each col
            cout << mat1.get(i,j) << " ";   // print out element at (i,j)
        }
        cout << endl;                       // move onto next line after each row
    }
    cout << "mat3:" << endl;
    for (unsigned int i=0; i<2; i++) {      // loop through each row
        for (unsigned int j=0; j<2; j++) {  // (nested) loop through each col
            cout << mat3.get(i,j) << " ";   // print out element at (i,j)
        }
        cout << endl;                       // move onto next line after each row
    }

    // check mat1 and mat3
    if (mat1 == mat3) {
        cout << "mat1 is EQUAL to mat3." << endl;        // expected output
    } else {
        cout << "mat1 is NOT EQUAL to mat3." << endl;
    }

    cout << "*************************" << endl;
}

// test case for spring representation of matrix
void Test_Case_13_String() {
    cout << "Test_Case_13_String" << endl;

    // initialise matrix mat (original matrix)
    Matrix mat(3,3);
    // set values to mat
    mat.set(0,0,5);
    mat.set(0,1,8);
    mat.set(0,2,2);
    mat.set(1,0,1);
    mat.set(1,1,4);
    mat.set(1,2,9);
    mat.set(2,0,7);
    mat.set(2,1,3);
    mat.set(2,2,7);

    // output matrix in original form
    cout << "matrix:" << endl;
    for (unsigned int i=0; i<3; i++) {          // loop through each row
        for (unsigned int j=0; j<3; j++) {      // (nested) loop through each col
            cout << mat.get(i,j) << " ";        // print out element at (i,j)
        }
        cout << endl;                           // move onto next line after each row
    }

    // output string representation of matrix
    cout << "string rep:" << endl;
    cout << mat.toStr() << endl;

    cout << "*************************" << endl;
}

int main() {
    Test_Case_1_Constructor();  // test case for initialising matrix
    Test_Case_2_Copy();         // test case for copying matrix
    Test_Case_3_Array();        // test case for initialising current matrix using 2d array
    Test_Case_4_Rows();         // test case for returning number of rows in matrix
    Test_Case_5_Columns();      // test case for returning number of columns in matrix
    Test_Case_6_Get();          // test case for returning element at row i & col j
    Test_Case_7_Set();          // test case for updating value at row i & col j
    Test_Case_8_Plus();         // test case for matrix operation +
    Test_Case_9_Minus();        // test case for matrix operation -
    Test_Case_10_Multiply();    // test case for matrix operation *
    Test_Case_11_Transpose();   // test case for transposing matrix
    Test_Case_12_Equal();       // test case for checking if two matrices are the same
    Test_Case_13_String();      // test case for spring representation of matrix
    return 0;
}