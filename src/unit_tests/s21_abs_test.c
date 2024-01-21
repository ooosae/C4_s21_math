#include "s21_math_test.h"

START_TEST(abs_test1) { ck_assert_int_eq(s21_abs(-1), abs(-1)); }
END_TEST

START_TEST(abs_test2) { ck_assert_int_eq(s21_abs(5), abs(5)); }
END_TEST

START_TEST(abs_test3) {
  ck_assert_int_eq(s21_abs(-2147483647), abs(-2147483647));
}
END_TEST

START_TEST(abs_test4) {
  ck_assert_int_eq(s21_abs(-0x7FFFFFFF), abs(-0x7FFFFFFF));
}
END_TEST

START_TEST(abs_test5) { ck_assert_int_eq(s21_abs(13), abs(13)); }
END_TEST

START_TEST(abs_test6) { ck_assert_int_eq(s21_abs(-0), abs(-0)); }
END_TEST

START_TEST(abs_test7) { ck_assert_int_eq(s21_abs(-5), abs(-5)); }
END_TEST

START_TEST(abs_test8) { ck_assert_int_eq(s21_abs(-12345678), abs(-12345678)); }
END_TEST

START_TEST(abs_test9) { ck_assert_int_eq(s21_abs(123456789), abs(123456789)); }
END_TEST

START_TEST(abs_test10) { ck_assert_int_eq(s21_abs(100), abs(100)); }
END_TEST

START_TEST(abs_test11) { ck_assert_int_eq(s21_abs(-100), abs(-100)); }
END_TEST

START_TEST(abs_test12) { ck_assert_int_eq(s21_abs(0), abs(0)); }
END_TEST

START_TEST(abs_test13) { ck_assert_int_eq(s21_abs(1), abs(1)); }
END_TEST

START_TEST(abs_test14) { ck_assert_int_eq(s21_abs(-2), abs(-2)); }
END_TEST

START_TEST(abs_test15) { ck_assert_int_eq(s21_abs(3), abs(3)); }
END_TEST

Suite *suite_abs(void) {
  Suite *s = suite_create("suite_abs");
  TCase *tc = tcase_create("abs_tc");

  tcase_add_test(tc, abs_test1);
  tcase_add_test(tc, abs_test2);
  tcase_add_test(tc, abs_test3);
  tcase_add_test(tc, abs_test4);
  tcase_add_test(tc, abs_test5);
  tcase_add_test(tc, abs_test6);
  tcase_add_test(tc, abs_test7);
  tcase_add_test(tc, abs_test8);
  tcase_add_test(tc, abs_test9);
  tcase_add_test(tc, abs_test10);
  tcase_add_test(tc, abs_test11);
  tcase_add_test(tc, abs_test12);
  tcase_add_test(tc, abs_test13);
  tcase_add_test(tc, abs_test14);
  tcase_add_test(tc, abs_test15);

  suite_add_tcase(s, tc);
  return s;
}
