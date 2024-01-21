#ifndef __S21_MATH_H__
#define __S21_MATH_H__

#include <stdio.h>

#define eps 1e-7
#define S21_NAN 0.0 / 0.0
#define S21_PI 3.1415926535
#define S21_PI_2 1.5707963267
#define S21_E 2.7182818284
#define S21_PI_12 (S21_PI / 12.F)
#define S21_PI_6 (S21_PI / 6.F)
#define S21_SQRT_3 ((float)1.732050807569)
#define APPROX_A1 0.55913709
#define APPROX_A2 1.4087812
#define APPROX_A3 0.60310579
#define APPROX_A4 0.05160454

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif  // __S21_MATH_H__
