#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res = 0;
  if (rows < 1 || columns < 1 || !result) return 1;
  result->columns = columns;
  result->rows = rows;
  result->matrix = calloc(rows, sizeof(double *));
  for (int i = 0; i < rows; i++) {
    result->matrix[i] = calloc(columns, sizeof(double));
  }
  if (!result->matrix) res = 1;
  return res;
}