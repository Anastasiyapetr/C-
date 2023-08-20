/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source
 * file "test.check" instead.
 */

#include <check.h>

#include "../backend/credit_calculator.h"
#include "../backend/smartCalc.h"

START_TEST(calc_error) {
  char *string = "1/0";
  long double result = -1;

  int res = smartCalculator(string, &result, 0, 0);

  ck_assert_int_eq(res, CALC_ERR);
  ck_assert_int_eq(result, -1);
}
END_TEST

START_TEST(invalid_error_1) {
  char *string = "1/0+";
  long double result = 1;

  int res = smartCalculator(string, &result, 0, 0);

  ck_assert_int_eq(res, FAIL);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(invalid_error_2) {
  char *string = "(1+2*2)/((2+2)";
  long double result = 1;

  int res = smartCalculator(string, &result, 0, 0);

  ck_assert_int_eq(res, FAIL);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(invalid_error_3) {
  char *string = "212.242.2+253";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, FAIL);
  ck_assert_double_eq_tol(1, result, 1e-7);
}
END_TEST

START_TEST(invalid_error_4) {
  char *string = "sin(3)/";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, FAIL);
  ck_assert_double_eq_tol(1, result, 1e-7);
}
END_TEST

START_TEST(invalid_error_5) {
  char *string = "11.124.15-35";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, FAIL);
  ck_assert_double_eq_tol(1, result, 1e-7);
}
END_TEST

START_TEST(invalid_error_6) {
  char *string = "(34-)(2)";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, FAIL);
  ck_assert_double_eq_tol(1, result, 1e-7);
}
END_TEST

START_TEST(invalid_error_7) {
  char *string = "coss(2)";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, FAIL);
  ck_assert_double_eq_tol(1, result, 1e-7);
}
END_TEST

START_TEST(invalid_error_8) {
  char *string = "";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, FAIL);
  ck_assert_double_eq_tol(1, result, 1e-7);
}
END_TEST

START_TEST(invalid_error_9) {
  char *string = "*122";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, FAIL);
  ck_assert_double_eq_tol(1, result, 1e-7);
}
END_TEST

START_TEST(invalid_error_10) {
  char *string = ".22+12";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, FAIL);
  ck_assert_double_eq_tol(1, result, 1e-7);
}
END_TEST

START_TEST(invalid_error_11) {
  char *string = "18+(*12)";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, FAIL);
  ck_assert_double_eq_tol(1, result, 1e-7);
}
END_TEST

START_TEST(invalid_error_12) {
  char *string = "18(10)";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, FAIL);
  ck_assert_double_eq_tol(1, result, 1e-7);
}
END_TEST

START_TEST(invalid_error_13) {
  char *string = "8..2+20";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, FAIL);
  ck_assert_double_eq_tol(1, result, 1e-7);
}
END_TEST

START_TEST(invalid_error_14) {
  char *string = "(-15)40";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, FAIL);
  ck_assert_double_eq_tol(1, result, 1e-7);
}
END_TEST

START_TEST(mod_1) {
  char *string = "12mod4+3";
  long double result = 1;

  int res = smartCalculator(string, &result, 0, 0);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(result, 3);
}
END_TEST

START_TEST(mod_2) {
  char *string = "sin(1)";
  long double result = 1;

  int res = smartCalculator(string, &result, 0, 0);

  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(result, sin(1), 1e-7);
}
END_TEST

START_TEST(x_1) {
  char *string = "2*x+2-x";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 2.5);
  long double tmp = 2 * 2.5 + 2 - 2.5;

  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(x_2) {
  char *string = "log(x)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 0.1);
  double tmp = log10(0.1);

  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(x_3) {
  char *string = "ln(x)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 8);
  double tmp = log(8);

  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(x_4) {
  char *string = "cos(x)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 60);
  double tmp = cos(60);

  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(x_5) {
  char *string = "sin(x)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 90);
  double tmp = sin(90);

  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(x_6) {
  char *string = "tan(x)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 90);
  double tmp = tan(90);

  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(x_7) {
  char *string = "acos(x)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 0.5);
  double tmp = acos(0.5);

  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(sin_1) {
  char *string = "sin(0.5)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 0);
  double tmp = sin(0.5);

  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(sin_2) {
  char *string = "sin(-2)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 0);
  double tmp = sin(-2);

  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(cos_1) {
  char *string = "cos(0.5)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 0);
  double tmp = cos(0.5);

  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(cos_2) {
  char *string = "cos(-2)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 0);
  double tmp = cos(-2);

  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(tan_1) {
  char *string = "tan(60)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 0);
  double tmp = tan(60);

  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(tan_2) {
  char *string = "tan(90)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 0);
  double tmp = tan(90);

  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(tan_3) {
  char *string = "tan(x)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, -2);
  double tmp = tan(-2);

  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(tan_4) {
  char *string = "tan(x)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 180);
  double tmp = tan(180);

  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(acos_1) {
  char *string = "acos(0.5)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 0);
  double tmp = acos(0.5);

  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(acos_2) {
  char *string = "acos(1)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 0);
  double tmp = acos(1);

  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(acos_3) {
  char *string = "acos(x)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 0);
  double tmp = acos(0);

  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(acos_4) {
  char *string = "acos(x)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, -1);
  double tmp = acos(-1);

  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(asin_1) {
  char *string = "asin(0.5)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 0);
  double tmp = asin(0.5);

  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(asin_2) {
  char *string = "asin(1)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 0);
  double tmp = asin(1);

  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(asin_3) {
  char *string = "asin(x)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 0);
  double tmp = asin(0);

  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(asin_4) {
  char *string = "asin(x)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, -1);
  double tmp = asin(-1);

  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(atan_1) {
  char *string = "atan(0.5)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 0);
  double tmp = atan(0.5);

  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(atan_2) {
  char *string = "atan(1)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 0);
  double tmp = atan(1);

  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(atan_3) {
  char *string = "atan(x)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 0);
  double tmp = atan(0);

  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(atan_4) {
  char *string = "atan(x)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, -1);
  double tmp = atan(-1);

  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(sqrt_1) {
  char *string = "sqrt(81)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, 9, 1e-7);
}
END_TEST

START_TEST(sqrt_2) {
  char *string = "sqrt(0)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, 0, 1e-7);
}
END_TEST

START_TEST(sqrt_3) {
  char *string = "sqrt(x)";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, -1);
  ck_assert_int_eq(res, CALC_ERR);
}
END_TEST

START_TEST(sqrt_4) {
  char *string = "sqrt(x)";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 262144);
  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, 512, 1e-7);
}
END_TEST

START_TEST(log_1) {
  char *string = "log(1)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, 0, 1e-7);
}
END_TEST

START_TEST(log_2) {
  char *string = "log(10)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, 1, 1e-7);
}
END_TEST

START_TEST(log_3) {
  char *string = "log(x)";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, -1);
  ck_assert_int_eq(res, CALC_ERR);
}
END_TEST

START_TEST(log_4) {
  char *string = "log(x)";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 100);
  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, 2, 1e-7);
}
END_TEST

START_TEST(log_5) {
  char *string = "log(x)";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 0.1);
  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, -1, 1e-7);
}
END_TEST

START_TEST(ln_1) {
  char *string = "ln(1)";
  long double result = 1;

  int res = smartCalculator(string, &result, 1, 0);
  double tmp = log(1);
  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(ln_2) {
  char *string = "ln(10)";
  long double result = 1;
  double tmp = log(10);

  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(ln_3) {
  char *string = "ln(x)";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, -1);
  ck_assert_int_eq(res, CALC_ERR);
}
END_TEST

START_TEST(ln_4) {
  char *string = "ln(x)";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 100);
  double tmp = log(100);

  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(ln_5) {
  char *string = "ln(3)+ln(4)";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 0);
  double tmp = log(3) + log(4);
  ck_assert_int_eq(res, OK);
  ck_assert_ldouble_eq_tol(result, tmp, 1e-7);
}
END_TEST

START_TEST(additional_1) {
  char *string = "1.675+256+123";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(380.675, result, 1e-7);
}
END_TEST

START_TEST(common_test_1) {
  char *string = "-(3)*(-1-(7*(-(-(-(-7))))))";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(150, result, 1e-7);
}
END_TEST

START_TEST(common_test_2) {
  char *string = "(8+2*5)/(1+3*2-4)";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(6, result, 1e-7);
}
END_TEST

START_TEST(common_test_3) {
  char *string = "(1+2)*4*cos(10*7-2)";
  long double result = 1;
  double tmp = (1 + 2) * 4 * cos(10 * 7 - 2);
  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(tmp, result, 1e-6);
}
END_TEST

START_TEST(common_test_4) {
  char *string = "4^acos(2/4)/tan(2*2)";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(3.6883678, result, 1e-6);
}
END_TEST

START_TEST(common_test_5) {
  char *string = "ln(55/(2+sqrt(77)))";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(1.63010785436, result, 1e-6);
}
END_TEST

START_TEST(common_test_6) {
  char *string = "-sqrt(x^log(5-x))+ln(55/(2+x))";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 1.45);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(1.66132917093, result, 1e-6);
}
END_TEST

START_TEST(common_test_7) {
  char *string = "asin(2/x)mod(x)+atan(x)";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 2);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(2.6779450446, result, 1e-6);
}
END_TEST

START_TEST(common_test_8) {
  char *string = "1/2*3";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(1.5, result, 1e-6);
}
END_TEST

START_TEST(pow_1) {
  char *string = "2^3^2";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(512, result, 1e-6);
}
END_TEST

START_TEST(un_minus) {
  char *string = "22*-1";
  long double result = 1;
  int res = smartCalculator(string, &result, 1, 0);
  ck_assert_int_eq(res, OK);
  ck_assert_double_eq_tol(-22, result, 1e-6);
}
END_TEST

START_TEST(credit_calculator_ann) {
  double sum = 1500000;
  double rate = 6.11;
  int term = 60;

  double month_pay = Calc_month_payment(sum, rate, term);
  double main_debt = 0, perc_debt = 0;
  double total_payment = month_pay * term;
  double overpayment = total_payment - sum;

  Calc_ann_type(&main_debt, &perc_debt, rate, sum, month_pay);

  ck_assert_double_eq_tol(29075.99, month_pay, 1e-2);
  ck_assert_double_eq_tol(21438.49, main_debt, 1e-2);
  ck_assert_double_eq_tol(7637.50, perc_debt, 1e-2);
  ck_assert_double_eq_tol(1744559.40, total_payment, 1e-2);
  ck_assert_double_eq_tol(244559.40, overpayment, 1e-2);
}
END_TEST

START_TEST(credit_calculator_diff) {
  double sum = 2200000;
  double sum_1 = sum;
  double rate = 8.99;
  int term = 120;
  double main_debt = sum / term;

  ck_assert_double_eq_tol(18333.33, main_debt, 1e-2);

  double perc_debt = 0;
  for (int i = 0; i <= term; i++) {
    double tmp = 0;
    Calc_diff_type(&tmp, rate, sum);
    sum -= main_debt;
    perc_debt += tmp;
  }

  double total_payment = main_debt * term + perc_debt;
  double overpayment = total_payment - sum_1;
  ck_assert_double_eq_tol(3197140.83, total_payment, 1e-2);
  ck_assert_double_eq_tol(997140.83, overpayment, 1e-2);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  srunner_set_fork_status(sr, CK_NOFORK);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, calc_error);
  tcase_add_test(tc1_1, invalid_error_1);
  tcase_add_test(tc1_1, invalid_error_2);
  tcase_add_test(tc1_1, invalid_error_3);
  tcase_add_test(tc1_1, invalid_error_4);
  tcase_add_test(tc1_1, invalid_error_5);
  tcase_add_test(tc1_1, invalid_error_6);
  tcase_add_test(tc1_1, invalid_error_7);
  tcase_add_test(tc1_1, invalid_error_8);
  tcase_add_test(tc1_1, invalid_error_9);
  tcase_add_test(tc1_1, invalid_error_10);
  tcase_add_test(tc1_1, invalid_error_11);
  tcase_add_test(tc1_1, invalid_error_12);
  tcase_add_test(tc1_1, invalid_error_13);
  tcase_add_test(tc1_1, invalid_error_14);
  tcase_add_test(tc1_1, mod_1);
  tcase_add_test(tc1_1, mod_2);
  tcase_add_test(tc1_1, x_1);
  tcase_add_test(tc1_1, x_2);
  tcase_add_test(tc1_1, x_3);
  tcase_add_test(tc1_1, x_4);
  tcase_add_test(tc1_1, x_5);
  tcase_add_test(tc1_1, x_6);
  tcase_add_test(tc1_1, x_7);
  tcase_add_test(tc1_1, sin_1);
  tcase_add_test(tc1_1, sin_2);
  tcase_add_test(tc1_1, cos_1);
  tcase_add_test(tc1_1, cos_2);
  tcase_add_test(tc1_1, tan_1);
  tcase_add_test(tc1_1, tan_2);
  tcase_add_test(tc1_1, tan_3);
  tcase_add_test(tc1_1, tan_4);
  tcase_add_test(tc1_1, acos_1);
  tcase_add_test(tc1_1, acos_2);
  tcase_add_test(tc1_1, acos_3);
  tcase_add_test(tc1_1, acos_4);
  tcase_add_test(tc1_1, asin_1);
  tcase_add_test(tc1_1, asin_2);
  tcase_add_test(tc1_1, asin_3);
  tcase_add_test(tc1_1, asin_4);
  tcase_add_test(tc1_1, atan_1);
  tcase_add_test(tc1_1, atan_2);
  tcase_add_test(tc1_1, atan_3);
  tcase_add_test(tc1_1, atan_4);
  tcase_add_test(tc1_1, sqrt_1);
  tcase_add_test(tc1_1, sqrt_2);
  tcase_add_test(tc1_1, sqrt_3);
  tcase_add_test(tc1_1, sqrt_4);
  tcase_add_test(tc1_1, log_1);
  tcase_add_test(tc1_1, log_2);
  tcase_add_test(tc1_1, log_3);
  tcase_add_test(tc1_1, log_4);
  tcase_add_test(tc1_1, log_5);
  tcase_add_test(tc1_1, ln_1);
  tcase_add_test(tc1_1, ln_2);
  tcase_add_test(tc1_1, ln_3);
  tcase_add_test(tc1_1, ln_4);
  tcase_add_test(tc1_1, ln_5);
  tcase_add_test(tc1_1, additional_1);
  tcase_add_test(tc1_1, common_test_1);
  tcase_add_test(tc1_1, common_test_2);
  tcase_add_test(tc1_1, common_test_3);
  tcase_add_test(tc1_1, common_test_4);
  tcase_add_test(tc1_1, common_test_5);
  tcase_add_test(tc1_1, common_test_6);
  tcase_add_test(tc1_1, common_test_7);
  tcase_add_test(tc1_1, common_test_8);
  tcase_add_test(tc1_1, pow_1);
  tcase_add_test(tc1_1, un_minus);
  tcase_add_test(tc1_1, credit_calculator_ann);
  tcase_add_test(tc1_1, credit_calculator_diff);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}