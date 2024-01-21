#include "s21_math_test.h"

START_TEST(fmod_test1) {
  double x = 12.0;
  double y = 3.0;
  if (fabs((double)(fmod(x, y) - s21_fmod(x, y))) > eps) ck_abort();
}
END_TEST

START_TEST(fmod_test2) {
  double x = 0.0;
  double y = 2.5;
  if (fabs((double)(fmod(x, y) - s21_fmod(x, y))) > eps) ck_abort();
}
END_TEST

START_TEST(fmod_test5) {
  double x = 3.7;
  double y = 0.0;
  if (fabs((double)(fmod(x, y) - s21_fmod(x, y))) > eps) ck_abort();
}
END_TEST

START_TEST(fmod_test6) {
  double x = -3.3;
  double y = 2.0;
  if (fabs((double)(fmod(x, y) - s21_fmod(x, y))) > eps) ck_abort();
}
END_TEST

START_TEST(fmod_test7) {
  double x = -12.0;
  double y = 3.0;
  if (fabs((double)(fmod(x, y) - s21_fmod(x, y))) > eps) ck_abort();
}
END_TEST

START_TEST(fmod_test8) {
  double x = 12.0;
  double y = -3.0;
  if (fabs((double)(fmod(x, y) - s21_fmod(x, y))) > eps) ck_abort();
}
END_TEST

START_TEST(fmod_test11) {
  double x = -12.0;
  double y = -3.0;
  if (fabs((double)(fmod(x, y) - s21_fmod(x, y))) > eps) ck_abort();
}
END_TEST

START_TEST(fmod_test4) {
  double x = -3.3;
  double y = -2.0;
  if (fabs((double)(fmod(x, y) - s21_fmod(x, y))) > eps) ck_abort();
}
END_TEST

START_TEST(fmod_test3) {
  double x = 3.3;
  double y = -2.0;
  if (fabs((double)(fmod(x, y) - s21_fmod(x, y))) > eps) ck_abort();
}
END_TEST

START_TEST(fmod_test9) {
  double x = S21_NAN;
  double y = 12.8;
  if (fabs((double)(s21_fmod(x, y) - NAN)) > eps) ck_abort();
}
END_TEST

START_TEST(fmod_test10) {
  double x = 5.5;
  double y = S21_NAN;
  if (fabs((double)(s21_fmod(x, y) - NAN)) > eps) ck_abort();
}
END_TEST

START_TEST(fmod_test12) {
  double x = 12;
  double y = 0;
  if (fabs((double)(fmod(x, y) - s21_fmod(x, y))) > eps) ck_abort();
}
END_TEST

START_TEST(fmod_test13) {
  double x = 1;
  double y = 1e-10;
  if (fabs((double)(fmod(x, y) - s21_fmod(x, y))) > eps) ck_abort();
}
END_TEST

START_TEST(fmod_test14) {
  double x = 2;
  double y = 0.3;
  if (fabs((double)(s21_fmod(x, y) - fmod(x, y))) > eps) ck_abort();
}
END_TEST

START_TEST(fmod_test16) {
  double x = 13;
  double y = 0.5;
  if (fabs((double)(fmod(x, y) - s21_fmod(x, y))) > eps) ck_abort();
}
END_TEST

START_TEST(fmod_test15) {
  double x = 0;
  double y = 0;
  if (fabs((double)(fmod(x, y) - s21_fmod(x, y))) > eps) ck_abort();
}
END_TEST

START_TEST(fmod_test17) {
  double x = -0.5;
  double y = 2;
  if (fabs((double)(fmod(x, y) - s21_fmod(x, y))) > eps) ck_abort();
}
END_TEST

START_TEST(fmod_test18) {
  double x = 0.3;
  double y = 2;
  if (fabs((double)(fmod(x, y) - s21_fmod(x, y))) > eps) ck_abort();
}
END_TEST

START_TEST(fmod_test19) {
  double x = 0.3;
  double y = 0.1;
  if (fabs((double)(fmod(x, y) - s21_fmod(x, y))) > eps) ck_abort();
}
END_TEST

START_TEST(fmod_test20) {
  double x = -0.3;
  double y = 0.1;
  if (fabs((double)(fmod(x, y) - s21_fmod(x, y))) > eps) ck_abort();
}
END_TEST

START_TEST(fmod_test21) {
  double x = 0.3;
  double y = -0.1;
  if (fabs((double)(fmod(x, y) - s21_fmod(x, y))) > eps) ck_abort();
}
END_TEST

START_TEST(fmod_test22) {
  double x = -0.3;
  double y = -0.1;
  if (fabs((double)(fmod(x, y) - s21_fmod(x, y))) > eps) ck_abort();
}
END_TEST

START_TEST(fmod_test23) {
  double x = 0.1;
  double y = 0.3;
  if (fabs((double)(fmod(x, y) - s21_fmod(x, y))) > eps) ck_abort();
}
END_TEST

START_TEST(fmod_test24) {
  double x = -0.1;
  double y = 0.3;
  if (fabs((double)(fmod(x, y) - s21_fmod(x, y))) > eps) ck_abort();
}
END_TEST

START_TEST(fmod_test25) {
  double x = 0.1;
  double y = -0.3;
  if (fabs((double)(fmod(x, y) - s21_fmod(x, y))) > eps) ck_abort();
}
END_TEST

START_TEST(fmod_test26) {
  double x = -0.1;
  double y = -0.3;
  if (fabs((double)(fmod(x, y) - s21_fmod(x, y))) > eps) ck_abort();
}
END_TEST

Suite *suite_fmod(void) {
  Suite *s = suite_create("suite_fmod");
  TCase *tc = tcase_create("fmod_tc");

  tcase_add_test(tc, fmod_test1);
  tcase_add_test(tc, fmod_test2);
  tcase_add_test(tc, fmod_test3);
  tcase_add_test(tc, fmod_test4);
  tcase_add_test(tc, fmod_test5);
  tcase_add_test(tc, fmod_test6);
  tcase_add_test(tc, fmod_test7);
  tcase_add_test(tc, fmod_test8);
  tcase_add_test(tc, fmod_test9);
  tcase_add_test(tc, fmod_test10);
  tcase_add_test(tc, fmod_test11);
  tcase_add_test(tc, fmod_test12);
  tcase_add_test(tc, fmod_test13);
  tcase_add_test(tc, fmod_test14);
  tcase_add_test(tc, fmod_test15);
  tcase_add_test(tc, fmod_test16);
  tcase_add_test(tc, fmod_test17);
  tcase_add_test(tc, fmod_test18);
  tcase_add_test(tc, fmod_test19);
  tcase_add_test(tc, fmod_test20);
  tcase_add_test(tc, fmod_test21);
  tcase_add_test(tc, fmod_test22);
  tcase_add_test(tc, fmod_test23);
  tcase_add_test(tc, fmod_test24);
  tcase_add_test(tc, fmod_test25);
  tcase_add_test(tc, fmod_test26);

  suite_add_tcase(s, tc);
  return s;
}
