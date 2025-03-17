#include "helpers.h"
double det(matrix_t *A) {
  double res = 0;
  if (A->columns == 2 && A->rows == A->columns) {
    res = A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
  }
  if (A->columns == 1 && A->rows == A->columns) {
    res = A->matrix[0][0];
  }
  if (A->columns > 2 && A->rows == A->columns) {
    for (int i = 0; i < A->columns; i++) {
      matrix_t result;

      res = res + pow(-1, i) * A->matrix[0][i] * det(minor(A, 0, i, &result));
      s21_remove_matrix(&result);
    }
  }
  return res;
}
matrix_t *minor(matrix_t *A, int n, int m, matrix_t *result) {
  s21_create_matrix((A->rows - 1), (A->columns - 1), result);

  int k = 0;
  int l = 0;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (!(i == n || j == m)) {
        result->matrix[k][l] = A->matrix[i][j];
        l++;
      }
    }

    if (i != n) {
      k++;
    }
    l = 0;
  }

  return result;
}