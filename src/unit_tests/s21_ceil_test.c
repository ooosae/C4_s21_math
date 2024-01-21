#include "s21_math_test.h"

START_TEST(ceil_test1) {
  double x = 1.0;
  if (fabs((double)(ceil(x) - s21_ceil(x))) > eps) ck_abort();
}
END_TEST

START_TEST(ceil_test2) {
  double x = 0.0;
  if (fabs((double)(ceil(x) - s21_ceil(x))) > eps) ck_abort();
}
END_TEST

START_TEST(ceil_test6) {
  if (fabs((double)(s21_ceil(S21_NAN) - NAN)) > eps) ck_abort();
}
END_TEST

START_TEST(ceil_test7) {
  double x = 4.7;
  if (fabs((double)(ceil(x) - s21_ceil(x))) > eps) ck_abort();
}
END_TEST

START_TEST(ceil_test8) {
  double x = 4.7329936467890765;
  if (fabs((double)(ceil(x) - s21_ceil(x))) > eps) ck_abort();
}
END_TEST

START_TEST(ceil_test9) {
  double x = 455039688.5;
  if (fabs((double)(ceil(x) - s21_ceil(x))) > eps) ck_abort();
}
END_TEST

START_TEST(ceil_test10) {
  double x = -4.8888888867890765;
  if (fabs((double)(ceil(x) - s21_ceil(x))) > eps) ck_abort();
}
END_TEST

START_TEST(ceil_test11) {
  double x = -47777777.5;
  if (fabs((double)(ceil(x) - s21_ceil(x))) > eps) ck_abort();
}
END_TEST

Suite *suite_ceil(void) {
  Suite *s = suite_create("suite_ceil");
  TCase *tc = tcase_create("ceil_tc");

  tcase_add_test(tc, ceil_test1);
  tcase_add_test(tc, ceil_test2);
  tcase_add_test(tc, ceil_test6);
  tcase_add_test(tc, ceil_test7);
  tcase_add_test(tc, ceil_test8);
  tcase_add_test(tc, ceil_test9);
  tcase_add_test(tc, ceil_test10);
  tcase_add_test(tc, ceil_test11);

  suite_add_tcase(s, tc);
  return s;
}
