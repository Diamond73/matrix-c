#ifndef HELPERS 
#define HELPERS
#include "../s21_matrix.h"
double det(matrix_t *A);
matrix_t *minor(matrix_t *A, int n, int m, matrix_t *result);
int cheak(matrix_t*a);
int cheak_num(matrix_t*a);
int eq_size(matrix_t* a, matrix_t* b);
#endif