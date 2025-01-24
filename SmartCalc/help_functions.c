#include "my_heder.h"
int check_null(const char* check_sctring) { return check_sctring == NULL; }

int check_simbol(const char* check_string) {
  int result = 99;
  char simbol_string[27] = "0123456789()+-=*/^sctalm~x";
  for (size_t i = 0; i < strlen(simbol_string); i++) {
    if (*check_string == simbol_string[i]) {
      if (i < 10) {
        result = number;
      } else if (i < 12) {
        result = parenthesis;
      } else if (i < 18) {
        result = sign;
      } else if (i < 23) {
        result = function;
      } else if (i < 24) {
        result = modd;
      } else if (i < 25) {
        result = unary_minus;
      } else {
        result = variable;
      }

      i = strlen(simbol_string);
    }
  }
  return result;
}

int check_parenthesis(char char_parenthesis) { return char_parenthesis == '('; }

int check_mod(const char* check_string) {
  int error = 0;
  for (int i = 0; *check_string && i < 3; check_string++, i++) {
    if (i == 1 && *check_string != 'o') {
      error = 1;
      break;
    }
    if (i == 2 && *check_string != 'd') {
      error = 1;
      break;
    }
  }
  return error;
}

int check_sign(const char* check_string) {
  int error = 0;
  if (check_simbol(check_string + 1) == sign) {
    error = 1;
  }
  return error;
}

int check_function(const char* check_string) {
  int quantity_number = 0;
  if (*check_string == 'a') {
    check_string++;
    quantity_number++;
    if (*check_string == 'c') {
      char check_cos[4] = "cos";
      for (int i = 0; i < 3 && *check_string; i++, check_string++) {
        if (*check_string != check_cos[i]) {
          quantity_number = 0;
          break;
        }
        quantity_number++;
      }
    } else if (*check_string == 's') {
      check_string++;
      quantity_number++;
      if (*check_string == 'i') {
        char check_sin[3] = "in";
        for (int i = 0; i < 2 && *check_string; i++, check_string++) {
          if (*check_string != check_sin[i]) {
            quantity_number = 0;
            break;
          }
          quantity_number++;
        }
      }
    } else if (*check_string == 't') {
      char check_tan[4] = "tan";
      for (int i = 0; i < 3 && check_string; i++, check_string++) {
        if (*check_string != check_tan[i]) {
          quantity_number = 0;
          break;
        }
        quantity_number++;
      }
    }

  } else if (*check_string == 'c') {
    char check_cos[4] = "cos";
    for (int i = 0; i < 3 && *check_string; i++, check_string++) {
      if (*check_string != check_cos[i]) {
        quantity_number = 0;
        break;
      }
      quantity_number++;
    }
  } else if (*check_string == 's') {
    check_string++;
    quantity_number++;
    if (*check_string == 'i') {
      char check_sin[3] = "in";
      for (int i = 0; i < 2 && *check_string; i++, check_string++) {
        if (*check_string != check_sin[i]) {
          quantity_number = 0;
          break;
        }
        quantity_number++;
      }
    } else if (*check_string == 'q') {
      char check_sqrt[4] = "qrt";
      for (int i = 0; i < 3 && *check_string; i++, check_string++) {
        if (*check_string != check_sqrt[i]) {
          quantity_number = 0;
          break;
        }
        quantity_number++;
      }
    }
  } else if (*check_string == 't') {
    char check_tan[4] = "tan";
    for (int i = 0; i < 3 && check_string; i++, check_string++) {
      if (*check_string != check_tan[i]) {
        quantity_number = 0;
        break;
      }
      quantity_number++;
    }
  } else if (*check_string == 'l') {
    check_string++;
    quantity_number++;
    if (*check_string == 'n') {
      quantity_number++;
    } else if (*check_string == 'o') {
      char check_log[3] = "og";
      for (int i = 0; i < 2 && check_string; i++, check_string++) {
        if (*check_string != check_log[i]) {
          quantity_number = 0;
          break;
        }
        quantity_number++;
      }
    }
  }

  return quantity_number;
}

int check_presens_value(const char* check_string) {
  int res = 0;
  for (; *check_string; check_string++) {
    if (*check_string == ')') {
      break;
    }
    if (*check_string != '(' && *check_string != ')') {
      res = 1;
    }
  }
  return res;
}

int check_string_correct(const char* check_string_const) {
  char test_string[200] = {'\0'};
  for (size_t x = 0; x < strlen(check_string_const); x++) {
    test_string[x] = check_string_const[x];
  }
  swap_minus(test_string);
  char* check_string = test_string;
  int count_parenthesis = 0;
  int error = 0;
  int count_sign = 0;
  for (; *check_string; check_string++) {
    if (check_simbol(check_string) == parenthesis) {
      if (check_parenthesis(*check_string)) {
        // printf("HERE %d\n",count_parenthesis);
        if (!check_presens_value(check_string)) {
          error = 1;
          break;
        }
        count_parenthesis++;
      } else {
        if (!count_parenthesis || check_simbol(check_string + 1) == number) {
          error = 1;
          break;
        } else {
          count_parenthesis--;
        }
      }
    } else if (check_simbol(check_string) == number) {
      if (count_sign) {
        count_sign--;
      }
      if (check_simbol(check_string + 1) == function ||
          check_simbol(check_string + 1) == variable ||
          check_parenthesis(*(check_string + 1))) {
        error = 1;
        break;
      }

    } else if (check_simbol(check_string) == modd) {
      if (count_sign || check_last_mod(check_string)) {
        error = 1;
        break;
      } else if (check_mod(check_string)) {
        error = 1;
        break;
      } else if (check_simbol(check_string + 3) == parenthesis) {
        if (!check_parenthesis(*(check_string + 3))) {
          error = 1;
          break;
        }
      } else {
        count_sign++;
        check_string += 2;
        continue;
      }
    } else if (check_simbol(check_string) == sign) {
      if (check_sign(check_string) || count_sign) {
        error = 1;
        break;
      } else if (check_simbol(check_string + 1) == parenthesis) {
        if (!check_parenthesis(*(check_string + 1))) {
          error = 1;
          break;
        } else {
          count_sign++;
        }
      } else {
        count_sign++;
      }
    } else if (check_simbol(check_string) == unary_minus) {
      if (check_sign(check_string)) {
        error = 1;
        break;
      } else if (check_simbol(check_string + 1) == parenthesis) {
        if (!check_parenthesis(*(check_string + 1))) {
          error = 1;
          break;
        }
      }
    } else if (check_simbol(check_string) == function) {
      if (count_sign) {
        count_sign--;
      }

      if (!check_function(check_string)) {
        error = 1;
        break;
      } else {
        check_string += check_function(check_string);
        //  printf("\n%d %c", check_function(check_string),*check_string);

        if (!*check_string) {
          error = 1;
          break;
        } else {
          if (check_simbol(check_string) != parenthesis) {
            error = 1;
            break;
          } else {
            if (!check_presens_value(check_string)) {
              error = 1;
              break;
            }
          }
          check_string--;
          continue;
        }
      }
    } else if (check_simbol(check_string) == variable) {
      if (count_sign) {
        count_sign--;
      }
      if (check_simbol(check_string + 1) == function ||
          check_simbol(check_string + 1) == variable ||
          check_simbol(check_string + 1) == number ||
          check_simbol(check_string + 1) == number) {
        error = 1;
        break;
      }
    } else if (*check_string == '.') {
      if (check_dot(check_string)) {
        error = 1;
        break;
      }
    } else {
      error = 1;
    }
  }
  check_string--;
  if (check_simbol(check_string) == sign) {
    error = 1;
  }
  if (count_parenthesis) {
    error = 1;
  }
  return error;
}

int push(elem** current_elem, char current_value) {
  int error = 0;
  elem* tmp = (elem*)malloc(sizeof(elem));
  if (tmp == NULL) {
    error = 1;
  } else {
    tmp->value = current_value;
    tmp->priority = prioryty_for_steck(&current_value);
    tmp->next = (*current_elem);

    (*current_elem) = tmp;
    // printf("%c %d %d\n",
    // current_value,prioryty_for_steck(&current_value),check_simbol(&current_value)
    // == sign);
  }
  return error;
}

int push_number(elem_number** current_elem, double current_value) {
  int error = 0;
  elem_number* tmp = (elem_number*)malloc(sizeof(elem_number));
  if (tmp == NULL) {
    error = 1;
  } else {
    tmp->value = current_value;
    tmp->next = (*current_elem);

    (*current_elem) = tmp;
  }
  return error;
}

int prioryty_for_steck(char* simbol) {
  int res = 0;
  if (check_simbol(simbol) == number) {
    res = number;
  } else if (check_simbol(simbol) == sign) {
    if (*simbol == '+') {
      res = sign;
    } else if (*simbol == '-') {
      res = sign;
    } else if (*simbol == '^') {
      res = 3;
    }
  } else if (*simbol == '*' || *simbol == '/') {
    res = 3;
  } else if (*simbol == '~') {
    res = 4;
  } else if (*simbol == 'm') {
    res = 3;
  }
  return res;
}

int pop(elem** current_elem) {
  elem* prev = NULL;
  int val = 0;
  ;
  if (current_elem == NULL) {
    exit(-1);
  }
  prev = (*current_elem);
  val = prev->value;
  (*current_elem) = (*current_elem)->next;
  free(prev);
  return val;
}

double pop_number(elem_number** current_elem) {
  elem_number* prev = NULL;
  double val = 0;
  ;
  if (current_elem == NULL) {
    exit(-1);
  }
  prev = (*current_elem);
  val = prev->value;
  (*current_elem) = (*current_elem)->next;
  free(prev);
  return val;
}

int priority_operator(const char* simbol) {
  int res = 0;
  if (check_simbol(simbol) == number) {
    res = number;
  } else if (check_simbol(simbol) == sign) {
    if (*simbol == '+') {
      res = sign;
    } else if (*simbol == '-') {
      if (check_unary_minus(simbol)) {
        res = 4;
      } else {
        res = sign;
      }
    } else if (*simbol == '*' || *simbol == '/') {
      res = 3;
    } else if (*simbol == '^') {
      res = 3;
    }
  } else if (*simbol == 'm') {
    if (!check_mod(simbol)) {
      res = 3;
    }
  } else if (*simbol == '~') {
    res = 4;
  }
  return res;
}

int check_unary_minus(const char* check_string) {
  int res = 0;
  check_string--;
  if (*check_string) {
    if (*check_string == '(') {
      res = 1;
    }
  } else {
    res = 1;
  }

  return res;
}

int check_steck_simbol(char simbol) {
  int res = 0;
  if (simbol == '-' || simbol == '+' || simbol == '*' || simbol == '/' ||
      simbol == '^' || simbol == 'm' || simbol == '~') {
    res = 1;
  }
  return res;
}

int check_steck_function(char simbol) {
  int res = 0;
  if (simbol == 's' || simbol == 'c' || simbol == 'm' || simbol == 't' ||
      simbol == 'g' || simbol == 'a' || simbol == 'n' || simbol == 'q' ||
      simbol == 'l' || simbol == 'L') {
    res = 1;
  }
  // s-sin, c-cos, m-mob, t-tan, g-atan, a-acos, n-asin,q-sqrt,l-ln,L-log
  return res;
}

void swap_minus(char* current_string) {
  for (; *current_string; current_string++) {
    if (*current_string == '-' && check_unary_minus(current_string))
      *current_string = '~';
  }
}

char converter_function_for_steck(const char* current_string) {
  // s-sin, c-cos, m-mob, t-tan, g-atan, a-acos, n-asin,q-sqrt,l-ln,L-log
  char res = '\0';
  if (*current_string == 's') {
    if (check_function(current_string) == 4) {
      res = 'q';
    } else {
      res = 's';
    }

  } else if (*current_string == 'c') {
    res = 'c';
  } else if (*current_string == 't') {
    res = 't';
  } else if (*current_string == 'a') {
    current_string++;
    if (*current_string == 'c') {
      res = 'a';
    } else if (*current_string == 's') {
      res = 'n';
    } else if (*current_string == 't') {
      res = 'g';
    }
  } else if (*current_string == 'l') {
    if (check_function(current_string) == 3) {
      res = 'l';
    } else {
      res = 'L';
    }
  }
  return res;
}

int check_simbol_for_parsing_string(const char* check_string) {
  int result = 99;
  char string_number[11] = "0123456789";
  for (int i = 0; i < 10; i++) {
    if (*check_string == string_number[i]) {
      result = number;
      break;
    }
  }
  if (result == 99) {
    if (check_steck_function(*check_string)) {
      result = function;
    } else if (check_simbol(check_string) == sign) {
      result = sign;
    } else if (check_simbol(check_string) == variable) {
      result = variable;
    } else if (check_simbol(check_string) == unary_minus) {
      result = unary_minus;
    }
  }
  return result;
}

double operation(char sign_or_function, double x, double y) {
  double res = 0;
  if (sign_or_function == '+') {
    res = x + y;
  } else if (sign_or_function == '-') {
    res = x - y;
  } else if (sign_or_function == '/') {
    res = x / y;
  } else if (sign_or_function == '*') {
    res = x * y;
  } else if (sign_or_function == 's') {
    res = sin(x);
  } else if (sign_or_function == 'c') {
    res = cos(x);
  } else if (sign_or_function == 'm') {
    // printf("\n %f, %f\n", x,y);
    res = (int)x % (int)y;
  } else if (sign_or_function == 't') {
    res = tan(x);
  } else if (sign_or_function == 'g') {
    res = atan(x);
  } else if (sign_or_function == 'a') {
    res = acos(x);
  } else if (sign_or_function == 'n') {
    res = asin(x);
  } else if (sign_or_function == 'q') {
    res = sqrt(x);
  } else if (sign_or_function == 'l') {
    res = log10(x);
  } else if (sign_or_function == 'L') {
    res = log(x);
  } else if (sign_or_function == '^') {
    res = pow(x, y);
  } else if (sign_or_function == '~') {
    res = -x;
  }
  return res;
  // s-sin, c-cos, m-mob, t-tan, g-atan, a-acos, n-asin,q-sqrt,l-ln,L-log
}

int check_dot(const char* check_string) {
  int error = 0;
  check_string--;
  if (check_simbol(check_string) != number) {
    error = 1;
  }
  check_string += 2;
  if (check_simbol(check_string) != number) {
    error = 1;
  }
  return error;
}

void result_number(double* current_res, const char* current_string) {
  // printf("HERE%s\n",current_string);
  int i = 1;
  int count = 0;
  double result = 0;

  while (check_simbol(current_string) == number) {
    current_string++;
    count++;
  }

  current_string--;

  while (count) {
    result += (double)((*current_string - 48) * i);

    i *= 10;
    count--;
    current_string--;
  }
  current_string++;

  while (check_simbol(current_string) == number) {
    current_string++;
    count++;
  }

  if (*current_string == '.') {
    current_string++;

    int new_count = 0;
    double new_i = 10;
    while (check_simbol(current_string) == number) {
      current_string++;
      new_count++;
    }

    current_string--;
    while (check_simbol(current_string) == number) {
      current_string--;
    }
    current_string++;

    while (new_count) {
      // printf("SIMBOl %lf\n %lf \n ",
      // (double)(*current_string-48)/new_i,new_i);
      result += (double)(*current_string - 48) / new_i;
      new_i *= 10;
      new_count--;
      current_string++;
    }
  }
  *current_res = result;
  // printf("HERE RES%f\n", result);
}

int check_pair_function(const char* current_string) {
  // s-sin, c-cos, m-mob, t-tan, g-atan, a-acos, n-asin,q-sqrt,l-ln,L-log
  int res = 1;
  if (*current_string == 's' || *current_string == 'c' ||
      *current_string == 't' || *current_string == 'g' ||
      *current_string == 'a' || *current_string == 'n' ||
      *current_string == 'l' || *current_string == 'L' ||
      *current_string == '~' || *current_string == 'q') {
    res = 0;
  }
  return res;
}

int check_variable(const char* check_string) {
  int error = 0;
  int count_dot = 0;
  if (check_simbol(check_string) != number &&
      check_simbol(check_string) != unary_minus &&
      check_simbol(check_string) != sign) {
    while (*check_string != ' ') {
      check_string++;
    }
    check_string++;
  }
  if (*check_string == '-') {
    check_string++;
  }
  // printf("\n%c\n", *check_string);
  while (*check_string) {
    if (check_simbol(check_string) != number && *check_string != '.') {
      error = 1;
    }
    if (*check_string == '.') {
      if (count_dot) {
        error = 1;
      } else {
        count_dot = 1;
      }
    }
    check_string++;
  }
  return error;
}

int check_last_mod(const char* check_string) {
  int error = 0;
  if (check_simbol(check_string + 3) == modd) {
    error = 1;
  }
  return error;
}
