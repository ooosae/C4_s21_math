#include "s21_math_test.h"

START_TEST(test_exp_positive) {
  double x = 18.6;
  if (fabs((double)(exp(x) - s21_exp(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_exp_positive_less_than_one) {
  double x = 7.445e-29;
  if (fabs((double)(exp(x) - s21_exp(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_exp_negative) {
  double x = -13.544;
  if (fabs((double)(exp(x) - s21_exp(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_exp_negative_less_than_one) {
  double x = -0.646;
  if (fabs((double)(exp(x) - s21_exp(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_exp_zero) {
  double x = 0.0;
  if (fabs((double)(exp(x) - s21_exp(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_exp_nan) {
  double x = S21_NAN;
  if (fabs((double)(exp(x) - s21_exp(x))) > eps) ck_abort();
}
END_TEST

Suite *suite_exp(void) {
  Suite *s = suite_create("suite_exp");
  TCase *tc = tcase_create("exp_tc");

  tcase_add_test(tc, test_exp_positive);
  tcase_add_test(tc, test_exp_positive_less_than_one);
  tcase_add_test(tc, test_exp_negative);
  tcase_add_test(tc, test_exp_negative_less_than_one);
  tcase_add_test(tc, test_exp_zero);
  tcase_add_test(tc, test_exp_nan);

  suite_add_tcase(s, tc);
  return s;
}
