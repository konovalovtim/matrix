#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int res = OK;
  if (A == NULL || A->rows <= 0 || A->columns <= 0) {
    res = INCORRECT_MATRIX;
  } else {
    if (A->rows != A->columns) {
      res = CALCULATION_ERROR;
    } else {
      *result = 0;
      if (A->rows == 2) {
        *result = A->matrix[0][0] * A->matrix[1][1] -
                  A->matrix[0][1] * A->matrix[1][0];
      } else if (A->rows == 1) {
        *result = A->matrix[0][0];
      } else {
        for (int i = 0; i < A->rows; i++) {
          matrix_t result_matrix = {0};
          double res_double = 0;
          s21_create_matrix(A->rows - 1, A->rows - 1, &result_matrix);
          int k = 0;
          for (int j = 0; j < result_matrix.rows; j++) {
            k = 0;
            for (int l = 0; l < result_matrix.columns; l++) {
              if (l == i) k = 1;
              result_matrix.matrix[j][l] = A->matrix[j + 1][l + k];
            }
          }
          s21_determinant(&result_matrix, &res_double);
          s21_remove_matrix(&result_matrix);
          *result += A->matrix[0][i] * res_double * (i % 2 == 0 ? 1 : -1);
        }
      }
    }
  }
  return res;
}