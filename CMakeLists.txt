cmake_minimum_required(VERSION 3.24)
project(matrix C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(matrix
        src/unit_tests/unit_tests.c
        src/s21_calc_complements.c
        src/s21_create_matrix.c
        src/s21_determinant.c
        src/s21_eq_matrix.c
        src/s21_inverse_matrix.c
        src/s21_matrix.h
        src/s21_mult_matrix.c
        src/s21_mult_number.c
        src/s21_remove_matrix.c
        src/s21_sub_matrix.c
        src/s21_sum_matrix.c
        src/s21_transpose.c)
