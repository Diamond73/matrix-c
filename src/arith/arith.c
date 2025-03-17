#include "../helpers/helpers.h"
#include "../s21_matrix.h"
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = 0;
  int rows = 0;
  int columns = 0;
  if (cheak(A) == S21_INCORRECT_MATRIX || cheak(B) == S21_INCORRECT_MATRIX ||
      result == NULL) {
    res = S21_INCORRECT_MATRIX;
  }
  if (res != S21_INCORRECT_MATRIX) {
    res = s21_create_matrix(A->rows, A->columns, result);
    if ((eq_size(A, B) || cheak_num(A) == S21_ERROR_CALC ||
         cheak_num(B) == S21_ERROR_CALC)) {
      res = S21_ERROR_CALC;
    }
    rows = A->rows;
    columns = A->columns;
  }

  for (int i = 0; i < rows && res == 0; i++) {
    for (int j = 0; j < columns && res == 0; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }
  return res;
}
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = 0;
  int rows = 0;
  int columns = 0;
  if (cheak(A) == S21_INCORRECT_MATRIX || cheak(B) == S21_INCORRECT_MATRIX ||
      result == NULL) {
    res = S21_INCORRECT_MATRIX;
  }
  if (res != S21_INCORRECT_MATRIX) {
    res = s21_create_matrix(A->rows, A->columns, result);
    if ((eq_size(A, B) || cheak_num(A) == S21_ERROR_CALC ||
         cheak_num(B) == S21_ERROR_CALC)) {
      res = S21_ERROR_CALC;
    }
    rows = A->rows;
    columns = A->columns;
  }

  for (int i = 0; i < rows && res == 0; i++) {
    for (int j = 0; j < columns && res == 0; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
  return res;
}
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int res = 0;
  int rows = 0;
  int columns = 0;

  if (cheak(A) == S21_INCORRECT_MATRIX || result == NULL) {
    res = S21_INCORRECT_MATRIX;
  }
  if (res != S21_INCORRECT_MATRIX) {
    rows = A->rows;
    columns = A->columns;
    res = s21_create_matrix(rows, columns, result);
    if ((cheak_num(A) == S21_ERROR_CALC || number == INFINITY)) {
      res = S21_ERROR_CALC;
    }
  }

  for (int i = 0; i < rows && res == 0; i++) {
    for (int j = 0; j < columns && res == 0; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }
  return res;
}
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = 0;
  int rows = 0;
  int b_columns = 0;
  int a_rows = 0;

  if (cheak(A) == S21_INCORRECT_MATRIX || cheak(B) == S21_INCORRECT_MATRIX ||
      result == NULL) {
    res = S21_INCORRECT_MATRIX;
  }
  if (res != S21_INCORRECT_MATRIX) {
    res = s21_create_matrix(A->rows, B->columns, result);
    if ((A->columns != B->rows || cheak_num(A) == S21_ERROR_CALC ||
         cheak_num(B) == S21_ERROR_CALC)) {
      res = S21_ERROR_CALC;
    }

    rows = B->rows;
    b_columns = B->columns;
    a_rows = A->rows;
  }

  for (int i = 0; i < a_rows && res == 0; i++) {
    for (int j = 0; j < b_columns && res == 0; j++) {
      for (int m = 0; m < rows && res == 0; m++) {
        result->matrix[i][j] =
            result->matrix[i][j] + A->matrix[i][m] * B->matrix[m][j];
      }
    }
  }
  return res;
}
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  int rows = 0;
  int columns = 0;

  if (cheak(A) || cheak(B) || eq_size(A, B)) {
    res = FAILURE;
  } else {
    columns = A->columns;
    rows = A->rows;
  }
  for (int i = 0; i < rows && res != FAILURE; i++) {
    for (int j = 0; j < columns && res != FAILURE; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1e-7) {
        res = FAILURE;
        i = rows;
        j = columns;
      }
    }
  }
  return res;
}