#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int res = 0;
  if (!is_correct(A)) return 1;
  if (A->rows != A->columns) return 2;
  if (A->rows == 1) {
    *result = A->matrix[0][0];
    if (!isfinite(*result)) res = 2;
  }
  if (!res && A->rows == 2) {
    *result = det2x2(A);
    if (!isfinite(*result)) res = 2;
  }
  if (!res && A->rows == 3) {
    *result = det3x3(A);
    if (!isfinite(*result)) res = 2;
  }

  if (!res && A->rows > 3) {
    res = det_nxn(A, result);
  }
  if (res) *result = 0;
  return res;
}

double det2x2(matrix_t *A) {
  return A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
}

double det3x3(matrix_t *A) {
  return (A->matrix[0][0] * A->matrix[1][1] * A->matrix[2][2]) +
         (A->matrix[2][0] * A->matrix[0][1] * A->matrix[1][2]) +
         (A->matrix[1][0] * A->matrix[2][1] * A->matrix[0][2]) -
         (A->matrix[2][0] * A->matrix[1][1] * A->matrix[0][2]) -
         (A->matrix[1][0] * A->matrix[0][1] * A->matrix[2][2]) -
         (A->matrix[0][0] * A->matrix[1][2] * A->matrix[2][1]);
}

int det_nxn(matrix_t *A, double *result) {
  int flag = 0;
  double per = 0;
  for (int j = 0; j < A->rows - 1 && !flag; j++) {
    for (int i = j + 1; i < A->rows && !flag; i++) {
      per = A->matrix[i][j];
      for (int x = 0; x < A->columns && !flag; x++) {
        A->matrix[i][x] =
            A->matrix[i][x] - A->matrix[j][x] * per / A->matrix[j][j];
        if (!isfinite(A->matrix[i][x])) {
          flag = 2;
        }
      }
    }
  }
  *result = 1;
  for (int y = 0; y < A->rows && !flag; y++) {
    *result *= A->matrix[y][y];
  }
  return flag;
}