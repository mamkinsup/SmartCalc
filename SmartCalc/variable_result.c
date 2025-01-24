#include "my_heder.h"
double variable_result(const char* current_string, const char* variable) {
  int i = 0;
  int count = 0;
  char test_string[200] = {'\0'};
  double res = 0;
  if (check_variable(variable) || check_string_correct(current_string)) {
  } else {
    // printf("\n%d\n",check_simbol(variable)==sign );
    if (check_simbol(variable) != number && check_simbol(variable) != sign) {
      while (*variable != ' ') {
        variable++;
      }

      variable++;
    }
    for (; *current_string; current_string++) {
      if (*current_string == 'x') {
        test_string[i] = '(';
        i++;
        for (; *variable; variable++) {
          test_string[i] = *variable;
          count++;
          i++;
        }
        test_string[i] = ')';
        i++;
        while (count) {
          variable--;
          count--;
        }

      } else {
        test_string[i] = *current_string;
        i++;
      }
    }

    char result_string[200] = {'\0'};

    swap_minus(test_string);
    parser(test_string, result_string);
    //  printf("VAR %s\n",test_string);
    res = calculation(result_string);
    // double res=99;
  }
  return res;
}