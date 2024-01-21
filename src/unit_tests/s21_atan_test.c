#include "s21_math_test.h"

START_TEST(test_atan_positive) {
  double x = 0.4;
  if (fabs((double)(atan(x) - s21_atan(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_atan_negative) {
  double x = -0.4;
  if (fabs((double)(atan(x) - s21_atan(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_atan_zero) {
  double x = 0;
  if (fabs((double)(atan(x) - s21_atan(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_atan_one) {
  double x = -0.0;
  if (fabs((double)(atan(x) - s21_atan(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_atan_one_negative) {
  double x = -1;
  if (fabs((double)(atan(x) - s21_atan(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_atan_huge_positive) {
  double x = 100000000.0;
  if (fabs((double)(atan(x) - s21_atan(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_atan_huge_negative) {
  double x = -10000000000;
  if (fabs((double)(atan(x) - s21_atan(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_atan_big_mantissa) {
  double x = 0.123456702439789420789540789525;
  if (fabs((double)(atan(x) - s21_atan(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_atan_nan) {
  double x = S21_NAN;
  if (s21_atan(x) - NAN < eps) ck_abort();
}
END_TEST

Suite *suite_atan(void) {
  Suite *s = suite_create("suite_atan");
  TCase *tc = tcase_create("atan_tc");

  tcase_add_test(tc, test_atan_positive);
  tcase_add_test(tc, test_atan_negative);
  tcase_add_test(tc, test_atan_zero);
  tcase_add_test(tc, test_atan_one);
  tcase_add_test(tc, test_atan_negative);
  tcase_add_test(tc, test_atan_one_negative);
  tcase_add_test(tc, test_atan_huge_positive);
  tcase_add_test(tc, test_atan_huge_negative);
  tcase_add_test(tc, test_atan_big_mantissa);
  tcase_add_test(tc, test_atan_nan);

  suite_add_tcase(s, tc);
  return s;
}
