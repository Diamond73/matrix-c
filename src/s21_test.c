
#include <check.h>
#include <stdlib.h>

#include "init/init.h"
#include "s21_matrix.h"
//====================================================================//
//====================//      Сreate matrix     //====================//
//====================================================================//

START_TEST(test_s21_create_matrix_1) {
  matrix_t result;
  int code = s21_create_matrix(3, 3, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(result.rows, 3);
  ck_assert_int_eq(result.columns, 3);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_create_matrix_2) {
  matrix_t result;
  int code = s21_create_matrix(6, 6, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(result.rows, 6);
  ck_assert_int_eq(result.columns, 6);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_create_matrix_3) {
  matrix_t result;
  int code = s21_create_matrix(5, 3, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(result.rows, 5);
  ck_assert_int_eq(result.columns, 3);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_create_matrix_4) {
  matrix_t result;
  int code = s21_create_matrix(3, 5, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(result.rows, 3);
  ck_assert_int_eq(result.columns, 5);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_create_matrix_5) {
  matrix_t result;
  int code = s21_create_matrix(1, 3, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_int_eq(result.rows, 1);
  ck_assert_int_eq(result.columns, 3);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_create_matrix_6) {
  matrix_t result;
  int code = s21_create_matrix(0, 0, &result);
  ck_assert_int_eq(code, S21_INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_s21_create_matrix_7) {
  matrix_t result;
  int code = s21_create_matrix(0, 5, &result);
  ck_assert_int_eq(code, S21_INCORRECT_MATRIX);
}
END_TEST
START_TEST(test_s21_create_matrix_8) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(0, 0, &A), S21_INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_s21_create_matrix_9) {
  ck_assert_int_eq(s21_create_matrix(5, 5, NULL), S21_INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_s21_create_matrix_10) {
  matrix_t result;
  int code = s21_create_matrix(0, 6, &result);
  ck_assert_int_eq(code, S21_INCORRECT_MATRIX);
}
END_TEST

//====================================================================//
//====================//      Remove Matrix     //====================//
//====================================================================//

START_TEST(test_s21_remove_matrix_1) {
  matrix_t result;
  s21_create_matrix(3, 3, &result);
  s21_remove_matrix(&result);
  ck_assert_ptr_eq(result.matrix, NULL);
}
END_TEST

START_TEST(test_s21_remove_matrix_2) {
  s21_remove_matrix(NULL);
  ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(test_s21_remove_matrix_3) {
  matrix_t A = {};
  s21_remove_matrix(&A);
  ck_assert_int_eq(1, 1);
}
END_TEST

START_TEST(test_s21_remove_matrix_4) {
  matrix_t result;
  s21_create_matrix(3, 5, &result);
  s21_remove_matrix(&result);
  ck_assert_ptr_eq(result.matrix, NULL);
}
END_TEST

START_TEST(test_s21_remove_matrix_5) {
  matrix_t result;
  s21_create_matrix(1, 3, &result);
  s21_remove_matrix(&result);
  ck_assert_ptr_eq(result.matrix, NULL);
}
END_TEST

//====================================================================//
//====================//      Matrix Equal      //====================//
//====================================================================//

START_TEST(test_s21_eq_matrix_equal_1) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 4.0;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_equal_2) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  B.matrix[0][0] = 2.0;
  B.matrix[0][1] = 3.0;
  B.matrix[1][0] = 4.0;
  B.matrix[1][1] = 5.0;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_equal_3) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 3.0;
  A.matrix[0][1] = 4.0;
  A.matrix[1][0] = 5.0;
  A.matrix[1][1] = 6.0;
  B.matrix[0][0] = 3.0;
  B.matrix[0][1] = 4.0;
  B.matrix[1][0] = 5.0;
  B.matrix[1][1] = 6.0;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_equal_4) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 6.0;
  A.matrix[0][1] = 5.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 3.0;
  B.matrix[0][0] = 6.0;
  B.matrix[0][1] = 5.0;
  B.matrix[1][0] = 4.0;
  B.matrix[1][1] = 3.0;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_equal_5) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 8.0;
  A.matrix[0][1] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 5.0;
  B.matrix[0][0] = 8.0;
  B.matrix[0][1] = 7.0;
  B.matrix[1][0] = 6.0;
  B.matrix[1][1] = 5.0;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_equal_6) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 5.0;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_equal_7) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[1][0] = 6.0;
  B.matrix[1][1] = 4.0;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_equal_8) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 7.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 4.0;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_equal_9) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;
  B.matrix[0][0] = 6.0;
  B.matrix[0][1] = 2.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 4.0;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_eq_matrix_equal_10) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 8.0;
  A.matrix[0][1] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 5.0;
  B.matrix[0][0] = 8.0;
  B.matrix[0][1] = 6.0;
  B.matrix[1][0] = 7.0;
  B.matrix[1][1] = 5.0;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(result, FAILURE);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

//====================================================================//
//====================//   Addition   Matrix    //====================//
//====================================================================//

START_TEST(test_s21_sum_matrix_1) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;
  B.matrix[0][0] = 5.0;
  B.matrix[0][1] = 6.0;
  B.matrix[1][0] = 7.0;
  B.matrix[1][1] = 8.0;
  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_double_eq(result.matrix[0][0], 6.0);
  ck_assert_double_eq(result.matrix[0][1], 8.0);
  ck_assert_double_eq(result.matrix[1][0], 10.0);
  ck_assert_double_eq(result.matrix[1][1], 12.0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sum_matrix_2) {
  matrix_t A = {};
  matrix_t B = {};
  ck_assert_int_eq(s21_sum_matrix(&A, &B, NULL), S21_INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_s21_sum_matrix_3) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;
  B.matrix[0][0] = 5.0;
  B.matrix[0][1] = 6.0;
  B.matrix[1][0] = 7.0;
  B.matrix[1][1] = 8.0;
  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_double_eq(result.matrix[0][0], 6.0);
  ck_assert_double_eq(result.matrix[0][1], 8.0);
  ck_assert_double_eq(result.matrix[1][0], 10.0);
  ck_assert_double_eq(result.matrix[1][1], 12.0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sum_matrix_4) {
  matrix_t A, B, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;
  B.matrix[0][0] = 9.0;
  B.matrix[0][1] = 8.0;
  B.matrix[0][2] = 7.0;
  B.matrix[1][0] = 6.0;
  B.matrix[1][1] = 5.0;
  B.matrix[1][2] = 4.0;
  B.matrix[2][0] = 3.0;
  B.matrix[2][1] = 2.0;
  B.matrix[2][2] = 1.0;

  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_double_eq(result.matrix[0][0], 10.0);
  ck_assert_double_eq(result.matrix[0][1], 10.0);
  ck_assert_double_eq(result.matrix[0][2], 10.0);
  ck_assert_double_eq(result.matrix[1][0], 10.0);
  ck_assert_double_eq(result.matrix[1][1], 10.0);
  ck_assert_double_eq(result.matrix[1][2], 10.0);
  ck_assert_double_eq(result.matrix[2][0], 10.0);
  ck_assert_double_eq(result.matrix[2][1], 10.0);
  ck_assert_double_eq(result.matrix[2][2], 10.0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sum_matrix_5) {
  matrix_t A, B, result;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[0][3] = 4.0;
  A.matrix[1][0] = 5.0;
  A.matrix[1][1] = 6.0;
  A.matrix[1][2] = 7.0;
  A.matrix[1][3] = 8.0;
  A.matrix[2][0] = 9.0;
  A.matrix[2][1] = 10.0;
  A.matrix[2][2] = 11.0;
  A.matrix[2][3] = 12.0;
  A.matrix[3][0] = 13.0;
  A.matrix[3][1] = 14.0;
  A.matrix[3][2] = 15.0;
  A.matrix[3][3] = 16.0;
  B.matrix[0][0] = 16.0;
  B.matrix[0][1] = 15.0;
  B.matrix[0][2] = 14.0;
  B.matrix[0][3] = 13.0;
  B.matrix[1][0] = 12.0;
  B.matrix[1][1] = 11.0;
  B.matrix[1][2] = 10.0;
  B.matrix[1][3] = 9.0;
  B.matrix[2][0] = 8.0;
  B.matrix[2][1] = 7.0;
  B.matrix[2][2] = 6.0;
  B.matrix[2][3] = 5.0;
  B.matrix[3][0] = 4.0;
  B.matrix[3][1] = 3.0;
  B.matrix[3][2] = 2.0;
  B.matrix[3][3] = 1.0;

  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_double_eq(result.matrix[0][0], 17.0);
  ck_assert_double_eq(result.matrix[0][1], 17.0);
  ck_assert_double_eq(result.matrix[0][2], 17.0);
  ck_assert_double_eq(result.matrix[0][3], 17.0);
  ck_assert_double_eq(result.matrix[1][0], 17.0);
  ck_assert_double_eq(result.matrix[1][1], 17.0);
  ck_assert_double_eq(result.matrix[1][2], 17.0);
  ck_assert_double_eq(result.matrix[1][3], 17.0);
  ck_assert_double_eq(result.matrix[2][0], 17.0);
  ck_assert_double_eq(result.matrix[2][1], 17.0);
  ck_assert_double_eq(result.matrix[2][2], 17.0);
  ck_assert_double_eq(result.matrix[2][3], 17.0);
  ck_assert_double_eq(result.matrix[3][0], 17.0);
  ck_assert_double_eq(result.matrix[3][1], 17.0);
  ck_assert_double_eq(result.matrix[3][2], 17.0);
  ck_assert_double_eq(result.matrix[3][3], 17.0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sum_matrix_6) {
  int res = 0;
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};

  s21_create_matrix(4, 2, &A);

  s21_create_matrix(4, 3, &B);

  res = s21_sum_matrix(&A, &B, &Z);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&Z);

  ck_assert_int_eq(res, S21_ERROR_CALC);
}
END_TEST

START_TEST(test_s21_sum_matrix_7) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;
  B.matrix[0][0] = 5.0;
  B.matrix[0][1] = 6.0;
  B.matrix[1][0] = 7.0;
  B.matrix[1][1] = 8.0;
  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_double_eq(result.matrix[0][0], 6.0);
  ck_assert_double_eq(result.matrix[0][1], 8.0);
  ck_assert_double_eq(result.matrix[1][0], 10.0);
  ck_assert_double_eq(result.matrix[1][1], 12.0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sum_matrix_8) {
  matrix_t A;
  int err_A = s21_create_matrix(1, 1, &A);

  int err_R = s21_sum_matrix(&A, NULL, NULL);

  ck_assert_int_eq(err_R, 1);
  if (!err_A) s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_sum_matrix_9) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_initialize_matrix(&A, 1, 1);
  s21_initialize_matrix(&B, 1, 1);
  B.matrix[3][3] = INFINITY;
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), S21_ERROR_CALC);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sum_matrix_10) {
  matrix_t A = {};
  matrix_t B = {};
  matrix_t result = {};
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(5, 5, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), S21_ERROR_CALC);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

//====================================================================//
//====================//  Subtraction  Matrix   //====================//
//====================================================================//

START_TEST(test_s21_sub_matrix_1) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  B.matrix[0][0] = 0.5;
  B.matrix[0][1] = 1.0;
  B.matrix[1][0] = 1.5;
  B.matrix[1][1] = 2.0;

  int status = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(status, S21_OK);
  ck_assert_double_eq(result.matrix[0][0], 0.5);
  ck_assert_double_eq(result.matrix[0][1], 1.0);
  ck_assert_double_eq(result.matrix[1][0], 1.5);
  ck_assert_double_eq(result.matrix[1][1], 2.0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix_2) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 5.0;
  A.matrix[0][1] = 6.0;
  A.matrix[1][0] = 7.0;
  A.matrix[1][1] = 8.0;

  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 4.0;

  int status = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(status, S21_OK);
  ck_assert_double_eq(result.matrix[0][0], 4.0);
  ck_assert_double_eq(result.matrix[0][1], 4.0);
  ck_assert_double_eq(result.matrix[1][0], 4.0);
  ck_assert_double_eq(result.matrix[1][1], 4.0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix_3) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = -2.0;
  A.matrix[1][0] = -3.0;
  A.matrix[1][1] = -4.0;

  B.matrix[0][0] = -5.0;
  B.matrix[0][1] = -6.0;
  B.matrix[1][0] = -7.0;
  B.matrix[1][1] = -8.0;

  int status = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(status, S21_OK);
  ck_assert_double_eq(result.matrix[0][0], 4.0);
  ck_assert_double_eq(result.matrix[0][1], 4.0);
  ck_assert_double_eq(result.matrix[1][0], 4.0);
  ck_assert_double_eq(result.matrix[1][1], 4.0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix_4) {
  matrix_t A, B, result;
  A.rows = 2;
  A.columns = 2;
  A.matrix = NULL;
  s21_create_matrix(2, 2, &B);

  int status = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(status, S21_INCORRECT_MATRIX);

  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sub_matrix_6) {
  matrix_t A, B, result;
  A.rows = 2;
  A.columns = 2;
  A.matrix = NULL;
  B.rows = 2;
  B.columns = 2;
  B.matrix = NULL;

  int status = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(status, S21_INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_s21_sub_matrix_7) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 3, &B);

  int status = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(status, S21_ERROR_CALC);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sub_matrix_8) {
  matrix_t A, B, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(2, 2, &B);

  int status = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(status, S21_ERROR_CALC);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_s21_sub_matrix_10) {
  matrix_t A, B, result;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);

  A.matrix[0][0] = DBL_MAX / 2;
  B.matrix[0][0] = -DBL_MAX / 2;

  int status = s21_sub_matrix(&A, &B, &result);

  ck_assert_int_eq(status, S21_OK);
  ck_assert_double_eq(result.matrix[0][0], DBL_MAX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

//====================================================================//
//====================//      Mult  Number      //====================//
//====================================================================//

START_TEST(test_s21_mult_number_2) {
  matrix_t A = {};
  matrix_t result = {};
  double number = INFINITY;
  s21_create_matrix(3, 3, &A);
  s21_initialize_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_mult_number(&A, number, &result), S21_ERROR_CALC);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_mult_number_3) {
  matrix_t A = {};
  matrix_t result = {};
  double number = 3;
  s21_create_matrix(3, 3, &A);
  s21_initialize_matrix(&A, 1, 1);
  A.matrix[2][2] = INFINITY;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), S21_ERROR_CALC);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number_4) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  double number = 3;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &eq_matrix);
  ck_assert_int_eq(s21_mult_number(&A, number, &result), S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(test_s21_mult_number_5) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  double number = 3;
  s21_create_matrix(3, 3, &A);
  s21_initialize_matrix(&A, 1, 1);
  s21_create_matrix(3, 3, &eq_matrix);
  s21_initialize_matrix(&eq_matrix, 3, 3);
  ck_assert_int_eq(s21_mult_number(&A, number, &result), S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(test_s21_mult_number_6) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  double number = 2;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 2;
  A.matrix[2][0] = 2, A.matrix[2][1] = 3, A.matrix[2][2] = 4;
  s21_create_matrix(3, 3, &eq_matrix);
  eq_matrix.matrix[0][0] = 2, eq_matrix.matrix[0][1] = 4,
  eq_matrix.matrix[0][2] = 6;
  eq_matrix.matrix[1][0] = 0, eq_matrix.matrix[1][1] = 8,
  eq_matrix.matrix[1][2] = 4;
  eq_matrix.matrix[2][0] = 4, eq_matrix.matrix[2][1] = 6,
  eq_matrix.matrix[2][2] = 8;
  ck_assert_int_eq(s21_mult_number(&A, number, &result), S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(test_s21_mult_number_7) {
  int err_R = s21_mult_number(NULL, -4, NULL);

  ck_assert_int_eq(err_R, 1);
}
END_TEST

START_TEST(test_s21_mult_number_1) {
  matrix_t A, result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;
  int code = s21_mult_number(&A, 2.0, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_double_eq(result.matrix[0][0], 2.0);
  ck_assert_double_eq(result.matrix[0][1], 4.0);
  ck_assert_double_eq(result.matrix[1][0], 6.0);
  ck_assert_double_eq(result.matrix[1][1], 8.0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number_8) {
  matrix_t A, result;
  A.rows = 2;
  A.columns = 2;
  A.matrix = NULL;

  int code = s21_mult_number(&A, 2.0, &result);

  ck_assert_int_eq(code, S21_INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_s21_mult_number_9) {
  matrix_t A, result;
  A.rows = 2;
  A.columns = 2;
  A.matrix = NULL;

  int code = s21_mult_number(&A, 0.0, &result);

  ck_assert_int_eq(code, S21_INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_s21_mult_number_10) {
  matrix_t A, result;
  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = 0.0;
  A.matrix[0][1] = 0.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 0.0;

  int code = s21_mult_number(&A, -5.0, &result);

  ck_assert_int_eq(code, S21_OK);
  ck_assert_double_eq(result.matrix[0][0], 0.0);
  ck_assert_double_eq(result.matrix[0][1], 0.0);
  ck_assert_double_eq(result.matrix[1][0], 0.0);
  ck_assert_double_eq(result.matrix[1][1], 0.0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST
//====================================================================//
//====================//       Mult Matrix      //====================//
//====================================================================//

START_TEST(test_s21_mult_matrix_1) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;
  B.matrix[0][0] = 2.0;
  B.matrix[0][1] = 0.0;
  B.matrix[1][0] = 1.0;
  B.matrix[1][1] = 2.0;
  int code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(code, S21_OK);
  ck_assert_double_eq(result.matrix[0][0], 4.0);
  ck_assert_double_eq(result.matrix[0][1], 4.0);
  ck_assert_double_eq(result.matrix[1][0], 10.0);
  ck_assert_double_eq(result.matrix[1][1], 8.0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_2) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 5.0;
  A.matrix[0][1] = 6.0;
  A.matrix[1][0] = 7.0;
  A.matrix[1][1] = 8.0;

  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 4.0;

  int code = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(code, S21_OK);
  ck_assert_double_eq(result.matrix[0][0], 23.0);
  ck_assert_double_eq(result.matrix[0][1], 34.0);
  ck_assert_double_eq(result.matrix[1][0], 31.0);
  ck_assert_double_eq(result.matrix[1][1], 46.0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_3) {
  matrix_t A, B, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;

  B.matrix[0][0] = 9.0;
  B.matrix[0][1] = 8.0;
  B.matrix[0][2] = 7.0;
  B.matrix[1][0] = 6.0;
  B.matrix[1][1] = 5.0;
  B.matrix[1][2] = 4.0;
  B.matrix[2][0] = 3.0;
  B.matrix[2][1] = 2.0;
  B.matrix[2][2] = 1.0;

  int code = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(code, S21_OK);
  ck_assert_double_eq(result.matrix[0][0], 30.0);
  ck_assert_double_eq(result.matrix[0][1], 24.0);
  ck_assert_double_eq(result.matrix[0][2], 18.0);
  ck_assert_double_eq(result.matrix[1][0], 84.0);
  ck_assert_double_eq(result.matrix[1][1], 69.0);
  ck_assert_double_eq(result.matrix[1][2], 54.0);
  ck_assert_double_eq(result.matrix[2][0], 138.0);
  ck_assert_double_eq(result.matrix[2][1], 114.0);
  ck_assert_double_eq(result.matrix[2][2], 90.0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_4) {
  matrix_t A, B, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 0.0;
  A.matrix[0][2] = 0.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 1.0;
  A.matrix[1][2] = 0.0;
  A.matrix[2][0] = 0.0;
  A.matrix[2][1] = 0.0;
  A.matrix[2][2] = 1.0;

  B.matrix[0][0] = 5.0;
  B.matrix[0][1] = 6.0;
  B.matrix[0][2] = 7.0;
  B.matrix[1][0] = 8.0;
  B.matrix[1][1] = 9.0;
  B.matrix[1][2] = 10.0;
  B.matrix[2][0] = 11.0;
  B.matrix[2][1] = 12.0;
  B.matrix[2][2] = 13.0;

  int code = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(code, S21_OK);
  ck_assert_double_eq(result.matrix[0][0], 5.0);
  ck_assert_double_eq(result.matrix[0][1], 6.0);
  ck_assert_double_eq(result.matrix[0][2], 7.0);
  ck_assert_double_eq(result.matrix[1][0], 8.0);
  ck_assert_double_eq(result.matrix[1][1], 9.0);
  ck_assert_double_eq(result.matrix[1][2], 10.0);
  ck_assert_double_eq(result.matrix[2][0], 11.0);
  ck_assert_double_eq(result.matrix[2][1], 12.0);
  ck_assert_double_eq(result.matrix[2][2], 13.0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_5) {
  matrix_t A, B, result;
  s21_create_matrix(4, 4, &A);
  s21_create_matrix(4, 4, &B);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[0][3] = 4.0;
  A.matrix[1][0] = 5.0;
  A.matrix[1][1] = 6.0;
  A.matrix[1][2] = 7.0;
  A.matrix[1][3] = 8.0;
  A.matrix[2][0] = 9.0;
  A.matrix[2][1] = 10.0;
  A.matrix[2][2] = 11.0;
  A.matrix[2][3] = 12.0;
  A.matrix[3][0] = 13.0;
  A.matrix[3][1] = 14.0;
  A.matrix[3][2] = 15.0;
  A.matrix[3][3] = 16.0;

  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 0.0;
  B.matrix[0][2] = 0.0;
  B.matrix[0][3] = 0.0;
  B.matrix[1][0] = 0.0;
  B.matrix[1][1] = 1.0;
  B.matrix[1][2] = 0.0;
  B.matrix[1][3] = 0.0;
  B.matrix[2][0] = 0.0;
  B.matrix[2][1] = 0.0;
  B.matrix[2][2] = 1.0;
  B.matrix[2][3] = 0.0;
  B.matrix[3][0] = 0.0;
  B.matrix[3][1] = 0.0;
  B.matrix[3][2] = 0.0;
  B.matrix[3][3] = 1.0;

  int code = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(code, S21_OK);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_double_eq(result.matrix[i][j], A.matrix[i][j]);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_6) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 0.0;
  A.matrix[0][1] = 1.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = 3.0;

  B.matrix[0][0] = 4.0;
  B.matrix[0][1] = 5.0;
  B.matrix[1][0] = 6.0;
  B.matrix[1][1] = 7.0;

  int code = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(code, S21_OK);
  ck_assert_double_eq(result.matrix[0][0], 6.0);
  ck_assert_double_eq(result.matrix[0][1], 7.0);
  ck_assert_double_eq(result.matrix[1][0], 26.0);
  ck_assert_double_eq(result.matrix[1][1], 31.0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_7) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 0.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = -1.0;

  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 4.0;

  int code = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(code, S21_OK);
  ck_assert_double_eq(result.matrix[0][0], -1.0);
  ck_assert_double_eq(result.matrix[0][1], -2.0);
  ck_assert_double_eq(result.matrix[1][0], -3.0);
  ck_assert_double_eq(result.matrix[1][1], -4.0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_8) {
  matrix_t A, B, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;

  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 0.0;
  B.matrix[0][2] = 0.0;
  B.matrix[1][0] = 0.0;
  B.matrix[1][1] = 1.0;
  B.matrix[1][2] = 0.0;
  B.matrix[2][0] = 0.0;
  B.matrix[2][1] = 0.0;
  B.matrix[2][2] = 1.0;

  int code = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(code, S21_OK);
  ck_assert_double_eq(result.matrix[0][0], 1.0);
  ck_assert_double_eq(result.matrix[0][1], 2.0);
  ck_assert_double_eq(result.matrix[0][2], 3.0);
  ck_assert_double_eq(result.matrix[1][0], 4.0);
  ck_assert_double_eq(result.matrix[1][1], 5.0);
  ck_assert_double_eq(result.matrix[1][2], 6.0);
  ck_assert_double_eq(result.matrix[2][0], 7.0);
  ck_assert_double_eq(result.matrix[2][1], 8.0);
  ck_assert_double_eq(result.matrix[2][2], 9.0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_9) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 0.0;
  A.matrix[0][1] = 0.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 0.0;

  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 4.0;

  int code = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(code, S21_OK);
  ck_assert_double_eq(result.matrix[0][0], 0.0);
  ck_assert_double_eq(result.matrix[0][1], 0.0);
  ck_assert_double_eq(result.matrix[1][0], 0.0);
  ck_assert_double_eq(result.matrix[1][1], 0.0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_matrix_10) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = -1.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 3.0;

  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 4.0;
  B.matrix[1][0] = -2.0;
  B.matrix[1][1] = 0.0;

  int code = s21_mult_matrix(&A, &B, &result);

  ck_assert_int_eq(code, S21_OK);
  ck_assert_double_eq(result.matrix[0][0], 4.0);
  ck_assert_double_eq(result.matrix[0][1], 8.0);
  ck_assert_double_eq(result.matrix[1][0], -6.0);
  ck_assert_double_eq(result.matrix[1][1], 0.0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

//====================================================================//
//====================//    Transpose Matrix    //====================//
//====================================================================//
START_TEST(test_s21_transpose_1) {
  matrix_t A, result;
  s21_create_matrix(2, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  int status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, S21_OK);
  ck_assert_int_eq(result.rows, 3);
  ck_assert_int_eq(result.columns, 2);
  ck_assert_double_eq(result.matrix[0][0], 1);
  ck_assert_double_eq(result.matrix[0][1], 4);
  ck_assert_double_eq(result.matrix[1][0], 2);
  ck_assert_double_eq(result.matrix[1][1], 5);
  ck_assert_double_eq(result.matrix[2][0], 3);
  ck_assert_double_eq(result.matrix[2][1], 6);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose_2) {
  matrix_t A, result;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;

  int status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, S21_INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_s21_transpose_3) {
  matrix_t A, result;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;

  int status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, S21_INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_s21_transpose_4) {
  matrix_t A, result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  int status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, S21_OK);
  ck_assert_int_eq(result.rows, 3);
  ck_assert_int_eq(result.columns, 3);
  ck_assert_double_eq(result.matrix[0][0], 1);
  ck_assert_double_eq(result.matrix[0][1], 4);
  ck_assert_double_eq(result.matrix[0][2], 7);
  ck_assert_double_eq(result.matrix[1][0], 2);
  ck_assert_double_eq(result.matrix[1][1], 5);
  ck_assert_double_eq(result.matrix[1][2], 8);
  ck_assert_double_eq(result.matrix[2][0], 3);
  ck_assert_double_eq(result.matrix[2][1], 6);
  ck_assert_double_eq(result.matrix[2][2], 9);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose_5) {
  matrix_t A, result;
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 6;

  int status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, S21_OK);
  ck_assert_int_eq(result.rows, 2);
  ck_assert_int_eq(result.columns, 3);
  ck_assert_double_eq(result.matrix[0][0], 1);
  ck_assert_double_eq(result.matrix[0][1], 3);
  ck_assert_double_eq(result.matrix[0][2], 5);
  ck_assert_double_eq(result.matrix[1][0], 2);
  ck_assert_double_eq(result.matrix[1][1], 4);
  ck_assert_double_eq(result.matrix[1][2], 6);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose_6) {
  matrix_t A, result;
  s21_create_matrix(2, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  int status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, S21_OK);
  ck_assert_int_eq(result.rows, 3);
  ck_assert_int_eq(result.columns, 2);
  ck_assert_double_eq(result.matrix[0][0], 1);
  ck_assert_double_eq(result.matrix[0][1], 4);
  ck_assert_double_eq(result.matrix[1][0], 2);
  ck_assert_double_eq(result.matrix[1][1], 5);
  ck_assert_double_eq(result.matrix[2][0], 3);
  ck_assert_double_eq(result.matrix[2][1], 6);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose_7) {
  matrix_t A, result;
  s21_create_matrix(1, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;

  int status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, S21_OK);
  ck_assert_int_eq(result.rows, 3);
  ck_assert_int_eq(result.columns, 1);
  ck_assert_double_eq(result.matrix[0][0], 1);
  ck_assert_double_eq(result.matrix[1][0], 2);
  ck_assert_double_eq(result.matrix[2][0], 3);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose_8) {
  matrix_t A, result;
  s21_create_matrix(3, 1, &A);
  A.matrix[0][0] = 1;
  A.matrix[1][0] = 2;
  A.matrix[2][0] = 3;

  int status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, S21_OK);
  ck_assert_int_eq(result.rows, 1);
  ck_assert_int_eq(result.columns, 3);
  ck_assert_double_eq(result.matrix[0][0], 1);
  ck_assert_double_eq(result.matrix[0][1], 2);
  ck_assert_double_eq(result.matrix[0][2], 3);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose_9) {
  matrix_t A, result;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 42;

  int status = s21_transpose(&A, &result);
  ck_assert_int_eq(status, S21_OK);
  ck_assert_int_eq(result.rows, 1);
  ck_assert_int_eq(result.columns, 1);
  ck_assert_double_eq(result.matrix[0][0], 42);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose_10) {
  matrix_t result;
  int status = s21_transpose(NULL, &result);
  ck_assert_int_eq(status, S21_INCORRECT_MATRIX);
}
END_TEST

//====================================================================//
//====================//    Calc Complements    //====================//
//====================================================================//
START_TEST(test_s21_calc_1) {
  matrix_t A = {};
  s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(s21_calc_complements(&A, NULL), S21_INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_calc_2) {
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(1, 1, &A);
  // s21_initialize_matrix(&A, 1, 3);
  A.matrix[0][0] = 1;
  ck_assert_int_eq(s21_calc_complements(&A, &result), S21_ERROR_CALC);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_calc_3) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &eq_matrix);
  A.matrix[0][0] = 1, A.matrix[0][1] = 2, A.matrix[0][2] = 3;
  A.matrix[1][0] = 0, A.matrix[1][1] = 4, A.matrix[1][2] = 2;
  A.matrix[2][0] = 5, A.matrix[2][1] = 2, A.matrix[2][2] = 1;
  ck_assert_int_eq(s21_calc_complements(&A, &result), S21_OK);
  eq_matrix.matrix[0][0] = 0.0 / (-40.0),
  eq_matrix.matrix[0][1] = 10.0 / (-40.0),
  eq_matrix.matrix[0][2] = -20.0 / (-40.0);
  eq_matrix.matrix[1][0] = 4.0 / (-40.0),
  eq_matrix.matrix[1][1] = -14.0 / (-40.0),
  eq_matrix.matrix[1][2] = 8.0 / (-40.0);
  eq_matrix.matrix[2][0] = -8.0 / (-40.0),
  eq_matrix.matrix[2][1] = -2.0 / (-40.0),
  eq_matrix.matrix[2][2] = 4.0 / (-40.0);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

START_TEST(test_s21_calc_4) {
  int err_R = s21_calc_complements(NULL, NULL);

  ck_assert_int_eq(err_R, 1);
}
END_TEST

//====================================================================//
//====================//   Matrix Determinant   //====================//
//====================================================================//
START_TEST(test_s21_determinant_1) {
  matrix_t A;
  double result;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 5;

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, S21_OK);
  ck_assert_double_eq_tol(result, 5, 1e-6);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_2) {
  matrix_t A;
  double result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, S21_OK);
  ck_assert_double_eq_tol(result, -2, 1e-6);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_3) {
  matrix_t A;
  double result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, S21_OK);
  ck_assert_double_eq_tol(result, 0, 1e-6);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_4) {
  matrix_t A;
  double result;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 2;
  A.matrix[0][3] = -1;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[1][3] = 5;
  A.matrix[2][0] = 2;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = 4;
  A.matrix[2][3] = -3;
  A.matrix[3][0] = 1;
  A.matrix[3][1] = 0;
  A.matrix[3][2] = 5;
  A.matrix[3][3] = 0;

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, S21_OK);
  ck_assert_double_eq_tol(result, 30, 1e-6);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_5) {
  matrix_t A;
  double result;
  A.rows = 0;
  A.columns = 0;
  A.matrix = NULL;

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, S21_INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_s21_determinant_6) {
  matrix_t A;
  double result;
  s21_create_matrix(2, 3, &A);

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, S21_ERROR_CALC);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_8) {
  matrix_t A;
  double result;
  s21_create_matrix(3, 3, &A);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 0;
    }
  }

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, S21_OK);
  ck_assert_double_eq_tol(result, 0, 1e-6);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_9) {
  matrix_t A;
  double result;
  s21_create_matrix(3, 3, &A);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = (i == j) ? 1 : 0;
    }
  }

  int status = s21_determinant(&A, &result);
  ck_assert_int_eq(status, S21_OK);
  ck_assert_double_eq_tol(result, 1, 1e-6);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_determinant_10) {
  matrix_t *A = NULL;
  double result;

  int status = s21_determinant(A, &result);
  ck_assert_int_eq(status, S21_INCORRECT_MATRIX);
}
END_TEST
//====================================================================//
//====================//     Inverse Matrix     //====================//
//====================================================================//

START_TEST(test_s21_inverse_matrix_1) {
  matrix_t A, result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  int status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, S21_ERROR_CALC);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_2) {
  matrix_t *A = NULL, result;
  int status = s21_inverse_matrix(A, &result);
  ck_assert_int_eq(status, S21_INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_s21_inverse_matrix_3) {
  matrix_t A, result;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 5;

  int status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, S21_OK);
  ck_assert_double_eq_tol(result.matrix[0][0], 0.2, 1e-6);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_inverse_matrix_4) {
  matrix_t A, result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 4;

  int status = s21_inverse_matrix(&A, &result);
  ck_assert_int_eq(status, S21_ERROR_CALC);

  s21_remove_matrix(&A);
}
END_TEST
START_TEST(test_s21_inverse_matrix_5) {
  matrix_t A = {};
  matrix_t result = {};
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), S21_INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_s21_inverse_matrix_6) {
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(3, 3, &A);
  s21_initialize_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), S21_ERROR_CALC);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_7) {
  matrix_t A = {};
  matrix_t result = {};
  s21_create_matrix(5, 3, &A);
  s21_initialize_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), S21_ERROR_CALC);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_s21_inverse_matrix_8) {
  matrix_t A = {};
  matrix_t result = {};
  matrix_t eq_matrix = {};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &eq_matrix);
  A.matrix[0][0] = 21;
  eq_matrix.matrix[0][0] = 1.0 / 21.0;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), S21_OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &eq_matrix), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&eq_matrix);
}
END_TEST

//====================================================================//
//====================//     Minor Matrix       //====================//
//====================================================================//

Suite *s21_matrix_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("s21_matrix");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_create_matrix_1);
  tcase_add_test(tc_core, test_s21_create_matrix_2);
  tcase_add_test(tc_core, test_s21_create_matrix_3);
  tcase_add_test(tc_core, test_s21_create_matrix_4);
  tcase_add_test(tc_core, test_s21_create_matrix_5);
  tcase_add_test(tc_core, test_s21_create_matrix_6);
  tcase_add_test(tc_core, test_s21_create_matrix_7);
  tcase_add_test(tc_core, test_s21_create_matrix_8);
  tcase_add_test(tc_core, test_s21_create_matrix_9);
  tcase_add_test(tc_core, test_s21_create_matrix_10);
  tcase_add_test(tc_core, test_s21_remove_matrix_1);
  tcase_add_test(tc_core, test_s21_remove_matrix_2);
  tcase_add_test(tc_core, test_s21_remove_matrix_3);
  tcase_add_test(tc_core, test_s21_remove_matrix_4);
  tcase_add_test(tc_core, test_s21_remove_matrix_5);
  tcase_add_test(tc_core, test_s21_eq_matrix_equal_1);
  tcase_add_test(tc_core, test_s21_eq_matrix_equal_2);
  tcase_add_test(tc_core, test_s21_eq_matrix_equal_3);
  tcase_add_test(tc_core, test_s21_eq_matrix_equal_4);
  tcase_add_test(tc_core, test_s21_eq_matrix_equal_5);
  tcase_add_test(tc_core, test_s21_eq_matrix_equal_6);
  tcase_add_test(tc_core, test_s21_eq_matrix_equal_7);
  tcase_add_test(tc_core, test_s21_eq_matrix_equal_8);
  tcase_add_test(tc_core, test_s21_eq_matrix_equal_9);
  tcase_add_test(tc_core, test_s21_eq_matrix_equal_10);
  tcase_add_test(tc_core, test_s21_sum_matrix_1);
  tcase_add_test(tc_core, test_s21_sum_matrix_2);
  tcase_add_test(tc_core, test_s21_sum_matrix_3);
  tcase_add_test(tc_core, test_s21_sum_matrix_4);
  tcase_add_test(tc_core, test_s21_sum_matrix_5);
  tcase_add_test(tc_core, test_s21_sum_matrix_6);
  tcase_add_test(tc_core, test_s21_sum_matrix_7);
  tcase_add_test(tc_core, test_s21_sum_matrix_8);
  tcase_add_test(tc_core, test_s21_sum_matrix_9);
  tcase_add_test(tc_core, test_s21_sum_matrix_10);
  tcase_add_test(tc_core, test_s21_sub_matrix_1);
  tcase_add_test(tc_core, test_s21_sub_matrix_2);
  tcase_add_test(tc_core, test_s21_sub_matrix_3);
  tcase_add_test(tc_core, test_s21_sub_matrix_4);
  tcase_add_test(tc_core, test_s21_sub_matrix_6);
  tcase_add_test(tc_core, test_s21_sub_matrix_7);
  tcase_add_test(tc_core, test_s21_sub_matrix_8);
  tcase_add_test(tc_core, test_s21_sub_matrix_10);
  tcase_add_test(tc_core, test_s21_mult_number_1);
  tcase_add_test(tc_core, test_s21_mult_number_2);
  tcase_add_test(tc_core, test_s21_mult_number_3);
  tcase_add_test(tc_core, test_s21_mult_number_4);
  tcase_add_test(tc_core, test_s21_mult_number_5);
  tcase_add_test(tc_core, test_s21_mult_number_6);
  tcase_add_test(tc_core, test_s21_mult_number_7);
  tcase_add_test(tc_core, test_s21_mult_number_8);
  tcase_add_test(tc_core, test_s21_mult_number_9);
  tcase_add_test(tc_core, test_s21_mult_number_10);
  tcase_add_test(tc_core, test_s21_mult_matrix_1);
  tcase_add_test(tc_core, test_s21_mult_matrix_2);
  tcase_add_test(tc_core, test_s21_mult_matrix_3);
  tcase_add_test(tc_core, test_s21_mult_matrix_4);
  tcase_add_test(tc_core, test_s21_mult_matrix_5);
  tcase_add_test(tc_core, test_s21_mult_matrix_6);
  tcase_add_test(tc_core, test_s21_mult_matrix_7);
  tcase_add_test(tc_core, test_s21_mult_matrix_8);
  tcase_add_test(tc_core, test_s21_mult_matrix_9);
  tcase_add_test(tc_core, test_s21_mult_matrix_10);
  tcase_add_test(tc_core, test_s21_transpose_1);
  tcase_add_test(tc_core, test_s21_transpose_2);
  tcase_add_test(tc_core, test_s21_transpose_3);
  tcase_add_test(tc_core, test_s21_transpose_4);
  tcase_add_test(tc_core, test_s21_transpose_5);
  tcase_add_test(tc_core, test_s21_transpose_6);
  tcase_add_test(tc_core, test_s21_transpose_7);
  tcase_add_test(tc_core, test_s21_transpose_8);
  tcase_add_test(tc_core, test_s21_transpose_9);
  tcase_add_test(tc_core, test_s21_transpose_10);
  tcase_add_test(tc_core, test_s21_calc_1);
  tcase_add_test(tc_core, test_s21_calc_2);
  tcase_add_test(tc_core, test_s21_calc_3);
  tcase_add_test(tc_core, test_s21_calc_4);
  tcase_add_test(tc_core, test_s21_determinant_1);
  tcase_add_test(tc_core, test_s21_determinant_2);
  tcase_add_test(tc_core, test_s21_determinant_3);
  tcase_add_test(tc_core, test_s21_determinant_4);
  tcase_add_test(tc_core, test_s21_determinant_5);
  tcase_add_test(tc_core, test_s21_determinant_6);
  tcase_add_test(tc_core, test_s21_determinant_8);
  tcase_add_test(tc_core, test_s21_determinant_9);
  tcase_add_test(tc_core, test_s21_determinant_10);
  tcase_add_test(tc_core, test_s21_inverse_matrix_1);
  tcase_add_test(tc_core, test_s21_inverse_matrix_2);
  tcase_add_test(tc_core, test_s21_inverse_matrix_3);
  tcase_add_test(tc_core, test_s21_inverse_matrix_4);
  tcase_add_test(tc_core, test_s21_inverse_matrix_5);
  tcase_add_test(tc_core, test_s21_inverse_matrix_6);
  tcase_add_test(tc_core, test_s21_inverse_matrix_7);
  tcase_add_test(tc_core, test_s21_inverse_matrix_8);

  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_matrix_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}