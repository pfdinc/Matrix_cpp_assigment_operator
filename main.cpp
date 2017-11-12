//============================================================================
// Name        : matrix.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "matrix.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int rollDie();

int main()
{
    srand((unsigned)time(0));
    int row = rollDie();
    int col = rollDie();
    std::cout << "Please enter first Matrix A (" << row << " X " << col << ")\n";
    Matrix A(row, col);
    double valA[36];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++) {
           std::cin >> valA[i * col + j];
        }
    }

    int row1 = rollDie();
    int col1 = rollDie();
    std::cout << "Please enter second Matrix B (" << row1 << " X " << col1 << ")\n";
    Matrix B(row1, col1);
    double valB[36];

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++) {
            std::cin >> valB[i * col1 + j];
        }
    }
    std::cout << "Matrix A is as follows: " << std::endl;
    A.set_values(valA, row, col);
    for (int i = 0; i < A.getHeight(); i++)
    {
        for (int j = 0; j < A.getWidth(); j++) {
            std::cout << A.get_values()[i][j] << "  ";
        }
        std::cout << std::endl;
    }

    std::cout << "Matrix B is as follows: " << std::endl;
    B.set_values(valB, row1, col1);
    for (int i = 0; i < B.getHeight(); i++)
    {
        for (int j = 0; j < B.getWidth(); j++) {
            std::cout << B.get_values()[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    //test resize()
    std::cout << "***** test: resize() *****" << std::endl;
    std::cout << "Matrix A.resize(4, 5) is as follows: " << std::endl;
    Matrix Are = A;
    Are.resize(4, 5);
    if (Are.get_values() != nullptr)
    {
        for (int i = 0; i < Are.getHeight(); i++)
        {
            for (int j = 0; j < Are.getWidth(); j++) {

                std::cout << Are.get_values()[i][j] << "  ";
            }
            std::cout << std::endl;
        }
    }
    //test transpose
    std::cout << "***** test: transpose() *****" << std::endl;
    std::cout << "Matrix B.trasnpose() is as follows: " << std::endl;
    Matrix Bt = B;
    Bt.transpose();

    if (Bt.get_values() != nullptr)
    {
        for (int i = 0; i < Bt.getHeight(); i++)
        {
            for (int j = 0; j < Bt.getWidth(); j++) {

                std::cout << Bt.get_values()[i][j] << "  ";
            }
            std::cout << std::endl;
        }
    }
    //test C = A + B
    std::cout << "***** test: Matrix Sum *****" << std::endl;
    std::cout << "Matrix A + B is as follows: " << std::endl;
    Matrix C = A + B;
    if (C.get_values() != nullptr)
    {
        for (int i = 0; i < C.getHeight(); i++)
        {
            for (int j = 0; j < C.getWidth(); j++) {

                std::cout << C.get_values()[i][j] << "  ";
            }
            std::cout << std::endl;
        }
    }
    //test D = A * 0.5
    std::cout << "***** test: Product of Matrix and Number *****" << std::endl;
    std::cout << "Matrix A * 0. 5 is as follows: " << std::endl;
    Matrix D = A * 0.5;
    if (D.get_values() != nullptr)
    {
        for (int i = 0; i < D.getHeight(); i++)
        {
            for (int j = 0; j < D.getWidth(); j++) {

                std::cout << D.get_values()[i][j] << "  ";
            }
            std::cout << std::endl;
        }
    }
    //test E = A * B
    std::cout << "***** test: Product of two matrix *****" << std::endl;
    std::cout << "Matrix A * B is as follows: " << std::endl;
    Matrix E = A * B;
    if (E.get_values() != nullptr)
    {
        for (int i = 0; i < E.getHeight(); i++)
        {
            for (int j = 0; j < E.getWidth(); j++) {

                std::cout << E.get_values()[i][j] << "  ";
            }
            std::cout << std::endl;
        }
    }
    system("pause");

    return 0;
}

int rollDie() {
    return (rand() % 5) + 2;
}