#ifndef C5_S21_MATRIX_H
#define C5_S21_MATRIX_H

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define esc 0.0000001

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

enum ERROR_CODES { OK, INCORRECT_MATRIX, CALCULATION_ERROR };

// 0 - OK
// 1 - Ошибка, некорректная матрица
// 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой
// нельзя провести вычисления и т.д.)

int s21_create_matrix(int rows, int columns,
                      matrix_t *result);  // Создание матриц +++
void s21_remove_matrix(matrix_t *A);      // Очистка матриц +++
int s21_eq_matrix(matrix_t *A, matrix_t *B);  // Сравнение матриц +++
int s21_sum_matrix(matrix_t *A, matrix_t *B,
                   matrix_t *result);  // Сложение матриц +++
int s21_sub_matrix(matrix_t *A, matrix_t *B,
                   matrix_t *result);  // Вычитание матриц +++
int s21_mult_number(matrix_t *A, double number,
                    matrix_t *result);  // Умножение матрицы на число +++
int s21_mult_matrix(matrix_t *A, matrix_t *B,
                    matrix_t *result);  // Умножение матриц +++
int s21_transpose(matrix_t *A,
                  matrix_t *result);  // Транспонирование матрицы +++
int s21_calc_complements(matrix_t *A, matrix_t *result);  // Минор матрицы +++
int s21_determinant(matrix_t *A, double *result);  // Определитель матрицы +++
int s21_inverse_matrix(matrix_t *A, matrix_t *result);  // Обратная матрица

void s21_initialize_matrix(matrix_t *A, double value, double step);
double det2x2(matrix_t *A);
double det3x3(matrix_t *A);
int det_nxn(matrix_t *A, double *result);
void print_matr(matrix_t matr);
int is_correct(matrix_t *A);
int minor(matrix_t *A, matrix_t *matr, int i, int j);

#endif