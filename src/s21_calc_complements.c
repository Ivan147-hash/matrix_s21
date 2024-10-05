#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = 0;
  double temp = 0;
  if (!is_correct(A) || !result) return 1;
  if (A->columns != A->rows) return 2;
  if (s21_create_matrix(A->rows, A->columns, result)) return 1;
  if (A->rows == 1) {
    res = s21_create_matrix(A->rows, A->columns, result);
    result->matrix[0][0] = 1;
  } else {
    matrix_t matr;
    s21_create_matrix(A->rows - 1, A->columns - 1, &matr);
    for (int i = 0; i < A->rows && !res; i++) {
      for (int j = 0; j < A->columns && !res; j++) {
        minor(A, &matr, i, j);
        s21_determinant(&matr, &temp);
        temp = temp * pow(-1, i + j);
        result->matrix[i][j] = temp;
      }
    }
    s21_remove_matrix(&matr);
  }
  return res;
}

int minor(matrix_t *A, matrix_t *matr, int i, int j) {
  int res = 0;
  int c = 0;
  int r = 0;
  int flag = 0;
  for (int x = 0; x < A->rows; x++) {
    for (int y = 0; y < A->columns; y++) {
      if (x != i && y != j) {
        matr->matrix[r][c] = A->matrix[x][y];
        c++;
        flag = 1;
      }
    }
    if (flag) {
      r++;
      flag = 0;
      c = 0;
    }
  }
  return res;
}