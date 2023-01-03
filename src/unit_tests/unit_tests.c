#include <check.h>

#include "../s21_matrix.h"

START_TEST(create_matrix) {
  matrix_t A = {0};
  int A_columns = -5;
  int A_rows = 0;
  int return_value = 0;
  return_value = s21_create_matrix(A_rows, A_columns, &A);
  ck_assert_int_eq(return_value, INCORRECT_MATRIX);
}
END_TEST

START_TEST(eq_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  int A_columns = 5;
  int A_rows = 6;
  int B_columns = 5;
  int B_rows = 6;

  s21_create_matrix(A_rows, A_columns, &A);
  s21_create_matrix(B_rows, B_columns, &B);
  A.matrix[0][0] = 1;
  B.matrix[0][0] = 2;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  A_columns = 5;
  B_columns = 15;
  A_rows = 6;
  B_rows = 26;
  s21_create_matrix(A_rows, A_columns, &A);
  s21_create_matrix(B_rows, B_columns, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_matrix_null) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(0, 0, &A);
  s21_create_matrix(0, 0, &B);
  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  int A_columns = 16;
  int A_rows = 5;
  int B_columns = 16;
  int B_rows = 5;
  int return_value = 0;

  s21_create_matrix(A_rows, A_columns, &A);
  s21_create_matrix(B_rows, B_columns, &B);
  double x = -5;
  for (int i = 0; i < A_rows; i++) {
    for (int j = 0; j < A_columns; j++) {
      A.matrix[i][j] = x;
      x += 0.373747;
      B.matrix[i][j] = 1;
      x -= 0.169375;
    }
  }
  return_value = s21_sum_matrix(&A, &B, &result);
  if (return_value == OK) {
    for (int i = 0; i < result.rows; i++) {
      for (int j = 0; j < result.columns; j++) {
        ck_assert_int_eq(result.matrix[i][j], A.matrix[i][j] + B.matrix[i][j]);
      }
    }
  }
  ck_assert_int_eq(return_value, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_matrix_incorrect) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  int res = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sum_matrix_calculation) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(4, 5, &A);
  s21_create_matrix(4, 4, &B);
  int res = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 2);
  ck_assert_int_eq(res, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  int A_columns = 23;
  int A_rows = 16;
  int B_columns = 23;
  int B_rows = 16;
  int return_value = 0;

  s21_create_matrix(A_rows, A_columns, &A);
  s21_create_matrix(B_rows, B_columns, &B);
  int x = -5;
  for (int i = 0; i < A_rows; i++) {
    for (int j = 0; j < A_columns; j++) {
      A.matrix[i][j] = x;
      x += 4.245837;
      B.matrix[i][j] = x++;
      x -= 3.285937;
    }
  }
  return_value = s21_sub_matrix(&A, &B, &result);
  if (return_value == OK) {
    for (int i = 0; i < result.rows; i++) {
      for (int j = 0; j < result.columns; j++) {
        ck_assert_double_eq_tol(result.matrix[i][j],
                                A.matrix[i][j] - B.matrix[i][j], 1e-7);
      }
    }
  }
  ck_assert_int_eq(return_value, OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_incorrect) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  int res = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_calculation) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(4, 5, &A);
  s21_create_matrix(4, 4, &B);
  int res = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(res, 2);
  ck_assert_int_eq(res, CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t check = {0};
  int A_columns = 3;
  int A_rows = 3;
  int return_value = 0;

  s21_create_matrix(A_rows, A_columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  s21_create_matrix(A_rows, A_columns, &check);
  check.matrix[0][0] = 2;
  check.matrix[0][1] = 4;
  check.matrix[0][2] = 6;
  check.matrix[1][0] = 8;
  check.matrix[1][1] = 10;
  check.matrix[1][2] = 12;
  check.matrix[2][0] = 14;
  check.matrix[2][1] = 16;
  check.matrix[2][2] = 18;
  double number = 2;
  return_value = s21_mult_number(&A, number, &result);
  for (int i = 0; i < A_rows; i++) {
    for (int j = 0; j < A_columns; j++) {
      ck_assert_double_eq_tol(check.matrix[i][j], result.matrix[i][j], 1e-7);
    }
  }
  ck_assert_int_eq(return_value, OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_number_incorrect) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t check = {0};
  int return_value = 0;

  s21_create_matrix(0, 0, &A);
  s21_create_matrix(0, 0, &check);
  double number = 2;
  return_value = s21_mult_number(&A, number, &result);
  for (int i = 0; i < 0; i++) {
    for (int j = 0; j < 0; j++) {
      ck_assert_double_eq_tol(check.matrix[i][j], result.matrix[i][j], 1e-7);
    }
  }
  ck_assert_int_eq(return_value, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_matrix) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  matrix_t check = {0};
  int A_columns = 3;
  int A_rows = 2;
  int B_columns = 2;
  int B_rows = 3;
  int return_value = 0;

  s21_create_matrix(A_rows, A_columns, &A);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = -3;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = -2;
  s21_create_matrix(B_rows, B_columns, &B);
  B.matrix[0][0] = -7;
  B.matrix[0][1] = 5;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = -1;
  B.matrix[2][0] = 4;
  B.matrix[2][1] = 3;
  s21_create_matrix(A_rows, B_columns, &check);
  check.matrix[0][0] = -16;
  check.matrix[0][1] = 16;
  check.matrix[1][0] = -35;
  check.matrix[1][1] = 15;
  return_value = s21_mult_matrix(&A, &B, &result);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq_tol(check.matrix[i][j], result.matrix[i][j], 1e-7);
    }
  }
  ck_assert_int_eq(return_value, OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_matrix_incorrect) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  matrix_t check = {0};
  int return_value = 0;

  s21_create_matrix(0, 0, &A);
  s21_create_matrix(0, 0, &B);
  s21_create_matrix(0, 0, &check);
  return_value = s21_mult_matrix(&A, &B, &result);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq_tol(check.matrix[i][j], result.matrix[i][j], 1e-7);
    }
  }
  ck_assert_int_eq(return_value, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_matrix_calculation) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  matrix_t check = {0};
  int return_value = 0;

  s21_create_matrix(1, 1, &A);
  s21_create_matrix(2, 1, &B);
  s21_create_matrix(0, 0, &check);
  return_value = s21_mult_matrix(&A, &B, &result);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq_tol(check.matrix[i][j], result.matrix[i][j], 1e-7);
    }
  }
  ck_assert_int_eq(return_value, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(transponse) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.columns = -1;

  int ret = s21_transpose(&A, &B);
  ck_assert_int_eq(ret, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(null_transpose) {
  matrix_t *B = NULL;
  matrix_t *R = NULL;
  int res = s21_transpose(B, R);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(determinant) {
  matrix_t A = {0};
  double result = 0;
  int A_columns = 0;
  int A_rows = 0;
  int return_value = 0;

  A_rows = 1;
  A_columns = 1;
  s21_create_matrix(A_rows, A_columns, &A);
  return_value = s21_determinant(&A, &result);
  ck_assert_int_eq(return_value, OK);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_incorrect) {
  matrix_t a = {0};
  double result = 0;
  int return_code = 0;
  s21_create_matrix(0, 0, &a);
  return_code = s21_determinant(&a, &result);
  s21_remove_matrix(&a);
  ck_assert_int_eq(return_code, 1);
}
END_TEST

START_TEST(determinant_calculation) {
  matrix_t a = {0};
  double result = 0;
  int return_code = 0;
  s21_create_matrix(1, 2, &a);
  return_code = s21_determinant(&a, &result);
  s21_remove_matrix(&a);
  ck_assert_int_eq(return_code, 2);
}
END_TEST

START_TEST(calc_complements) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t check = {0};
  int A_columns = 3;
  int A_rows = 3;
  int return_value = 0;

  s21_create_matrix(A_rows, A_columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  s21_create_matrix(A_rows, A_columns, &check);
  check.matrix[0][0] = 0;
  check.matrix[0][1] = 10;
  check.matrix[0][2] = -20;
  check.matrix[1][0] = 4;
  check.matrix[1][1] = -14;
  check.matrix[1][2] = 8;
  check.matrix[2][0] = -8;
  check.matrix[2][1] = -2;
  check.matrix[2][2] = 4;
  return_value = s21_calc_complements(&A, &result);
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_double_eq_tol(result.matrix[i][j], check.matrix[i][j], 1e-7);
    }
  }
  ck_assert_int_eq(return_value, OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(calc_complements_incorrect) {
  matrix_t A = {0};
  matrix_t check = {0};
  int return_value = 0;
  s21_create_matrix(0, 0, &A);
  return_value = s21_calc_complements(&A, &check);
  for (int i = 0; i < check.rows; i++) {
    for (int j = 0; j < check.columns; j++) {
      ck_assert_double_eq_tol(check.matrix[i][j], check.matrix[i][j], 1e-7);
    }
  }
  ck_assert_int_eq(return_value, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(calc_complements_calculation) {
  matrix_t A = {0};
  matrix_t check = {0};
  int return_value = 0;
  s21_create_matrix(1, 1, &A);
  return_value = s21_calc_complements(&A, &check);
  for (int i = 0; i < check.rows; i++) {
    for (int j = 0; j < check.columns; j++) {
      ck_assert_double_eq_tol(check.matrix[i][j], check.matrix[i][j], 1e-7);
    }
  }
  ck_assert_int_eq(return_value, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(inverse_matrix) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t check = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);
  A.matrix[0][0] = 1.;
  A.matrix[0][1] = -1.;
  A.matrix[0][2] = 1.;
  A.matrix[1][0] = -38.;
  A.matrix[1][1] = 41.;
  A.matrix[1][2] = -34.;
  A.matrix[2][0] = 27.;
  A.matrix[2][1] = -29.;
  A.matrix[2][2] = 24.;

  check.matrix[0][0] = 2.;
  check.matrix[0][1] = 5.;
  check.matrix[0][2] = 7.;
  check.matrix[1][0] = 6.;
  check.matrix[1][1] = 3.;
  check.matrix[1][2] = 4.;
  check.matrix[2][0] = 5.;
  check.matrix[2][1] = -2.;
  check.matrix[2][2] = -3.;

  s21_inverse_matrix(&A, &result);
  int res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(inverse_matrix_null) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t check = {0};
  s21_create_matrix(0, 0, &A);
  s21_inverse_matrix(&A, &result);
  int res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(inverse_matrix_calulation) {
  matrix_t A = {0};
  matrix_t result = {0};
  matrix_t check = {0};
  s21_create_matrix(1, 1, &A);
  s21_inverse_matrix(&A, &result);
  int res = s21_eq_matrix(&result, &check);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

int main() {
  Suite *s1 = suite_create("tests");
  TCase *s21_test = tcase_create("function");
  SRunner *sr = srunner_create(s1);
  suite_add_tcase(s1, s21_test);

  tcase_add_test(s21_test, create_matrix);
  tcase_add_test(s21_test, eq_matrix);
  tcase_add_test(s21_test, eq_matrix_null);
  tcase_add_test(s21_test, sum_matrix);
  tcase_add_test(s21_test, sum_matrix_incorrect);
  tcase_add_test(s21_test, sum_matrix_calculation);
  tcase_add_test(s21_test, sub_matrix);
  tcase_add_test(s21_test, sub_matrix_incorrect);
  tcase_add_test(s21_test, sub_matrix_calculation);
  tcase_add_test(s21_test, mult_number);
  tcase_add_test(s21_test, mult_number_incorrect);
  tcase_add_test(s21_test, mult_matrix);
  tcase_add_test(s21_test, mult_matrix_incorrect);
  tcase_add_test(s21_test, mult_matrix_calculation);
  tcase_add_test(s21_test, transponse);
  tcase_add_test(s21_test, null_transpose);
  tcase_add_test(s21_test, determinant);
  tcase_add_test(s21_test, determinant_incorrect);
  tcase_add_test(s21_test, determinant_calculation);
  tcase_add_test(s21_test, calc_complements);
  tcase_add_test(s21_test, calc_complements_incorrect);
  tcase_add_test(s21_test, calc_complements_calculation);
  tcase_add_test(s21_test, inverse_matrix);
  tcase_add_test(s21_test, inverse_matrix_null);
  tcase_add_test(s21_test, inverse_matrix_calulation);

  srunner_run_all(sr, CK_VERBOSE);
  srunner_free(sr);

  return 0;
}
