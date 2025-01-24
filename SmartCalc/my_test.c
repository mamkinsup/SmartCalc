#include "my_heder.h"
double my_test(const char* current_string) {
  double res = 0;
  char test_string[200] = {'\0'};
  for (int i = 0; *current_string; current_string++, i++) {
    test_string[i] = *current_string;
  }
  swap_minus(test_string);
  if (check_string_correct(test_string) == 0) {
    char result_string[200] = {'\0'};

    // printf("%d", priority_operator(test_string + 3));
    parser(test_string, result_string);
    // printf("\nHERE %s\n", result_string);
    // printf("\n%s\n",result_string);
    // printf("\nHERE : %d , string = %s\n",
    // check_simbol_for_parsing_string(result_string+4)==function,
    // result_string);
    res = calculation(result_string);
    //  printf("%lf\n", res);
  } else {
    res = 0;
  }

  return res;
  //   printf("\n%lf", calculation(result_string));
}