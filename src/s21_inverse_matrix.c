#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = 0;
  int flag = 0;
  double det;
  double one = 1;
  if (!is_correct(A) || !result) return 1;
  if (A->rows != A->columns) return 2;
  matrix_t temp = {0};
  matrix_t temp1 = {0};
  s21_mult_number(A, one, &temp);
  s21_determinant(&temp, &det);
  if (A->rows != 1) s21_remove_matrix(&temp);
  if (det && A->rows == 1) {
    res = s21_create_matrix(A->rows, A->columns, result);
    result->matrix[0][0] = 1 / det;
    flag = 1;
  }
  if (det && !flag) {
    res = s21_calc_complements(A, &temp);
    if (!res) {
      res = s21_transpose(&temp, &temp1);
      if (!res) {
        res = s21_mult_number(&temp1, one / det, result);
        s21_remove_matrix(&temp1);
      }
      s21_remove_matrix(&temp);
    }
  } else if (!det)
    res = 2;
  return res;
}