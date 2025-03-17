#ifndef S21_MATRIX
#define S21_MATRIX 
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define S21_OK 0
#define S21_INCORRECT_MATRIX 1
#define S21_ERROR_CALC 2
#define SUCCESS 1
#define FAILURE 0
// Матрица

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

// создание и очистка 

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_initialize_matrix(matrix_t *a, double first, double step);
void print(matrix_t *A);
//арифметика 

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_eq_matrix(matrix_t *A, matrix_t *B);

//особые операции

int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif 