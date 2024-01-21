#include "s21_math_test.h"

#define EPS 1e-6

START_TEST(test_pos) {
  double x = 0.999;
  if (fabs((double)(acos(x) - s21_acos(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_pos2) {
  double x = 1;
  if (fabs((double)(acos(x) - s21_acos(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_pos3) {
  double x = 0.5;
  if (fabs((double)(acos(x) - s21_acos(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_pos4) {
  double x = 0;
  if (fabs((double)(acos(x) - s21_acos(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_neg) {
  double x = -0.001;
  if (fabs((double)(acos(x) - s21_acos(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_neg2) {
  double x = -0.9999;
  if (fabs((double)(acos(x) - s21_acos(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_neg3) {
  double x = -0.5;
  if (fabs((double)(acos(x) - s21_acos(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_nul) {
  double x = 1.001;
  if (fabs((double)(s21_acos(x) - NAN)) > eps) ck_abort();
}
END_TEST

START_TEST(test_nul2) {
  double x = -1.1;
  if (fabs((double)(acos(x) - s21_acos(x))) > eps) ck_abort();
}
END_TEST

START_TEST(test_nul3) {
  if (fabs((double)(s21_acos(S21_NAN) - NAN)) > eps) ck_abort();
}
END_TEST

Suite *suite_acos(void) {
  Suite *s = suite_create("suite_acos");
  TCase *tc = tcase_create("acos_tc");

  tcase_add_test(tc, test_pos);
  tcase_add_test(tc, test_pos2);
  tcase_add_test(tc, test_pos3);
  tcase_add_test(tc, test_pos4);
  tcase_add_test(tc, test_neg);
  tcase_add_test(tc, test_neg2);
  tcase_add_test(tc, test_neg3);
  tcase_add_test(tc, test_nul);
  tcase_add_test(tc, test_nul2);
  tcase_add_test(tc, test_nul3);

  suite_add_tcase(s, tc);
  return s;
}
