//
// Created by Shannen White on 7/11/24.
//

#include <iostream>
#include <sstream>  // for string rep (part 13) - convert num to str
#include "Matrix.h"

using namespace std;

/** 1
 * constructor that initialises a matrix of size mxn
 * every element in this matrix is 0
 * @param m is the number of rows
 * @param n is the number of columns
 * @return matrix of size mxn, with every element being 0
 */
Matrix::Matrix(unsigned int m, unsigned int n) {

    this->m = m;    // this-> points to the member variable m of the Matrix class
    this->n = n;    // same for this->n and n

    // dynamic memory allocation
    data = new int*[this->m];                   // allocate memory for each row
    for (unsigned int i=0; i<(this->m); i++) {  // loop through each row
        data[i] = new int[this->n]{0};          // allocate memory for each col in each row & assign 0 to each element
    }
}

/** 2
 * copy constructor that copies every element from one matrix to another
 * @param mat is the matrix to be copied
 */
Matrix::Matrix(const Matrix &mat) {

    // initialise m & n based on mat
    m = mat.m;
    n = mat.n;

    // dynamic memory allocation
    data = new int*[m];                     // allocate memory for each row
    for (unsigned int i=0; i<m; i++) {      // loop through each row
        data[i] = new int[n];               // allocate memory for each col in each row
        for (unsigned int j=0; j<n; j++) {  // (nested) loop through each col (in each row)
            data[i][j] = mat.data[i][j];    // copy data from one matrix to another
        }
    }
}

/** 3
 * initialise current matrix with a 2D array of size mxn
 * @param array is a pointer to a 2D array
 * @param m is the number of rows in the array
 * @param n is the number of columns in the array
 */
Matrix::Matrix(int** array, unsigned int m, unsigned int n) {

    this->m = m;    // this-> points to the member variable m of the Matrix class
    this->n = n;    // same for this->n and n

    // dynamic memory allocation
    data = new int*[this->m];                       // allocate memory for each row
    for (unsigned int i=0; i<(this->m); i++) {      // loop through each row
        data[i] = new int[this->n];                 // allocate memory for each col in each row
        for (unsigned int j=0; j<(this->n); j++) {  // (nested) loop through each col (in each row)
            data[i][j] = array[i][j];               // copy data from input array to matrix
        }
    }
}

/**
 * destructor: safely frees/deallocates dynamically allocated memory,
 * called immediately when a function ends
 */
Matrix::~Matrix() {
    for (unsigned int i=0; i<m; i++) {  // loop through each row
        delete[] data[i];               // deallocate memory for each row
    }
    delete[] data;                      // deallocate array of pointers,
                                        // where data was allocated using new int*[this->m]
}

/** 4
 * returns the number of rows in the matrix
 * @return m, which is the number of rows
 */
unsigned int Matrix::rows() const {
    return m;
}

/** 5
 * returns the number of columns in the matrix
 * @return n, which is the number of columns
 */
unsigned int Matrix::columns() const {
    return n;
}

/** 6
 * returns the value of element at ith row and jth column
 * @param i is the index of the row
 * @param j is the index of the column
 * @return value of element at row i and col j (i and j both start at 0)
 */
int Matrix::get(unsigned int i, unsigned int j) const {
    return data[i][j];
}

/** 7
 * updates value of element at ith row and jth column
 * @param i is the index of the row
 * @param j is the index of the column
 * @param value is the new value of the element
 * @return element at row i and col j (i and j both start at 0)
 */
void Matrix::set(unsigned int i, unsigned int j, int value) {
    data[i][j] = value; // overwrites the value of the element at row i col j with the input value
}

/** 8
 * operator that adds two matrices
 * @param mat is another matrix
 * @return matrix that contains the results of adding two matrices
 */
Matrix Matrix::operator+(const Matrix &mat) {
    // initialise a matrix of size mxn to store the result of addition
    Matrix result(m,n);

    for (unsigned int i=0; i<m; i++) {      // loop through each row
        for (unsigned int j=0; j<n; j++) {  // (nested) loop through each col
            // add respective values of elements from both matrices
            // and assign to the new matrix
            result.data[i][j] = data[i][j] + mat.data[i][j];
        }
    }
    return result;  // return the addition of both matrices
}

/** 9
 * operator that subtracts two matrices
 * @param mat is another matrix
 * @return matrix that contains the results of subtracting two matrices
 */
Matrix Matrix::operator-(const Matrix &mat) {
    // initialise a matrix of size mxn to store the result of subtraction
    Matrix result(m,n);

    for (unsigned int i=0; i<m; i++) {      // loop through each row
        for (unsigned int j=0; j<n; j++) {  // (nested) loop through each col
            // subtract value of element at respective index
            // of second matrix from that of first matrix
            // and assign to the new matrix
            result.data[i][j] = data[i][j] - mat.data[i][j];
        }
    }
    return result;  // return the subtraction of both matrices
}

/** 10
 * operator that multiplies two matrices
 * for matrix multiplication, num of cols in 1st matrix must equal num of rows in 2nd matrix
 * resulting matrix has the num of rows of 1st matrix and num of cols in 2nd matrix
 * @param mat is another matrix
 * @return matrix that contains the results of multiplying two matrices
 */
Matrix Matrix::operator*(const Matrix &mat) {
    // initialise a new matrix of size m x mat.n
    // number of rows is the same as first matrix
    // number of columns follows the second matrix (mat)
    Matrix result(m,mat.n);

    for (unsigned int i=0; i<m; i++) {          // loop through each row of 1st matrix
        for (unsigned int j=0; j<mat.n; j++) {  // loop through each col of 2nd matrix (mat)
            result.data[i][j] = 0;              // initialise each element of new matrix as 0

            for (unsigned int k=0; k<n; k++) {  // loop through each col of 1st matrix
                // multiply the values at row i of 1st matrix and col j of 2nd matrix (mat)
                // and assign to new matrix at (i,j)
                result.data[i][j] += data[i][k] * mat.data[k][j];
            }
        }
    }

    return result;  // return the multiplication of both matrices
}

/** 11
 * operator that transposes the current matrix
 * @return transpose of current matrix
 */
Matrix Matrix::operator~() const {
    // initialise a new matrix where num of rows & num of cols are swapped (mxn becomes nxm)
    // e.g. if matrix originally has 3 rows & 4 cols, transpose will have 4 rows & 3 cols
    Matrix result(n,m);

    for (unsigned int i=0; i<m; i++) {      // loop through each row of original matrix
        for (unsigned int j=0; j<n; j++) {  // (nested) loop through each col of original matrix
            result.data[j][i] = data[i][j]; // set element at (j,i) for new matrix as that at (i,j) of original matrix
        }
    }
    return result;  // return transpose of original matrix

}

/** 12
 * checks if two matrices are the same (i.e. if they both contain the same element at the same location in each matrix)
 * @param mat is another matrix
 * @return true if both same, false if different
 */
bool Matrix::operator==(const Matrix &mat) {
    // if number of rows or cols aren't the same for both matrices, return false
    if (m!=mat.m || n!=mat.n) {
        return false;
    }

    for (unsigned int i=0; i<m; i++) {          // loop through each row
        for (unsigned int j=0; j<n; j++) {      // (nested) loop through each col
            if (data[i][j] != mat.data[i][j]) { // if any of the values of the elements at the same indexes don't match
                return false;                   // return false (i.e. not equal)
            }
        }
    }

    return true;    // return true if both matrices are equal
}

/** 13
 * shows every element in the matrix in string format
 * @return string representation of matrix
 */
string Matrix::toStr() {
    std::stringstream ss;                   // initialise the string
    ss << "[";                              // starting bracket
    for (unsigned int i=0; i<m; i++) {      // loop through each row
        ss << "[";                          // to indicate start of row
        for (unsigned int j=0; j<n; j++) {  // (nested) loop through each col
            ss << data[i][j];               // add value of element at (i,j) to the string
            if (j<n-1) {                    // if not the last col
                ss << ", ";                 // add comma between elements in the same row
            }
        }
        ss << "]";                          // to indicate end of row
        if (i<m-1) {                        // if not the last row
            ss << ", ";                     // add comma between each row
        }
    }
    ss << "]";                              // ending bracket
    return ss.str();                        // return the string
}