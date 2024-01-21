#include "s21_math_test.h"

START_TEST(floor_test1) {
  double x = 1.0;
  if (fabs((double)(floor(x) - s21_floor(x))) > eps) ck_abort();
}
END_TEST

START_TEST(floor_test2) {
  double x = 0.0;
  if (fabs((double)(floor(x) - s21_floor(x))) > eps) ck_abort();
}
END_TEST

START_TEST(floor_test3) {
  double x = -0.0;
  if (fabs((double)(floor(x) - s21_floor(x))) > eps) ck_abort();
}
END_TEST

START_TEST(floor_test6) {
  if (fabs((double)(s21_floor(S21_NAN) - NAN)) > eps) ck_abort();
}
END_TEST

START_TEST(floor_test7) {
  double x = -4.7;
  if (fabs((double)(floor(x) - s21_floor(x))) > eps) ck_abort();
}
END_TEST

START_TEST(floor_test8) {
  double x = 4.3453456789404921;
  if (fabs((double)(floor(x) - s21_floor(x))) > eps) ck_abort();
}
END_TEST

START_TEST(floor_test9) {
  double x = 43453456.1;
  if (fabs((double)(floor(x) - s21_floor(x))) > eps) ck_abort();
}
END_TEST

START_TEST(floor_test10) {
  double x = -4.3453456;
  if (fabs((double)(floor(x) - s21_floor(x))) > eps) ck_abort();
}
END_TEST

START_TEST(floor_test11) {
  double x = -43453456.1;
  if (fabs((double)(floor(x) - s21_floor(x))) > eps) ck_abort();
}
END_TEST

START_TEST(floor_test12) {
  double x = -3.9999999999999999999;
  if (fabs((double)(floor(x) - s21_floor(x))) > eps) ck_abort();
}
END_TEST

START_TEST(floor_test13) {
  double x = 0.9999999999999999999;
  if (fabs((double)(floor(x) - s21_floor(x))) > eps) ck_abort();
}
END_TEST

START_TEST(floor_test14) {
  double x = 2.9999999999999999999;
  if (fabs((double)(floor(x) - s21_floor(x))) > eps) ck_abort();
}
END_TEST

Suite *suite_floor(void) {
  Suite *s = suite_create("suite_floor");
  TCase *tc = tcase_create("floor_tc");

  tcase_add_test(tc, floor_test1);
  tcase_add_test(tc, floor_test2);
  tcase_add_test(tc, floor_test3);
  tcase_add_test(tc, floor_test6);
  tcase_add_test(tc, floor_test7);
  tcase_add_test(tc, floor_test8);
  tcase_add_test(tc, floor_test9);
  tcase_add_test(tc, floor_test10);
  tcase_add_test(tc, floor_test11);
  tcase_add_test(tc, floor_test12);
  tcase_add_test(tc, floor_test13);
  tcase_add_test(tc, floor_test14);

  suite_add_tcase(s, tc);
  return s;
}
