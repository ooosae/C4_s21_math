#include "s21_math_test.h"

START_TEST(test_asin_positive) {
  double x = 0.4;
  if (fabs((double)(asin(x) - s21_asin(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_asin_positive2) {
  double x = 0.8;
  if (fabs((double)(asin(x) - s21_asin(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_asin_negative) {
  double x = -0.4;
  if (fabs((double)(asin(x) - s21_asin(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_asin_negative2) {
  double x = -0.8;
  if (fabs((double)(asin(x) - s21_asin(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_asin_zero) {
  double x = 0.0;
  if (fabs((double)(asin(x) - s21_asin(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_asin_out_of_range_positive) {
  double x = 1.1;
  if (fabs((double)(s21_asin(x) - NAN)) > eps) ck_abort();
}
END_TEST

START_TEST(test_asin_out_of_range_negative) {
  double x = -1.1;
  if (fabs((double)(s21_asin(x) - NAN)) > eps) ck_abort();
}
END_TEST

START_TEST(test_asin_nan) {
  if (fabs((double)(s21_sin(S21_NAN) - NAN)) > eps) ck_abort();
}
END_TEST

Suite *suite_asin(void) {
  Suite *s = suite_create("suite_asin");
  TCase *tc = tcase_create("asin_tc");

  tcase_add_test(tc, test_asin_positive);
  tcase_add_test(tc, test_asin_positive2);
  tcase_add_test(tc, test_asin_negative);
  tcase_add_test(tc, test_asin_negative2);
  tcase_add_test(tc, test_asin_zero);
  tcase_add_test(tc, test_asin_out_of_range_positive);
  tcase_add_test(tc, test_asin_out_of_range_negative);
  tcase_add_test(tc, test_asin_nan);

  suite_add_tcase(s, tc);
  return s;
}
