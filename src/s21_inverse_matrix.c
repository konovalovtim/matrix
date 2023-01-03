#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = OK, check = 0;
  if (A->rows <= 0 && A->columns <= 0) {
    res = INCORRECT_MATRIX;
  } else {
    double x = 0;
    int p = s21_determinant(A, &x);
    if (p == 0 && x != 0 && (A->rows != 1 && A->columns != 1)) {
      matrix_t det;
      check = s21_calc_complements(A, &det);
      s21_transpose(&det, result);
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] /= x;
        }
      }
      if (check == 0) s21_remove_matrix(&det);
    } else {
      res = CALCULATION_ERROR;
    }
  }
  return res;
}