#include "matrix.h"
#include "math.h"
#include <assert.h>
#include <stdlib.h>

void test_matrix()
{
    t_matrix m;
    float matrix_data[16] = {
        1.0f, 2.0f, 3.0f, 4.0f, 
        5.5f, 6.5f, 7.5f, 8.5f,
        9.0f, 10.0f, 11.0f, 12.0f,
        13.5f, 14.5f, 15.5f, 16.5f
    };
    assert(matrix(&m, 4, 4, matrix_data));
    assert(eq(matrix_get(&m, 0, 0), 1.0f));
    assert(eq(matrix_get(&m, 0, 3), 4.0f));
    assert(eq(matrix_get(&m, 1, 0), 5.5f));
    assert(eq(matrix_get(&m, 1, 2), 7.5f));
    assert(eq(matrix_get(&m, 2, 2), 11.0f));
    assert(eq(matrix_get(&m, 3, 0), 13.5f));
    assert(eq(matrix_get(&m, 3, 2), 15.5f));
    free_matrix(&m);
}

void test_matrix_equality()
{
    t_matrix m1;
    t_matrix m2;
    float data[4] = {
        1.0f, 2.0f,
        3.0f, 4.0f
    };
    assert(matrix(&m1, 2, 2, data));
    assert(matrix(&m2, 2, 2, data));
    assert(matrix_eq(&m1, &m2));
    free_matrix(&m1);
    free_matrix(&m2);
}

void test_matrix_inequality()
{
    t_matrix m1;
    t_matrix m2;
    float data1[4] = {
        1.0f, 2.0f,
        3.0f, 4.0f
    };
    float data2[4] = {
        1.0f, 2.0f,
        5.0f, 4.0f
    };
    assert(matrix(&m1, 2, 2, data1));
    assert(matrix(&m2, 2, 2, data2));
    assert(!matrix_eq(&m1, &m2));
    free_matrix(&m1);
    free_matrix(&m2);
}

/*
Scenario: Multiplying two matrices
Given the following matrix A:
| 1 | 2 | 3 | 4 |
| 5 | 6 | 7 | 8 |
| 9 | 8 | 7 | 6 |
| 5 | 4 | 3 | 2 |
And the following matrix B:
| -2 | 1 | 2 | 3 |
| 3 | 2 | 1 | -1 |
| 4 | 3 | 6 | 5 |
| 1 | 2 | 7 | 8 |
Then A * B is the following 4x4 matrix:
| 20| 22 | 50 | 48 |
| 44| 54 | 114 | 108 |
| 40| 58 | 110 | 102 |
| 16| 26 | 46 | 42 |
*/

void test_matrix_mul()
{
    t_matrix m1;
    t_matrix m2;
    t_matrix m3;
    t_matrix res;
    float data1[16] = {
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 8, 7, 6,
        5, 4, 3, 2
    };
    float data2[16] = {
        -2, 1, 2, 3,
        3, 2, 1, -1,
        4, 3, 6, 5,
        1, 2, 7, 8
    };
    float data3[16] = {
        20, 22, 50, 48,
        44, 54, 114, 108,
        40, 58, 110, 102,
        16, 26, 46, 42
    };
    assert(matrix(&m1, 4, 4, data1));
    assert(matrix(&m2, 4, 4, data2));
    assert(matrix(&m3, 4, 4, data3));
    assert(matrix_mul(&res, &m1, &m2));
    assert(matrix_eq(&m3, &res));
}

int main(void)
{
    test_matrix();
    test_matrix_equality();
    test_matrix_inequality();
    test_matrix_mul();
    return (EXIT_SUCCESS);
}