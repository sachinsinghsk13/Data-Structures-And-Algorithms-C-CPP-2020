#include "matrix.h"
#include <iostream>
using namespace std;
void Matrix::init_matrix()
{
    matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[columns];
    }
}
Matrix::Matrix(int rows, int columns) : rows(rows), columns(columns)
{
    init_matrix();
}

Matrix::Matrix(int order) : rows(order), columns(order)
{
    init_matrix();
}
// read matrix elements from stdin
void Matrix::read_matrix()
{
    cout << "Enter Your " << rows << "x" << columns << " Matrix : " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

// utility method to print the matrix
void Matrix::print_matrix()
{
    for (int i = 0; i < rows * 5; i++)
        cout << "-";
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < rows * 5; i++)
        cout << "-";
    cout << endl;
}

// this method add's two matrices
Matrix *Matrix::add_matrix(const Matrix *b)
{
    // check for order match
    if (rows == b->rows && columns == b->columns)
    {
        Matrix *m = new Matrix(rows, columns);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                m->matrix[i][j] = matrix[i][j] + b->matrix[i][j];
            }
        }
        return m;
    }
    else
    {
        cout << "Error : Matrix order not same " << endl;
        return nullptr;
    }
}

// this method add's two matrices
Matrix *Matrix::subtract_matrix(const Matrix *b)
{
    // check for order match
    if (rows == b->rows && columns == b->columns)
    {
        Matrix *m = new Matrix(rows, columns);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                m->matrix[i][j] = matrix[i][j] - b->matrix[i][j];
            }
        }
        return m;
    }
    else
    {
        cout << "Error : Matrix order not same " << endl;
        return nullptr;
    }
}

Matrix *Matrix::multiply_matrix(const Matrix *b)
{
    if (columns == b->rows)
    {
        Matrix *m = new Matrix(rows, b->columns);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < b->columns; j++)
            {
                int sum = 0;
                for (int k = 0; k < columns; k++)
                    sum += matrix[i][k] * b->matrix[k][j];
                m->matrix[i][j] = sum;
            }
        }
        return m;
    }
    else
    {
        cout << "Error : Multiplication not possible" << endl;
        return nullptr;
    }
}

Matrix *Matrix::transpose_matrix()
{
    Matrix *m = new Matrix(columns, rows);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            m->matrix[j][i] = matrix[i][j];
        }
    }
    return m;
}

void Matrix::set_element(int row, int column, int value)
{
    matrix[row][column] = value;
}
int Matrix::get_element(int row, int column)
{
    return matrix[row][column];
}