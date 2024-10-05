#include "s21_matrix.h"

void s21_initialize_matrix(matrix_t *A, double value, double step) {
  if (A != NULL && A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        A->matrix[i][j] = value;
        value += step;
      }
    }
  }
}