#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!is_correct(A) || !is_correct(B) || !result) return 1;
  if (A->columns != B->rows) return 2;
  if (s21_create_matrix(A->rows, B->columns, result)) return 1;
  int res = 0;
  double sum = 0;
  for (int i = 0; i < A->rows && !res; i++) {
    for (int j = 0; j < B->columns && !res; j++) {
      sum = 0;
      for (int x = 0; x < A->columns; x++) {
        sum += A->matrix[i][x] * B->matrix[x][j];
      }
      result->matrix[i][j] = sum;
      if (isinf(result->matrix[i][j])) {
        res = 2;
      }
    }
  }
  return res;
}