#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = 0;
  if (!is_correct(A) || !is_correct(B) || !result) return 1;
  if ((A->rows != B->rows || A->columns != B->columns) && !res) return 2;
  if (s21_create_matrix(A->rows, A->columns, result)) return 1;
  for (int i = 0; i < A->rows && !res; i++) {
    for (int j = 0; j < A->columns && !res; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      if (isinf(result->matrix[i][j])) {
        res = 2;
      }
    }
  }
  return res;
}