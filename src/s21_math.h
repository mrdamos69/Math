#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define E 2.71828182845904523536
#define s21LN10 2.30258509299404590109
#define s21_PI 3.141592653589793238462643383279502884197169399375105820974944
#define s21_PI_2 314.1592653589793238462643383279502884197169399375105820974944
#define s21_PI_3 3141.592653589793238462643383279502884197169399375105820974944
#define s21_PI_4 31415.92653589793238462643383279502884197169399375105820974944
#define s21_PI_5 314159.2653589793238462643383279502884197169399375105820974944
#define s21_PI_6 3141592.653589793238462643383279502884197169399375105820974944
#define s21_PI_7 31415926.53589793238462643383279502884197169399375105820974944
#define s21_PI_8 314159265.3589793238462643383279502884197169399375105820974944
#define s21_PI_9 3141592653.589793238462643383279502884197169399375105820974944

#define EXP_MIN -708.3964
#define EXP_MAX 709.7827
#define s21EPS 1e-17

#define s21NAN 0.0/0.0
#define s21INF 1.0/0.0
#define s21_min_INF -1.0/0.0

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
long double s21_pow_for_e(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
double shift_2pi(long double x);

#endif  // SRC_S21_MATH_H_
