#include "s21_math_test.h"

START_TEST(fabs_test_pos) {
  double x = -1.0;
  if (fabs((double)(fabs(x) - s21_fabs(x))) > eps) ck_abort();
}
END_TEST

START_TEST(fabs_test_neg) {
  double x = -1.000001;
  if (fabs((double)(fabs(x) - s21_fabs(x))) > eps) ck_abort();
}
END_TEST

START_TEST(fabs_test_zero) {
  double x = 0.0;
  if (fabs((double)(fabs(x) - s21_fabs(x))) > eps) ck_abort();
}
END_TEST

START_TEST(fabs_test_zero_2) {
  double x = 1e-10;
  if (fabs((double)(fabs(x) - s21_fabs(x))) > eps) ck_abort();
}
END_TEST

START_TEST(fabs_test_zero_3) {
  double x = 1e-5;
  if (fabs((double)(fabs(x) - s21_fabs(x))) > eps) ck_abort();
}
END_TEST

START_TEST(fabs_test_negzero) {
  double x = -0.0;
  if (fabs((double)(fabs(x) - s21_fabs(x))) > eps) ck_abort();
}
END_TEST

START_TEST(fabs_test_nan) {
  double x = S21_NAN;
  if (fabs((double)(fabs(x) - s21_fabs(x))) > eps) ck_abort();
}
END_TEST

START_TEST(fabs_test_large_pos) {
  double x = 1000.011;
  if (fabs((double)(fabs(x) - s21_fabs(x))) > eps) ck_abort();
}
END_TEST

START_TEST(fabs_test_large_neg) {
  double x = -1000.011;
  if (fabs((double)(fabs(x) - s21_fabs(x))) > eps) ck_abort();
}
END_TEST

Suite *suite_fabs(void) {
  Suite *s = suite_create("suite_fabs");
  TCase *tc = tcase_create("fabs_tc");

  tcase_add_test(tc, fabs_test_pos);
  tcase_add_test(tc, fabs_test_neg);
  tcase_add_test(tc, fabs_test_zero);
  tcase_add_test(tc, fabs_test_zero_2);
  tcase_add_test(tc, fabs_test_zero_3);
  tcase_add_test(tc, fabs_test_negzero);
  tcase_add_test(tc, fabs_test_nan);
  tcase_add_test(tc, fabs_test_large_pos);
  tcase_add_test(tc, fabs_test_large_neg);

  suite_add_tcase(s, tc);
  return s;
}
