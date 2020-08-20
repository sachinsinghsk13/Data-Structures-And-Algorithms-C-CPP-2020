#ifndef __MATRIX__H__
#define __MATRIX_H__

class Matrix
{
private:
    const int rows;
    const int columns;
    int** matrix;
    void init_matrix();
public:
    Matrix(int order); // constructor for square matrix
    Matrix(int rows, int columns);
    void read_matrix();
    void print_matrix();
    void set_element(int row, int column, int value);
    int get_element(int row, int column);
    Matrix *add_matrix(const Matrix* b);
    Matrix *subtract_matrix(const Matrix* b);
    Matrix *multiply_matrix(const Matrix* b);
    Matrix *transpose_matrix();
};

#endif