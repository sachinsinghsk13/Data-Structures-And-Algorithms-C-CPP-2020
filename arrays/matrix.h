#ifndef __MATRIX__H__
#define __MATRIX_H__

class Matrix
{
private:
    const int rows;
    const int columns;
    int** matrix;
public:
    Matrix(int rows, int columns);
    void read_matrix();
    void print_matrix();
    Matrix *add_matrix(const Matrix* b);
    Matrix *subtract_matrix(const Matrix* b);
    Matrix *multiply_matrix(const Matrix* b);
    Matrix *transpose_matrix();
};

#endif