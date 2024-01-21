#include "s21_math_test.h"

START_TEST(test_pos) {
  double x = 200;
  if (fabs((double)(log(x) - s21_log(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_small_pos) {
  double x = 4.3234323e-43;
  if (fabs((double)(log(x) - s21_log(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_neg) {
  double x = -3432.12;
  if (fabs((double)(log(x) - s21_log(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_one) {
  double x = 1;
  if (fabs((double)(log(x) - s21_log(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_nan_pos) {
  if (fabs((double)(s21_log(S21_NAN) - NAN)) > eps) ck_abort();
}
END_TEST

Suite *suite_log(void) {
  Suite *s = suite_create("suite_log");
  TCase *tc = tcase_create("log_tc");
  tcase_add_test(tc, test_pos);
  tcase_add_test(tc, test_small_pos);
  tcase_add_test(tc, test_neg);
  tcase_add_test(tc, test_one);
  tcase_add_test(tc, test_nan_pos);

  suite_add_tcase(s, tc);
  return s;
}
