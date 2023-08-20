#ifndef CREDIT_CALCULATOR_H
#define CREDIT_CALCULATOR_H

#include <math.h>
#include <stdio.h>

void Calc_ann_type(double *main_debt, double *perc_debt, double rate,
                   double sum, double month_payment);
void Calc_diff_type(double *perc_debt, double rate, double sum);
double Calc_month_payment(double sum, double rate, int term);

#endif  // CREDIT_CALCULATOR_H
