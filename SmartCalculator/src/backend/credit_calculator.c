#include "credit_calculator.h"

double Calc_month_payment(double sum, double rate, int term) {
  double month_rate = rate / 12.0 / 100.0;
  double index = (month_rate * (pow(1 + month_rate, term)) /
                  (pow(1 + month_rate, term) - 1));
  double month_payment = index * sum;
  month_payment = round(month_payment * 100) / 100;
  return month_payment;
}

void Calc_ann_type(double *main_debt, double *perc_debt, double rate,
                   double sum, double month_payment) {
  *perc_debt = sum * (rate / 12.0 / 100.0);
  *main_debt = month_payment - *perc_debt;
}

void Calc_diff_type(double *perc_debt, double rate, double sum) {
  *perc_debt = sum * rate / 100 / 12;
}
