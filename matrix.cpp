
#include "matrix.h"
#include <assert.h>
#include <algorithm>

using namespace std;

// Creates an empty matrix of size 0 times 0.
Matrix::Matrix()
{
    create_vlaues(0, 0);
}

// Creates an identity matrix of size <size> times <size>.
Matrix::Matrix(int size)
{
    //create component of matrix
    create_vlaues(size, size);
    //set diagonal components to 1
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            if (i == j)
                values[i][j] = 1;
            else
                values[i][j] = 0;
        }
}

// Creates a matrix of size <height> times <width> filled with 0s.
Matrix::Matrix(int row, int col)
{
    create_vlaues(row, col);
    //set all the components to 0
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            values[i][j] = 0;
}

// Copy constructor
Matrix::Matrix(const Matrix& src)
{
    //create values
    create_vlaues(src.height, src.width);
    //substitute components of src matrix into current matrix
    for (int i = 0;i < src.height;i++)
        for (int j = 0;j < src.width;j++)
            values[i][j] = src.values[i][j];
}

// Move constructor
Matrix::Matrix(Matrix&& src)
{
    create_vlaues(src.height, src.width);
    //substitute components of src matrix into current matrix
    for (int i = 0;i < src.height;i++)
        for (int j = 0;j < src.width;j++)
            values[i][j] = src.values[i][j];
    //initialize src matrix
    src.values = nullptr;
    src.width = 0;
    src.height = 0;
}

// Destructor
Matrix::~Matrix()
{
    //delete values of current matrix
    delete_values();
}

int Matrix::getWidth() const
{
    return width;
}

int Matrix::getHeight() const
{
    return height;
}

void Matrix::resize(int row, int col)
{
    double* temp_matrix;
    temp_matrix = new double[row * col];
    //copy current matrix temporarily to temp matrix
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            //new fields are set to 0
            if (i < this->height && j < this->width)
                temp_matrix[i * col + j] = values[i][j];
            else
                temp_matrix[i * col + j] = 0;
        }

    create_vlaues(row, col);
    //copy temp matrix to current matrix
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            values[i][j] = temp_matrix[i * col + j];

    delete[] temp_matrix;
}

void Matrix::transpose()
{
    int row = this->width;
    int col = this->height;

    Matrix temp(row, col);
    //copy transposition of current matrix to temp matrix
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            temp.values[i][j] = values[j][i];

    //create new transposition matrix
    create_vlaues(row, col);
    //copy temp matrix to current matrix
    for (int i = 0; i < this->height; i++)
        for (int j = 0; j < this->width; j++)
            values[i][j] = temp.values[i][j];
}


// Copy assignment
Matrix& Matrix::operator= (const Matrix& src)
{
    create_vlaues(src.height, src.width);
    //copy components of src matrix to current matrix
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            values[i][j] = src.values[i][j];

    return *this;
}

// Move assignment
Matrix& Matrix::operator= (Matrix&& other)
{
    create_vlaues(other.height, other.width);
    //copy components of other matrix to current matrix
    for (int i = 0; i < other.width; i++)
        for (int j = 0; j < other.height; j++)
            values[i][j] = other.values[i][j];
    //initialize other matrix
    other.values = nullptr;
    other.width = 0;
    other.height = 0;

    return *this;
}


// Returns the value at the specified position in the matrix.
double& Matrix::operator()(const int row, const int col)
{
    //process exception
    assert(row > 0 && row <= height);
    assert(col > 0 && col <= width);

    return values[row][col];
}

double Matrix::operator()(const int row, const int col) const
{
    //process exception
    assert(row > 0 && row <= height);
    assert(col > 0 && col <= width);

    return values[row][col];
}

// Creates a new matrix which is the sum of this and another given matrix.
Matrix Matrix::operator+(const Matrix& other) const
{
    //get minimum row and column counts of other and current matrix
    int rows = std::min(this->height, other.height);
    int cols = std::min(this->width, other.width);

    Matrix temp(rows, cols);
    //add two matrix to temp matrix
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            temp.values[i][j] = other.values[i][j] + this->values[i][j];

    return temp;
}

// Adds a given matrix to the current.
Matrix& Matrix::operator+=(const Matrix& other)
{
    //get minimum row and column counts of other and current matrix
    int rows = std::min(this->height, other.height);
    int cols = std::min(this->width, other.width);

    Matrix temp(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            temp.values[i][j] = this->values[i][j];

    create_vlaues(rows, cols);
    //add other matrix to the current matrix
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            this->values[i][j] = other.values[i][j] + temp.values[i][j];

    return *this;
}

// Creates a new matrix which is the product of this and another given matrix.
Matrix Matrix::operator*(const Matrix& other) const
{
    //get minimum value of the current matrix's column count and other's row count
    int cols = std::min(width, other.height);

    Matrix temp(height, other.width);
    //perform the product of two matrix
    for (int i = 0; i < height; i++)
        for (int j = 0; j < other.width; j++)
            for (int k = 0; k < cols; k++)
                temp.values[i][j] += values[i][k] * other.values[k][j];

    return temp;
}

// Multiplies a given matrix with the current.
Matrix& Matrix::operator*=(const Matrix& other)
{
    //get minimum value of the current matrix's column count and other's row count
    int cols = std::min(width, other.height);

    Matrix temp(height, other.width);
    //perform the product of two matrix
    for (int i = 0; i < height; i++)
        for (int j = 0; j < other.width; j++)
            for (int k = 0; k < cols; k++)
                temp.values[i][j] += values[i][k] * other.values[k][j];
    //recreate the current matrix
    create_vlaues(temp.height, temp.height);
    //copy temp matrix to the current matrix
    for (int i = 0; i < temp.height; i++)
        for (int j = 0; j < temp.width; j++)
            values[i][j] = temp.values[i][j];

    return *this;
}


// Creates a new matrix which is the product of this and given number.
Matrix Matrix::operator*(double num) const
{
    Matrix temp(height, width);
    //perform the product of current matrix and num number
    for (int i = 0;i < height;i++)
        for (int j = 0;j < width;j++)
            temp.values[i][j] = values[i][j] * num;
    return temp;
}

// Mutliplies the current matrix with a given number.
Matrix& Matrix::operator*=(double num)
{
    //perform the product of current matrix and num number
    for (int i = 0; i < height; i++)
        for (int j = 0;j < width;j++)
            values[i][j] = values[i][j] * num;

    return *this;
}

// Determines if two matrices are equal.
bool Matrix::operator==(const Matrix& other) const
{
    //compare if row & column counts of two matrix are equal
    if (width != other.width || height != other.height)
        return false;
    //compare if the components of two matrix are equal
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if (!is_equal(other.values[i][j], values[i][j]))
                return false;

    return true;
}

void Matrix::create_vlaues(int row, int col)
{
    delete_values();
    //set row and column number of new matrix
    this->height = row;
    this->width = col;
    //create components of new matrix
    values = new double*[row];
    for (int i = 0; i < row; i++)
    {
        values[i] = new double[col];
    }
}

void Matrix::delete_values()
{
    //delete components of new matrix
    if (values != nullptr) {
        for (int i = 0; i < this->height; i++)
            delete[] values[i];
        //delete[] values;
    }

    this->width = 0;
    this->height = 0;
}
//compare if a and b are equal
bool Matrix::is_equal(double a, double b) const
{
    double epsilon = 0.001;
    bool result = ((a - b) > -epsilon) && ((a - b) < epsilon);

    return true;
}

//add for test
void Matrix::set_values(double val[], int nRow, int nCol)
{
    create_vlaues(nRow, nCol);

    for (int i = 0; i < nRow; i++)
        for (int j = 0; j < nCol; j++)
            values[i][j] = val[i * nCol + j];
}









