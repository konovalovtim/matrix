#ifndef SRC_S21_MATRIX_H
#define SRC_S21_MATRIX_H

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

enum res { OK, INCORRECT_MATRIX, CALCULATION_ERROR };

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// Создание матриц (OK, INCORRECT_MATRIX)
int s21_create_matrix(int rows, int columns, matrix_t *result);
// Очистка матриц
void s21_remove_matrix(matrix_t *A);
// Сравнение матриц (SUCCESS, FAILURE)
int s21_eq_matrix(matrix_t *A, matrix_t *B);
// Сложение и вычитание матриц (OK, INCORRECT_MATRIX, CALCULATION_ERROR)
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
// Умножение матрицы на число. Умножение двух матриц (OK, INCORRECT_MATRIX,
// CALCULATION_ERROR)
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
// Транспонирование матрицы
int s21_transpose(matrix_t *A, matrix_t *result);
// Минор матрицы и матрица алгебраических дополнений
int s21_calc_complements(matrix_t *A, matrix_t *result);
// Определитель матрицы
int s21_determinant(matrix_t *A, double *result);
// Обратная матрица
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int s21_check_matrix(matrix_t *A);

#endif  //  SRC_S21_MATRIX_H