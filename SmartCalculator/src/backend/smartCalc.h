#ifndef SMARTCALC_H
#define SMARTCALC_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define FAIL 1
#define CALC_ERR 2

#define MAX_LEN_OPER 50
#define COUNT_OP 17
#define MAX_COUNT_LEX 255

struct operators {
  char name[MAX_LEN_OPER];
  int priority;
};

int smartCalculator(char *string, long double *result, int isx, double x);
void change_mod(char *string);
void change_arith(char *string);

int valid_operators(char *string);
int valid_string(char *string);
int valid_arith_string(char *string, double x);

char **lexeme(char *string, int *count_lex);
char **polish_translator(char **lexeme, int count_lex, int *count_exp);
long double calculate(char **polish_string, int count_exp);
long double arithmetic(char **stack, char *polish_string, int *top);
long double functions(char **stack, char *polish_string, int *top);
void unar_minus(char **polish_string, int *count_polish, char *lexeme, int *top,
                char **stack);
int last_operand(int top, char **stack);

char **initstack();
void push(char *a, int *top, char **stack);
char *pop(int *top, char **stack);
void free_stack(char **stack);

#endif  //  SMARTCALC_H
