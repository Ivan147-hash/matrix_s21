#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (!A && !B) res = FAILURE;
  if (A->columns != B->columns) res = FAILURE;
  if (A->rows != B->rows) res = FAILURE;
  for (int i = 0; i < A->rows && res; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= esc) {
        res = FAILURE;
      }
    }
  }
  return res;
}