/*
 * matrix.h
 *
 *  Created on: Nov 10, 2017
 *      Author: ppushkinp
 */

#ifndef MATRIX_H_
#define MATRIX_H_

class Matrix
{
public:

    // Creates an empty matrix of size 0 times 0.
    Matrix();

    // Creates an identity matrix of size <size> times <size>.
    Matrix(int size);

    // Creates a matrix of size <height> times <width> filled with 0s.
    Matrix(int row, int col);

    // Copy constructor
    Matrix(const Matrix&);

    // Move constructor
    Matrix(Matrix&&);

    // Destructor
    ~Matrix();

    int getWidth() const;
    int getHeight() const;

    void resize(int row, int col);
    void transpose();


    // Copy assignment
    Matrix& operator= (const Matrix&);

    // Move assignment
    Matrix& operator= (Matrix&&);


    // Returns the value at the specified position in the matrix.
    double& operator()(const int row, const int col);
    double operator()(const int row, const int col) const;


    // Creates a new matrix which is the sum of this and another given matrix.
    Matrix operator+(const Matrix&) const;

    // Adds a given matrix to the current.
    Matrix& operator+=(const Matrix&);


    // Creates a new matrix which is the product of this and another given matrix.
    Matrix operator*(const Matrix&) const;

    // Multiplies a given matrix with the current.
    Matrix& operator*=(const Matrix&);


    // Creates a new matrix which is the product of this and given number.
    Matrix operator*(double) const;

    // Mutliplies the current matrix with a given number.
    Matrix& operator*=(double);


    // Determines if two matrices are equal.
    bool operator==(const Matrix&) const;

//add for test
    void set_values(double val[], int nRow, int nCol);
    double** get_values(){return values;}
private:
    int width;
    int height;

    double** values;

    //create values
    void create_vlaues(int row, int col);

    //delete values;
    void delete_values();

    //compare if two double numbers is equal
    bool is_equal(double a, double b) const;
};




#endif /* MATRIX_H_ */
