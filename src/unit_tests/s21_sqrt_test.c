#include "s21_math_test.h"

START_TEST(sqrt_test1) {
  double x = 1;
  if (fabs((double)(sqrt(x) - s21_sqrt(x))) > eps) ck_abort();
}
END_TEST

START_TEST(sqrt_test2) {
  double x = 0.123456789;
  if (fabs((double)(sqrt(x) - s21_sqrt(x))) > eps) ck_abort();
}
END_TEST

START_TEST(sqrt_test3) {
  double x = 0.0;
  if (fabs((double)(sqrt(x) - s21_sqrt(x))) > eps) ck_abort();
}
END_TEST

START_TEST(sqrt_test5) {
  double x = 987565.9111111213656;
  if (fabs((double)(sqrt(x) - s21_sqrt(x))) > eps) ck_abort();
}
END_TEST

START_TEST(sqrt_test6) {
  double x = S21_PI / 3;
  if (fabs((double)(sqrt(x) - s21_sqrt(x))) > eps) ck_abort();
}
END_TEST

START_TEST(sqrt_test7) {
  double x = S21_PI / 6;
  if (fabs((double)(sqrt(x) - s21_sqrt(x))) > eps) ck_abort();
}
END_TEST

START_TEST(sqrt_test8) {
  double x = S21_PI / 2;
  if (fabs((double)(sqrt(x) - s21_sqrt(x))) > eps) ck_abort();
}
END_TEST

START_TEST(sqrt_test9) {
  double x = 2 * S21_PI / 3;
  if (fabs((double)(sqrt(x) - s21_sqrt(x))) > eps) ck_abort();
}
END_TEST

START_TEST(sqrt_test10) {
  double x = 5 * S21_PI / 6;
  if (fabs((double)(sqrt(x) - s21_sqrt(x))) > eps) ck_abort();
}
END_TEST

START_TEST(sqrt_test11) {
  double x = S21_PI;
  if (fabs((double)(sqrt(x) - s21_sqrt(x))) > eps) ck_abort();
}
END_TEST

START_TEST(sqrt_test12) {
  double x = -1.2312312367;
  if (fabs((double)(sqrt(x) - s21_sqrt(x))) > eps) ck_abort();
}
END_TEST

START_TEST(sqrt_test13) {
  double x = 64.;
  if (fabs((double)(sqrt(x) - s21_sqrt(x))) > eps) ck_abort();
}
END_TEST

START_TEST(sqrt_test14) {
  double x = 122223456789;
  if (fabs((double)(sqrt(x) - s21_sqrt(x))) > eps) ck_abort();
}
END_TEST

START_TEST(sqrt_test16) {
  double x = 4.12135e-31;
  if (fabs((double)(sqrt(x) - s21_sqrt(x))) > eps) ck_abort();
}
END_TEST

START_TEST(sqrt_test18) {
  double x = -121.1;
  if (fabs((double)(sqrt(x) - s21_sqrt(x))) > eps) ck_abort();
}
END_TEST

START_TEST(sqrt_test19) {
  double x = -2.8119;
  if (fabs((double)(sqrt(x) - s21_sqrt(x))) > eps) ck_abort();
}
END_TEST

START_TEST(sqrt_test20) {
  if (fabs((double)(s21_sqrt(S21_NAN) - NAN)) > eps) ck_abort();
}
END_TEST

Suite *suite_sqrt(void) {
  Suite *s = suite_create("suite_sqrt");
  TCase *tc = tcase_create("sqrt_tc");

  tcase_add_test(tc, sqrt_test1);
  tcase_add_test(tc, sqrt_test2);
  tcase_add_test(tc, sqrt_test3);
  tcase_add_test(tc, sqrt_test5);
  tcase_add_test(tc, sqrt_test6);
  tcase_add_test(tc, sqrt_test7);
  tcase_add_test(tc, sqrt_test8);
  tcase_add_test(tc, sqrt_test9);
  tcase_add_test(tc, sqrt_test10);
  tcase_add_test(tc, sqrt_test11);
  tcase_add_test(tc, sqrt_test12);
  tcase_add_test(tc, sqrt_test13);
  tcase_add_test(tc, sqrt_test14);
  tcase_add_test(tc, sqrt_test16);
  tcase_add_test(tc, sqrt_test18);
  tcase_add_test(tc, sqrt_test19);
  tcase_add_test(tc, sqrt_test20);

  suite_add_tcase(s, tc);
  return s;
}
