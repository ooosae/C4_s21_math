#include "s21_math_test.h"

START_TEST(test_tan_positive) {
  double x = 0.4;
  if (fabs((double)(tan(x) - s21_tan(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_tan_negative) {
  double x = -0.4;
  if (fabs((double)(tan(x) - s21_tan(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_tan_zero) {
  double x = 0;
  if (fabs((double)(tan(x) - s21_tan(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_tan_neg_zero) {
  double x = -0.0;
  if (fabs((double)(tan(x) - s21_tan(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_tan_one) {
  double x = 1;
  if (fabs((double)(tan(x) - s21_tan(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_tan_one_negative) {
  double x = -1;
  if (fabs((double)(tan(x) - s21_tan(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_tan_huge_positive) {
  double x = 34542352.23;
  if (fabs((double)(tan(x) - s21_tan(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_tan_huge_negative) {
  double x = -433452354.23;
  if (fabs((double)(tan(x) - s21_tan(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_tan_big_mantissa) {
  double x = 0.123456702439789420789540789525;
  if (fabs((double)(tan(x) - s21_tan(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_tan_two_pi) {
  double x = S21_PI;
  if (fabs((double)(tan(x) - s21_tan(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_tan_eps_positive) {
  double x = 1 + 1e-6;
  if (fabs((double)(tan(x) - s21_tan(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_tan_eps_negative) {
  double x = -1 - 1e-6;
  if (fabs((double)(tan(x) - s21_tan(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_tan_nan) {
  if (fabs((double)(s21_tan(S21_NAN) - NAN)) > eps) ck_abort();
}
END_TEST

Suite *suite_tan(void) {
  Suite *s = suite_create("suite_tan");
  TCase *tc = tcase_create("tan_tc");

  tcase_add_test(tc, test_tan_positive);
  tcase_add_test(tc, test_tan_negative);
  tcase_add_test(tc, test_tan_zero);
  tcase_add_test(tc, test_tan_neg_zero);
  tcase_add_test(tc, test_tan_one);
  tcase_add_test(tc, test_tan_negative);
  tcase_add_test(tc, test_tan_one_negative);
  tcase_add_test(tc, test_tan_huge_positive);
  tcase_add_test(tc, test_tan_huge_negative);
  tcase_add_test(tc, test_tan_big_mantissa);
  tcase_add_test(tc, test_tan_eps_positive);
  tcase_add_test(tc, test_tan_eps_negative);
  tcase_add_test(tc, test_tan_nan);
  tcase_add_test(tc, test_tan_two_pi);

  suite_add_tcase(s, tc);
  return s;
}
