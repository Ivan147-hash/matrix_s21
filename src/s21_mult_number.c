#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int res = 0;
  if (!is_correct(A) || !result) return 1;
  if (!isfinite(number)) return 2;
  if (s21_create_matrix(A->rows, A->columns, result)) return 1;
  for (int i = 0; i < A->rows && !res; i++) {
    for (int j = 0; j < A->columns && !res; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
      if (isinf(result->matrix[i][j])) {
        res = 2;
      }
    }
  }
  return res;
}