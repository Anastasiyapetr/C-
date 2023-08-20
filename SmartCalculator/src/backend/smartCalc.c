#include "smartCalc.h"

int smartCalculator(char *string, long double *result, int isx, double x) {
  int flag = OK;
  char tmp_string[MAX_COUNT_LEX] = "\0";
  if (string != NULL && strlen(string) > 0) {
    strcpy(tmp_string, string);
    change_mod(tmp_string);
    change_arith(tmp_string);
    if (valid_string(tmp_string)) {
      flag = FAIL;
    } else if (valid_arith_string(tmp_string, x)) {
      flag = CALC_ERR;
    } else {
      int count_lexeme = 0, count_exp = 0;
      char **str_arr = lexeme(tmp_string, &count_lexeme);

      if (isx) {
        char *arg = calloc(20, sizeof(char));
        for (int i = 0; i < count_lexeme; i++) {
          if (strcmp(str_arr[i], "x") == 0) {
            sprintf(arg, "%7lf", x);
            strcpy(str_arr[i], arg);
            memset(arg, '\0', 20);
          }
        }
        free(arg);
      }
      char **str_arr_2 = polish_translator(str_arr, count_lexeme, &count_exp);
      *result = calculate(str_arr_2, count_exp);
    }
  } else {
    flag = FAIL;
  }
  return flag;
}

void change_mod(char *string) {
  int count = 0;
  size_t index = 0;
  char *tmp = string;
  while (index != strlen(tmp) - 1) {
    if (tmp[index] == 'm' && tmp[index + 1] == 'o' && tmp[index + 2] == 'd') {
      for (size_t i = index + 1; i < strlen(tmp); i++) {
        if (i + 2 < strlen(tmp)) {
          tmp[i] = tmp[i + 2];
        }
      }
      count += 2;
    }
    index++;
  }
  if (count != 0) {
    tmp[strlen(tmp) - count] = '\0';
  }
  string = tmp;
}

void change_arith(char *string) {
  char result[MAX_COUNT_LEX] = "\0";
  size_t index = 0, i = 0;
  for (; i < strlen(string); i++) {
    if (strchr("+=*/m^", string[i]) && string[i + 1] == '-') {
      result[index++] = string[i];
      result[index++] = '(';
      result[index++] = string[++i];
      i++;
      while ((string[i] >= '0' && string[i] <= '9') || (string[i] == '.')) {
        result[index++] = string[i++];
      }
      result[index++] = ')';
    } else {
      result[index++] = string[i];
    }
  }
  strcpy(string, result);
}

int valid_operators(char *string) {
  int flag = OK;
  int step = 0, len = 0;
  const char valid_op[][6] = {{"sin("},  {"cos("},  {"tan("},
                              {"acos("}, {"asin("}, {"atan("},
                              {"sqrt("}, {"ln("},   {"log("}};

  char *tmp_string = calloc(MAX_COUNT_LEX, 1);
  strcpy(tmp_string, string);
  for (size_t i = 0; i < strlen(string) && !flag;) {
    if (strchr("+-*/m.^x()1234567890", tmp_string[0])) {
      i++;
      step = 1;
    }
    if (step == 0) {
      for (int j = 0; j < 9;) {
        char *tmp = strstr(tmp_string, valid_op[j]);

        if (tmp != NULL && strcmp(tmp, tmp_string) == 0) {
          if ((j >= 0 && j <= 2) || (j == 8)) {
            i += 4;
            step = 4;
          } else if (j >= 3 && j <= 6) {
            i += 5;
            step = 5;
          } else {
            i += 3;
            step = 3;
          }
          break;
        } else if (j == 8 && tmp == NULL) {
          flag = FAIL;
          break;
        } else {
          j++;
        }
      }
    }
    tmp_string += step;
    len += step;
    step = 0;
  }
  tmp_string -= len;
  free(tmp_string);
  return flag;
}

int valid_string(char *string) {
  int flag = OK;
  int brackets = 0;
  flag = valid_operators(string);
  if (!flag) {
    for (size_t i = 0; i < strlen(string) && !flag; i++) {
      if (i == strlen(string) - 1 && (!strchr("1234567890)x", string[i]))) {
        flag = FAIL;
      } else if (i == 0 && strchr("*/.^m)", string[i])) {
        flag = FAIL;
      } else if (string[i] == '.' && !strchr("0123456789x", string[i + 1]) &&
                 !strchr("0123456789x", string[i - 1])) {
        flag = FAIL;
      } else if (string[i] == '(' && (strchr("*/.m^)", string[i + 1]))) {
        flag = FAIL;
      } else if (string[i] == '(' && i != 0 &&
                 strchr("1234567890x.)", string[i - 1])) {
        flag = FAIL;
      } else if ((string[i] == ')' && !strchr("0123456789x)", string[i - 1]))) {
        flag = FAIL;
      } else if (string[i] == ')' && i != strlen(string) - 1 &&
                 !strchr(")*/+-^m", string[i + 1])) {
        flag = FAIL;
      } else if (string[i] == '.') {
        i++;
        while (string[i] >= '0' && string[i] <= '9') {
          i++;
        }
        if (string[i] == '.') {
          flag = FAIL;
        } else {
          i--;
        }
      } else if (string[i] == '(') {
        brackets++;
      } else if (string[i] == ')') {
        brackets--;
      }
    }
    if (brackets != 0) {
      flag = FAIL;
    }
  }
  return flag;
}

int valid_arith_string(char *string, double x) {
  int flag = OK;
  for (size_t i = 0; i < strlen(string); i++) {
    if (string[i] == '/') {
      i++;
      while (string[i] == '(') {
        i++;
      }
      if ((string[i] == '0') || (string[i] == 'x' && fabs(x) < 1e-8)) {
        flag = FAIL;
      }
    } else if (string[i] == 's' && string[i + 1] == 'q' &&
               string[i + 2] == 'r' && string[i + 3] == 't') {
      i += 4;
      while (string[i] == '(') {
        i++;
      }
      if ((string[i] == '-') || (string[i] == 'x' && x < 0.0)) {
        flag = FAIL;
      }
    } else if ((string[i] == 'l' && string[i + 1] == 'o' &&
                string[i + 2] == 'g') ||
               (string[i] == 'l' && string[i + 1] == 'n')) {
      if (string[i + 1] == 'o') {
        i += 3;
      } else {
        i += 2;
      }
      while (string[i] == '(') {
        i++;
      }
      if ((string[i] == '-') || (string[i] == 'x' && x < 0.0)) {
        flag = FAIL;
      }
    }
  }
  return flag;
}

char **lexeme(char *string, int *count_lex) {
  char valid_op[][5] = {{"sin"},  {"cos"},  {"tan"}, {"acos"}, {"asin"},
                        {"atan"}, {"sqrt"}, {"ln"},  {"log"}};
  int len = 0;
  char **result = initstack();
  for (size_t k = 0; k < strlen(string); k++) {
    if (string[k] == '-' && string[k + 1] == '(' &&
        (k == 0 || string[k - 1] == '(')) {
      strcat(result[(*count_lex)++], "0");
      strcat(result[(*count_lex)++], "-");
    } else if (((string[k] == '-' || string[k] == '+') &&
                ((k == 0) || (k != 0 && string[k - 1] == '('))) ||
               (string[k] >= '0' && string[k] <= '9')) {
      if (string[k] == '-') {
        strcat(result[*count_lex], "-");
        len++;
      }
      if (string[k] == '-' || string[k] == '+') {
        k++;
      }
      while ((string[k] == '.') || (string[k] >= '0' && string[k] <= '9')) {
        result[*count_lex][len++] = string[k++];
      }
      k--;
      *count_lex = *count_lex + 1;
      len = 0;
    } else if (string[k] == '(') {
      if (k == 0 || strchr("+-*/^m(", string[k - 1])) {
        strcat(result[(*count_lex)++], "(");
      }
    } else if (string[k] == ')') {
      strcat(result[(*count_lex)++], ")");
    } else if (strchr("+-*/^mx", string[k])) {
      result[(*count_lex)++][0] = string[k];
    } else {
      string = string + k;
      for (int i = 0; i < 9; i++) {
        if (strstr(string, valid_op[i]) == string) {
          strcat(result[(*count_lex)++], valid_op[i]);
          strcat(result[(*count_lex)++], "(");
          string = string - k;
          if ((i >= 0 && i <= 2) || (i == 8)) {
            k += 3;
          } else if (i >= 3 && i <= 6) {
            k += 4;
          } else {
            k += 2;
          }
          break;
        }
      }
    }
  }
  return result;
}

char **initstack() {
  char **stack = calloc(MAX_COUNT_LEX, sizeof(char *));
  for (int i = 0; i < MAX_COUNT_LEX; i++) {
    stack[i] = (char *)calloc(MAX_LEN_OPER, sizeof(char));
  }
  return stack;
}

void push(char *a, int *top, char **stack) {
  sscanf(a, "%s", stack[*top]);
  *top = *top + 1;
}

char *pop(int *top, char **stack) {
  *top = *top - 1;
  return stack[*top];
}

void free_stack(char **stack) {
  for (int i = 0; i < MAX_COUNT_LEX; i++) {
    free(stack[i]);
  }
  free(stack);
  stack = NULL;
}

void unar_minus(char **polish_string, int *count_polish, char *lexeme, int *top,
                char **stack) {
  strcat(polish_string[*count_polish], "0");
  *count_polish = *count_polish + 1;
  lexeme++;
  strcat(polish_string[*count_polish], lexeme);
  *count_polish = *count_polish + 1;
  push("-", top, stack);
}

int last_operand(int top, char **stack) {
  int priority_stack_operand = 0;

  if (top >= 0) {
    if (stack[top][0] == '-' || stack[top][0] == '+') {
      priority_stack_operand = 2;
    } else if (stack[top][0] == '*' || stack[top][0] == '/' ||
               stack[top][0] == 'm') {
      priority_stack_operand = 3;
    } else if (stack[top][0] == '^') {
      priority_stack_operand = 4;
    } else if (stack[top][0] == '(') {
      priority_stack_operand = 1;
    } else {
      priority_stack_operand = 5;
    }
  }
  return priority_stack_operand;
}

char **polish_translator(char **lexeme, int count_lex, int *count_exp) {
  struct operators all[COUNT_OP] = {
      {"(", 1},   {")", 1},    {"*", 3},    {"/", 3},    {"+", 2},
      {"-", 2},   {"m", 3},    {"^", 4},    {"sin", 5},  {"cos", 5},
      {"tan", 5}, {"acos", 5}, {"asin", 5}, {"atan", 5}, {"sqrt", 5},
      {"log", 5}, {"ln", 5}};

  char **stack = initstack();
  char **polish_string = initstack();
  int i = 0, count_polish = 0, top = 0, priority_stack_operand = 0;
  for (; i != count_lex; i++) {
    if (lexeme[i][0] == '-' && (lexeme[i][1] >= '0' && lexeme[i][1] <= '9')) {
      unar_minus(polish_string, &count_polish, lexeme[i], &top, stack);
      priority_stack_operand = 6;
    } else if ((lexeme[i][0] >= '0' && lexeme[i][0] <= '9')) {
      strcat(polish_string[count_polish++], lexeme[i]);
    } else {
      for (int j = 0; j < COUNT_OP; j++) {
        if (strcmp(lexeme[i], all[j].name) == 0) {
          if (j == 0) {
            push(all[j].name, &top, stack);
            priority_stack_operand = 1;
          } else if (j >= 2 && j <= 16) {
            if (((all[j].priority < priority_stack_operand) ||
                 (all[j].priority == priority_stack_operand && j < 7)) &&
                top != 0) {
              strcat(polish_string[count_polish++], pop(&top, stack));

              priority_stack_operand = last_operand(top - 1, stack);
              while (top >= 0 &&
                     ((priority_stack_operand > all[j].priority) ||
                      (priority_stack_operand == all[j].priority && j != 7)) &&
                     j >= 2) {
                strcat(polish_string[count_polish++], pop(&top, stack));
                if (top == 0) {
                  priority_stack_operand = 0;
                } else {
                  priority_stack_operand = last_operand(top - 1, stack);
                }
              }
            }
            push(all[j].name, &top, stack);
            priority_stack_operand = all[j].priority;
          } else if (j == 1) {
            int k = top;
            while (strcmp(stack[--k], "(") != 0) {
              strcat(polish_string[count_polish++], pop(&top, stack));
            }
            char *s = pop(&top, stack);
            s[0] = '\0';
            k--;
            if (k >= 0) {
              for (int i = 0; i < COUNT_OP; i++) {
                if (strcmp(stack[k], all[i].name) == 0) {
                  priority_stack_operand = all[i].priority;
                }
              }
            } else {
              priority_stack_operand = 0;
            }
          }
        }
      }
    }
  }
  while (top != 0) {
    strcat(polish_string[count_polish++], pop(&top, stack));
  }
  *count_exp = count_polish;
  free_stack(stack);
  free_stack(lexeme);
  return polish_string;
}

long double calculate(char **polish_string, int count_exp) {
  char **stack = initstack();
  char *tmp = calloc(50, sizeof(char));
  int top = 0;
  long double result = 0;

  for (int i = 0; i < count_exp; i++) {
    if (polish_string[i][0] >= '0' && polish_string[i][0] <= '9') {
      push(polish_string[i], &top, stack);
    } else {
      if (strcmp(polish_string[i], "+") == 0 ||
          strcmp(polish_string[i], "-") == 0 ||
          strcmp(polish_string[i], "*") == 0 ||
          strcmp(polish_string[i], "/") == 0 ||
          strcmp(polish_string[i], "m") == 0 ||
          strcmp(polish_string[i], "^") == 0) {
        result = arithmetic(stack, polish_string[i], &top);
      } else {
        result = functions(stack, polish_string[i], &top);
      }
      sprintf(tmp, "%.7Lf", result);
      push(tmp, &top, stack);
      memset(tmp, '\0', 20);
    }
  }
  sscanf(pop(&top, stack), "%Lf", &result);

  free(tmp);
  free_stack(stack);
  free_stack(polish_string);

  return result;
}

long double arithmetic(char **stack, char *polish_string, int *top) {
  long double result = 0.0;
  long double x1 = 0.0, x2 = 0.0;

  sscanf(pop(top, stack), "%Lf", &x2);
  if (*top != 0) {
    sscanf(pop(top, stack), "%Lf", &x1);
  }

  if (strcmp(polish_string, "+") == 0) {
    result = x1 + x2;
  } else if (strcmp(polish_string, "-") == 0) {
    result = x1 - x2;
  } else if (strcmp(polish_string, "*") == 0) {
    result = x1 * x2;
  } else if (strcmp(polish_string, "/") == 0) {
    result = x1 / x2;
  } else if (strcmp(polish_string, "m") == 0) {
    result = fmod(x1, x2);
  } else {
    result = pow(x1, x2);
  }
  return result;
}

long double functions(char **stack, char *polish_string, int *top) {
  long double result = 0.0;
  long double x1 = 0.0;

  sscanf(pop(top, stack), "%Lf", &x1);

  if (strcmp(polish_string, "sin") == 0) {
    result = sinl(x1);
  } else if (strcmp(polish_string, "cos") == 0) {
    result = cosl(x1);
  } else if (strcmp(polish_string, "tan") == 0) {
    result = tanl(x1);
  } else if (strcmp(polish_string, "acos") == 0) {
    result = acos(x1);
  } else if (strcmp(polish_string, "asin") == 0) {
    result = asin(x1);
  } else if (strcmp(polish_string, "atan") == 0) {
    result = atan(x1);
  } else if (strcmp(polish_string, "sqrt") == 0) {
    result = sqrt(x1);
  } else if (strcmp(polish_string, "log") == 0) {
    result = log10(x1);
  } else {
    result = log(x1);
  }
  return result;
}
