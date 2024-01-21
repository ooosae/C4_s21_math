#include "s21_math_test.h"

START_TEST(test_sin_small_positive) {
  double x = 2.233243;
  if (fabs((double)(sin(x) - s21_sin(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_sin_small_negative) {
  double x = -2.234234;
  if (fabs((double)(sin(x) - s21_sin(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_sin_huge_positive) {
  double x = 345453543;
  if (fabs((double)(sin(x) - s21_sin(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_sin_huge_negative) {
  double x = -2345345232;
  if (fabs((double)(sin(x) - s21_sin(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_sin_zero) {
  double x = 0;
  if (fabs((double)(sin(x) - s21_sin(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_sin_neg_zero) {
  double x = -0.0;
  if (fabs((double)(sin(x) - s21_sin(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_sin_nan) {
  if (fabs((double)(s21_sin(S21_NAN) - NAN)) > eps) ck_abort();
}
END_TEST

START_TEST(test_sin_big_mantissa) {
  double x = 0.1234567889;
  if (fabs((double)(sin(x) - s21_sin(x))) > eps) ck_abort();
}
END_TEST

Suite *suite_sin(void) {
  Suite *s = suite_create("suite_sin");
  TCase *tc = tcase_create("sin_tc");

  tcase_add_test(tc, test_sin_small_positive);
  tcase_add_test(tc, test_sin_small_negative);
  tcase_add_test(tc, test_sin_huge_positive);
  tcase_add_test(tc, test_sin_huge_negative);
  tcase_add_test(tc, test_sin_zero);
  tcase_add_test(tc, test_sin_neg_zero);
  tcase_add_test(tc, test_sin_nan);
  tcase_add_test(tc, test_sin_big_mantissa);

  suite_add_tcase(s, tc);
  return s;
}
