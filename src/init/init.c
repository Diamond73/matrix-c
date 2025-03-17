#include "init.h"
int s21_initialize_matrix(matrix_t *a, double first, double step) {
  int res = 0;
  if (a == NULL || a->matrix == NULL || a->columns == 0 || a->rows == 0) {
    res = 1;
  }
  a->matrix[0][0] = first;
  for (int i = 0; i < a->rows; i++) {
    if (i - 1 >= 0) {
      a->matrix[i][0] = a->matrix[i - 1][a->columns - 1] + step;
    }
    for (int j = 1; j < a->columns; j++) {
      a->matrix[i][j] = a->matrix[i][j - 1] + step;
    }
  }
  return res;
}