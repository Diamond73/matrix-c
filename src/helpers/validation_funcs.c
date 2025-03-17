#include "../s21_matrix.h"
int cheak(matrix_t* a) {
  int res = 0;
  if (a == NULL) {
    res = S21_INCORRECT_MATRIX;
  } else {
    if (a->columns == 0 || a->rows == 0 || a->matrix == NULL) {
      res = S21_INCORRECT_MATRIX;
    }
  }
  return res;
}
int cheak_num(matrix_t* a) {
  int res = 0;
  for (int i = 0; i < a->rows; i++) {
    for (int j = 0; j < a->columns; j++) {
      if (a->matrix[i][j] == INFINITY) {
        res = S21_ERROR_CALC;
        j = a->columns;
        i = a->rows;
      }
    }
  }
  return res;
}
int eq_size(matrix_t* a, matrix_t* b) {
  int res = 1;
  if (a != NULL && b != NULL) {
    res = (a->rows != b->rows || b->columns != a->columns);
  }
  return res;
}