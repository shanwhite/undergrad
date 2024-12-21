//
// Created by Shannen White on 7/11/24.
//

#ifndef MATRIX_H
#define MATRIX_H

#include <string>   // for part 13 (std::string)

class Matrix {

private:
    unsigned int m; // number of rows
    unsigned int n; // number of columns
    int** data;     // pointer to 2D matrix data

public:
    // 1. constructor
    Matrix(unsigned int m, unsigned int n);
    // 2. copy constructor
    Matrix(const Matrix &mat);
    // 3. constructor to initialise current matrix using a 2D array of size mxn
    Matrix(int** array, unsigned int m, unsigned int n);
    // destructor to safely free/deallocate dynamically allocated memory
    ~Matrix();
    // 4. function that returns num of rows in matrix
    unsigned int rows() const;
    // 5. function that returns num of cols in matrix
    unsigned int columns() const;
    // 6. function that returns element at row i, col j
    int get(unsigned int i, unsigned int j) const;
    // 7. function that updates value at row i, col j
    void set(unsigned int i, unsigned int j, int value);
    // 8. function that returns a matrix that contains the results of addition of two matrices
    Matrix operator+(const Matrix &mat);
    // 9. function that returns a matrix that contains the results of subtraction of two matrices
    Matrix operator-(const Matrix &mat);
    // 10. function that returns a matrix that contains the results of multiplication of two matrices
    Matrix operator*(const Matrix &mat);
    // 11. function that returns a transpose of current matrix
    Matrix operator~() const;
    // 12. function that checks if two matrices are the same
    bool operator==(const Matrix &mat);
    // 13. function that returns a string representation of the matrix (i.e. shows every element in the matrix)
    std::string toStr();
};

#endif