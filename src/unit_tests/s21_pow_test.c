#include "s21_math_test.h"

START_TEST(test_pos_1) {
  double num = 2;
  double p = 3;
  if (isnan(s21_pow(num, p))) ck_abort();
  if (fabs((double)(pow(num, p) - s21_pow(num, p))) > eps) ck_abort();
}
END_TEST

START_TEST(test_pos_2) {
  double num = 122.5;
  double p = 21.5e-34;
  if (isnan(s21_pow(num, p))) ck_abort();
  if (fabs((double)(pow(num, p) - s21_pow(num, p))) > eps) ck_abort();
}
END_TEST

START_TEST(test_1) {
  double num = 2;
  double p = -2;
  if (isnan(s21_pow(num, p))) ck_abort();
  if (fabs((double)(pow(num, p) - s21_pow(num, p))) > eps) ck_abort();
}
END_TEST

START_TEST(test_2) {
  double num = -2;
  double p = -2;
  if (isnan(s21_pow(num, p))) ck_abort();
  if (fabs((double)(pow(num, p) - s21_pow(num, p))) > eps) ck_abort();
}
END_TEST

START_TEST(test_3) {
  double num = 2;
  double p = 2;
  if (isnan(s21_pow(num, p))) ck_abort();
  if (fabs((double)(pow(num, p) - s21_pow(num, p))) > eps) ck_abort();
}
END_TEST

START_TEST(test_4) {
  double num = -2;
  double p = 2;
  if (isnan(s21_pow(num, p))) ck_abort();
  if (fabs((double)(pow(num, p) - s21_pow(num, p))) > eps) ck_abort();
}
END_TEST

START_TEST(test_neg_pow_1) {
  double num = 20;
  double p = -5;
  if (isnan(s21_pow(num, p))) ck_abort();
  if (fabs((double)(pow(num, p) - s21_pow(num, p))) > eps) ck_abort();
}
END_TEST

START_TEST(test_neg_num_odd_int_pow) {
  double num = -12.1;
  double p = -3.1;
  if (fabs((double)(pow(num, p) - s21_pow(num, p))) > eps) ck_abort();
}
END_TEST

START_TEST(test_neg_num_fract_pow) {
  double num = -12.1;
  double p = -1.5;
  if (fabs((double)(pow(num, p) - s21_pow(num, p))) > eps) ck_abort();
}
END_TEST

START_TEST(test_fractional_pow) {
  double num = 15.1;
  double p = 1.12443;
  if (isnan(s21_pow(num, p))) ck_abort();
  if (fabs((double)(pow(num, p) - s21_pow(num, p))) > eps) ck_abort();
}
END_TEST

START_TEST(test_fractional_pow_neg_num) {
  double num = -22137.45;
  double p = 1.0 / 3.0;
  if (fabs((double)(pow(num, p) - s21_pow(num, p))) > eps) ck_abort();
}
END_TEST

START_TEST(test_one_power) {
  double num = 12.34;
  double p = 1;
  if (isnan(s21_pow(num, p))) ck_abort();
  if (fabs((double)(pow(num, p) - s21_pow(num, p))) > eps) ck_abort();
}
END_TEST

START_TEST(test_zero_pos_pow) {
  double num = 0;
  double p = 12;
  if (isnan(s21_pow(num, p))) ck_abort();
  if (fabs((double)(pow(num, p) - s21_pow(num, p))) > eps) ck_abort();
}
END_TEST

Suite *suite_pow(void) {
  Suite *s = suite_create("suite_pow");
  TCase *tc = tcase_create("pow_tc");

  tcase_add_test(tc, test_pos_1);
  tcase_add_test(tc, test_pos_2);
  tcase_add_test(tc, test_neg_pow_1);
  tcase_add_test(tc, test_neg_num_odd_int_pow);
  tcase_add_test(tc, test_neg_num_fract_pow);
  tcase_add_test(tc, test_fractional_pow);
  tcase_add_test(tc, test_fractional_pow_neg_num);
  tcase_add_test(tc, test_one_power);
  tcase_add_test(tc, test_zero_pos_pow);
  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);

  suite_add_tcase(s, tc);
  return s;
}
