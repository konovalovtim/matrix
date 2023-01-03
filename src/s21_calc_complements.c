#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (A->rows <= 0 && A->columns <= 0) {
    res = INCORRECT_MATRIX;
  } else if (A->rows == 1 && A->columns == 1) {
    res = CALCULATION_ERROR;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t result_matrix = {0};
        double res_double;
        s21_create_matrix(A->rows - 1, A->columns - 1, &result_matrix);
        int k = 0, k1 = 0;
        for (int n = 0; n < result_matrix.rows; n++) {
          k = 0;
          if (n >= i) k1 = 1;
          for (int l = 0; l < result_matrix.columns; l++) {
            if (l == j) k = 1;
            result_matrix.matrix[n][l] = A->matrix[n + k1][l + k];
          }
        }
        res = s21_determinant(&result_matrix, &res_double);
        if (res == 0)
          result->matrix[i][j] = res_double * ((j + i) % 2 == 0 ? 1 : -1);
        s21_remove_matrix(&result_matrix);
      }
    }
  }
  return res;
}