#include <stdio.h>

#include "../helpers/helpers.h"
#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int res = 0;
  int rows = 0;
  int columns = 0;
  res = cheak(A);
  if (result == NULL) {
    res = S21_INCORRECT_MATRIX;
  }
  if (res != S21_INCORRECT_MATRIX) {
    res = s21_create_matrix(A->columns, A->rows, result);
    if ((cheak_num(A) == S21_ERROR_CALC ||
         cheak_num(result) == S21_ERROR_CALC)) {
      res = S21_ERROR_CALC;
    }
    rows = A->rows;
    columns = A->columns;
  }
  for (int i = 0; i < rows && res == 0; i++) {
    for (int j = 0; j < columns && res == 0; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }
  return res;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = 0;
  int rows = 0;
  int columns = 0;
  double main_det = 1;
  res = cheak(A);
  if (result == NULL) {
    res = S21_INCORRECT_MATRIX;
  }

  if (res != S21_INCORRECT_MATRIX) {
    res = s21_create_matrix(A->columns, A->rows, result);
    cheak_num(A);
    cheak_num(result);

    res = s21_determinant(A, &main_det);

    if ((cheak_num(A) == S21_ERROR_CALC ||
         cheak_num(result) == S21_ERROR_CALC || A->rows != A->columns ||
         main_det == 0)) {
      res = S21_ERROR_CALC;
    }
    rows = A->rows;
    columns = A->columns;
  }

  for (int i = 0; i < rows && res == 0 && rows != 1; i++) {
    for (int j = 0; j < columns && res == 0 && columns != 1; j++) {
      matrix_t new;

      result->matrix[i][j] =
          1 / main_det * pow(-1, i + j) * det(minor(A, i, j, &new));

      s21_remove_matrix(&new);
    }
  }
  if (rows == 1 || columns == 1) {
    res = S21_ERROR_CALC;
  }

  return res;
}
int s21_determinant(matrix_t *A, double *result) {
  int res = 0;
  int rows = 0;
  int columns = 0;
  res = cheak(A);
  if (res != S21_INCORRECT_MATRIX) {
    res = cheak_num(A);
    rows = A->rows;
    columns = A->columns;
  }
  if (res != S21_INCORRECT_MATRIX && res != S21_ERROR_CALC && columns == rows &&
      rows == 1) {
    *result = A->matrix[0][0];
  }
  if (res != S21_INCORRECT_MATRIX && res != S21_ERROR_CALC && columns == rows &&
      rows > 1) {
    *result = det(A);
  }
  if (res != S21_INCORRECT_MATRIX && res != S21_ERROR_CALC &&
      (columns != rows)) {
    res = S21_ERROR_CALC;
  }
  return res;
}
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = 0;
  double det = 0;
  res = s21_determinant(A, &det);

  if (res != S21_INCORRECT_MATRIX && res != S21_ERROR_CALC && A->rows == 1 &&
      A->matrix[0][0] != 0) {
    s21_create_matrix(A->rows, A->columns, result);
    result->matrix[0][0] = 1 / A->matrix[0][0];
  }
  if (res != S21_INCORRECT_MATRIX && res != S21_ERROR_CALC &&
      A->columns == A->rows && A->rows > 1 && det != 0) {
    matrix_t comp;

    res = s21_calc_complements(A, &comp);

    res = s21_transpose(&comp, result);
    s21_remove_matrix(&comp);
  }

  if (res != S21_INCORRECT_MATRIX && res != S21_ERROR_CALC && (det == 0)) {
    res = S21_ERROR_CALC;
  }
  return res;
}