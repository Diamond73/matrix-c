#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res = 0;
  if (result == NULL || rows <= 0 || columns <= 0) {
    rows = 0;
    res = S21_INCORRECT_MATRIX;

  } else {
    result->matrix = (double **)malloc(rows * (int)sizeof(double *));
    result->columns = columns;
    result->rows = rows;
  }
  if (res != S21_INCORRECT_MATRIX && result->matrix != NULL) {
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)malloc(columns * sizeof(double));
      if (result->matrix[i] == NULL) {
        i = rows;
        res = 1;
        s21_remove_matrix(result);
      }
      for (int j = 0; j < columns; j++) {
        result->matrix[i][j] = 0;
      }
    }
  }
  return res;
}
void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    for (int i = 0; i < A->rows && A->matrix[i] != NULL && A->matrix != NULL;
         i++) {
      free(A->matrix[i]);
      A->matrix[i] = NULL;
    }
    free(A->matrix);
    A->matrix = NULL;
  }
}
