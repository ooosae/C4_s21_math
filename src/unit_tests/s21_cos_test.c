#include "s21_math_test.h"

START_TEST(test_cos_positive) {
  double x = 0.4;
  if (fabs((double)(cos(x) - s21_cos(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_cos_negative) {
  double x = -0.4;
  if (fabs((double)(cos(x) - s21_cos(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_cos_zero) {
  double x = 0;
  if (fabs((double)(cos(x) - s21_cos(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_cos_one) {
  double x = 1;
  if (fabs((double)(cos(x) - s21_cos(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_cos_one_negative) {
  double x = -1;
  if (fabs((double)(cos(x) - s21_cos(x))) > eps) ck_abort();
  ;
}
END_TEST

START_TEST(test_cos_huge_positive) {
  double x = 777666986;
  if (fabs((double)(cos(x) - s21_cos(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_cos_huge_negative) {
  double x = -6667779234;
  if (fabs((double)(cos(x) - s21_cos(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_cos_big_mantissa) {
  double x = 0.123456702439789420789540789525;
  if (fabs((double)(cos(x) - s21_cos(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_cos_two_pi) {
  double x = 2 * S21_PI;
  if (fabs((double)(cos(x) - s21_cos(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_cos_eps_positive) {
  double x = 1 + 1e-6;
  if (fabs((double)(cos(x) - s21_cos(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_cos_eps_negative) {
  double x = -1 - 1e-6;
  if (fabs((double)(cos(x) - s21_cos(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_cos_nan) {
  if (fabs((double)(s21_cos(S21_NAN) - NAN)) > eps) ck_abort();
}
END_TEST

Suite *suite_cos(void) {
  Suite *s = suite_create("suite_cos");
  TCase *tc = tcase_create("cos_tc");

  tcase_add_test(tc, test_cos_positive);
  tcase_add_test(tc, test_cos_negative);
  tcase_add_test(tc, test_cos_zero);
  tcase_add_test(tc, test_cos_one);
  tcase_add_test(tc, test_cos_one_negative);
  tcase_add_test(tc, test_cos_huge_positive);
  tcase_add_test(tc, test_cos_huge_negative);
  tcase_add_test(tc, test_cos_big_mantissa);
  tcase_add_test(tc, test_cos_two_pi);
  tcase_add_test(tc, test_cos_eps_positive);
  tcase_add_test(tc, test_cos_eps_negative);
  tcase_add_test(tc, test_cos_nan);

  suite_add_tcase(s, tc);
  return s;
}
