#include "s21_math.h"

int s21_abs(int x) {
  int result;

  if (x > 0)
    result = x;
  else
    result = -x;

  return result;
}

long double s21_acos(double x) { return (S21_PI_2 - s21_asin(x)); }

long double s21_asin(double x) {
  long double result = 0;
  if ((x > 1.0 + eps) || x < -1.0 - eps) {
    result = S21_NAN;
  } else {
    x /= (double)s21_sqrt(1.0 - x * x);
    result = s21_atan(x);
  }
  return result;
}

long double s21_atan(double x) {
  int sign = 0;
  int size = 0;
  long double result = 0;
  long double x2 = 0;
  if (x < -eps) {
    x = -x;
    sign |= 1;
  }
  if (x > s21_pow(10, 7)) {
    x = (double)s21_pow(10, 7);
  }
  if (x - 1.0 > eps) {
    x = 1.0 / x;
    sign |= 2;
  }
  while (x > S21_PI_12) {
    size++;
    result = 1.0 / (x + S21_SQRT_3);
    x = ((x * S21_SQRT_3) - 1) * (double)result;
  }
  x2 = s21_pow(x, 2);
  result = x * (APPROX_A1 / (APPROX_A2 + x2) + APPROX_A3 - APPROX_A4 * x2);
  while (size > 0) {
    result += S21_PI_6;
    size--;
  }
  (sign & 2) ? result = S21_PI_2 - result : result;
  (sign & 1) ? result = -result : result;
  return result;
}

long double s21_ceil(double x) {
  int int_x = (int)x;
  long double result;

  if (s21_fabs((double)int_x - x) > eps && x > eps)
    result = int_x + 1.0;
  else
    result = int_x;

  return result;
}

long double s21_cos(double x) {
  long double sum = 1.0;
  long double term = 1.0;
  long double x_sq = x * x;
  long double dividend = 1.0;
  long double divisor = 1.0;
  long double sign = 1.0;
  long double n = 0.0;

  while (term > eps || term < -eps) {
    dividend *= x_sq;
    divisor *= (n + 1.0) * (n + 2.0);
    sign *= -1.0;
    term = sign * dividend / divisor;
    sum += term;
    n += 2.0;
  }

  return sum;
}

long double s21_exp(double x) {
  long double sum = 1.0;
  long double term = 1.0;
  long double factorial = 1.0;
  long double x_pow = 1.0;
  int k = 1;

  while (term > eps || term < -eps) {
    x_pow *= x;
    factorial *= k++;
    term = x_pow / factorial;
    sum += term;
  }

  return sum;
}

long double s21_fabs(double x) {
  long double result;

  if (x < -eps)
    result = -x;
  else
    result = x;

  return result;
}

long double s21_floor(double x) {
  int int_x = (int)x;
  long double result;

  if (s21_fabs((double)s21_fmod(x, 1)) < eps || int_x >= 0.0)
    result = int_x;
  else
    result = int_x - 1;

  return result;
}

long double s21_fmod(double x, double y) {
  long double remainder = S21_NAN;

  if (s21_fabs(y) >= eps) {
    if (s21_fabs(y) >= 1.F) {
      long double int_part = (long double)(long long)(x / y);
      remainder = x - int_part * y;
    }
  }
  return remainder;
}

long double s21_log(double x) {
  long double res = 0.0;
  if (x < eps) {
    res = S21_NAN;
  } else if (s21_fabs(x - 1.0) < eps) {
    res = 0.0;
  } else {
    double sum = 0.0;
    double tmp_x = x;
    double tmp = 0.0;
    while (tmp_x >= S21_E) {
      tmp_x /= S21_E;
      sum++;
    }
    sum += (tmp_x / S21_E);
    tmp_x = x;
    do {
      double left, right;
      tmp = sum;
      left = (tmp_x / ((double)s21_exp(sum - 1.0)));
      right = ((sum - 1.0) * S21_E);
      sum = ((left + right) / S21_E);
    } while (s21_fabs(sum - tmp) > eps);
    res = sum;
  }
  return res;
}

long double s21_pow(double base, double exp) {
  long double result = 1.0;
  if (s21_fabs(exp) < eps) {
    result = 1.0;
  } else if (s21_fabs(base) < eps) {
    result = 0.0;
  } else if ((base < -eps) && (s21_fmod((double)s21_fabs(exp), 1.0) > eps)) {
    result = S21_NAN;
  } else {
    if (exp < -eps) {
      exp = -exp;
      base = 1.0 / base;
    }

    int sign = 1;
    if (base < -eps) {
      base = -base;
      if (s21_fmod(exp, 2) > eps) sign = -1;
    }

    result = sign * s21_exp(exp * (double)s21_log(base));
  }
  return result;
}

long double s21_sin(double x) {
  long double sum = x;
  long double term = x;
  long double x_sq = x * x;
  long double dividend = x;
  long double divisor = 1.0;
  long double sign = 1.0;
  long double n = 1.0;

  while (term > eps || term < -eps) {
    dividend *= x_sq;
    divisor *= (n + 1.0) * (n + 2.0);
    sign *= -1.0;
    term = sign * dividend / divisor;
    sum += term;
    n += 2.0;
  }

  return sum;
}

long double s21_sqrt(double x) {
  long double result;
  if (x < -eps) {
    result = S21_NAN;
  } else if (x > -eps && x < eps) {
    result = 0.0;
  } else {
    long double guess = x / 2.0;
    long double prev_guess = 0.0;

    while (s21_fabs((double)(guess - prev_guess)) > eps) {
      prev_guess = guess;
      guess = (x / guess + guess) / 2.0;
    }

    result = guess;
  }
  return result;
}

long double s21_tan(double x) {
  long double result = S21_NAN;
  long double x_sin = s21_sin(x);
  long double x_cos = s21_cos(x);
  if (x_cos >= eps) {
    result = x_sin / x_cos;
  }
  return result;
}
