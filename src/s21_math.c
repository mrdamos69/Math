#include "s21_math.h"

// вычисляет абсолютное значение целого числа
int s21_abs(int x) {
    return x = (x < 0 ? x*(-1) : x);
}

// вычисляет арккосинус
long double s21_acos(double x) {
    return (s21_PI/2) - s21_asin(x);
}

// вычисляет арксинус
long double s21_asin(double x) {
    int f_minus = 1;
    if (x < 0) {
        x = -x;
        f_minus = -1;
    }
    long double result = 0;
    if (x > 1) {
        result = 0 / 0.0;
    } else if (x > 1 / s21_sqrt(2)) {
        result = (s21_PI/2) - s21_asin(s21_sqrt(1 - x * x));
    } else {
        for (int k = 0; k < 100; k++) {
            long double current = 1;
            for (int j = 1; j <= 2 * k + 1; ++j) {
                current *= x;
                if (j % 2 == 0 || j == 2 * k + 1)
                    current /= j;
                else
                    current *= j;
            }
            result += current;
        }
    }
    return result * f_minus;
}

// вычисляет арктангенс
long double s21_atan(double x) {
    long double result = 0;
    int f_minus = 1;
    if (x < 0) {
        x *= (-1);
        f_minus = -1;
    }
    if (x < 0.9) {
        for (int k = 0; k < 100; k++) {
            long double current = 1;
            int j;
            for (j = 1; j <= 2 * k + 1; ++j) {
                current *= x;
            }
            if (j != 0) {
                current /= (j - 1);
            }
            result += s21_pow(-1, k) * current;
        }
    } else if (x > 1) {
        result = (s21_PI/2) - s21_atan(1 / x);
    } else {
        result = s21_asin(x / s21_sqrt(1 + x * x));
    }
    return f_minus * result;
}

// возвращает ближайшее целое число, не меньшее заданного значения
long double s21_ceil(double x) {
    long double result;
    if (s21_fmod(x, 1))
        result = (x > 0) ? (int)(++x) : (int)x;
    else
        result = x;
    return result;
}

// вычисляет косинус
long double s21_cos(double x) {
    x = shift_2pi(x);
    return s21_sin((s21_PI/2) - x);
}

// возвращает значение e, возведенное в заданную степень
long double s21_exp(double x) {
    long double s21_factorial = 1;
    long double result = (x > EXP_MAX ? s21INF : (x < EXP_MIN ? 0.0 : 1));
    if (result == 1) {
        for (int i = 1; i < 350; i++) {
            result += (s21_pow_for_e(x, i)/ s21_factorial);
            s21_factorial *= (i + 1);
        }
    }
    return result;
}

// вычисляет абсолютное значение числа с плавающей точкой
long double s21_fabs(double x) {
    return x = (x < 0 ? x * (-1) : x);
}

// возвращает ближайшее целое число, не превышающее заданное значение
long double s21_floor(double x) {
    return (x < 0 ? (int)--x : (int)x);
}

// остаток операции деления с плавающей точкой
long double s21_fmod(double x, double y) {
    double result, all_res;
    result = (x < 0 || y < 0 ? s21_abs(x / y) * (-1) : s21_abs(x / y));
    all_res = x - result * y;
    all_res = (y == 0 ? s21NAN : all_res);
    return all_res;
}

// вычисляет натуральный логарифм
long double s21_log(double x) {
    long double result = x - 1;
    long double result2 = x - 1;
    long double result3 = x;
    result =(x <= 0 ? (x == 0.0 ? -s21INF : s21NAN) : result);
    if (x < 2.0 && !(x <= 0)) {
        x--;
        for (int i = 2; s21_fabs(result2 / i) > s21EPS; ++i) {
            result2 *= (-1 * x);
            result += result2/i;
        }
    } else if (!(x <= 0)) {
        int i;
        for (i = 0; result3 > 1.0; i++) {
            result3 /= 10;
        }
        result = s21_log(result3) + i * s21LN10;
    }
    return result;
}

// возводит число в заданную степень a^x = exp(x* ln(a))
long double s21_pow(double base, double exp) {
    long double result;
    if (base == 0 &&  exp == 0) {
        result = 1;
    } else if (base < 0 && (s21_fmod(s21_fabs(exp), 1) > 0)) {
        result = s21NAN;
    } else {
        result = s21_exp(exp * s21_log(s21_fabs(base)));
        if ((s21_fmod(exp, 2) > 0) && (base < 0)) { result *= -1;}
        if ((base < 0) && (exp < 0) && (s21_fmod(s21_fabs(exp), 2) > 0)) {
            result *= -1;
        }
    }
    return result;
}

long double s21_pow_for_e(double base, double exp) {
    long double result = base;
    for (int i = 1; i < exp; i++) {
        result *= base;
    }
    return result;
}

// вычисляет синус
long double s21_sin(double x) {
    int f_minus = 1;
    if (x < 0) {
        f_minus = -1;
        x = (-1)*x;
    }
    x = shift_2pi(x);
    long double res = 0;
    for (int k = 0; k < 30; k++) {
        long double current = 1;
        for (int j = 1; j <= 2 * k + 1; ++j) {
            current *= x;
            current /= (j);
        }
        res += s21_pow(-1, k) * current;
    }
    return res*f_minus;
}

// вычисляет квадратный корень
long double s21_sqrt(double x) {
    long double result;  // = 4;
    return result = (x <= 0 ? (x == 0 ? 0.0 : s21NAN) : s21_pow(x, 0.5));
}

// вычисляет тангенс
long double s21_tan(double x) {
    long double res = 0;
    int flag_minus = 1;
    if (x < 0) {
        x = -x;
        flag_minus = -1;
    }
    x = shift_2pi(x);
    while (x > s21_PI)
        x -= s21_PI;
    x = x*flag_minus;
    res = s21_sin(x)/s21_cos(x);
    return res;
}

double shift_2pi(long double x) {
    while (x > s21_PI_9)
        x -= s21_PI_9;
    while (x > s21_PI_8)
        x -= s21_PI_8;
    while (x > s21_PI_7)
        x -= s21_PI_7;
    while (x > s21_PI_6)
        x -= s21_PI_6;
    while (x > s21_PI_5)
        x -= s21_PI_5;
    while (x > s21_PI_4)
        x -= s21_PI_4;
    while (x > s21_PI_3)
        x -= s21_PI_3;
    while (x > s21_PI_2)
        x -= s21_PI_2;
    while (x > 2 * s21_PI)
        x -= 2 * s21_PI;
    return (x < 0) ? s21_fabs(x) : x;
}
