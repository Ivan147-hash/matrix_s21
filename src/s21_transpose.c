#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int res = 0;
  if (!is_correct(A) || !result) return 1;
  if (s21_create_matrix(A->columns, A->rows, result)) return 1;
  for (int i = 0; i < result->rows && !res; i++) {
    for (int j = 0; j < result->columns && !res; j++) {
      result->matrix[i][j] = A->matrix[j][i];
    }
  }
  return res;
}