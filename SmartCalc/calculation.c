#include "my_heder.h"
double calculation(const char* parsing_string) {
  double res = 0;
  elem_number* my_steck;
  for (; *parsing_string; parsing_string++) {
    if (check_simbol_for_parsing_string(parsing_string) == number) {
      // printf("\nSIMBOL = %c\n", *parsing_string);
      double value = 0;
      result_number(&value, parsing_string);
      push_number(&my_steck, value);
      // printf("\n value %lf\n", value);
      while (check_simbol_for_parsing_string(parsing_string) == number) {
        parsing_string++;
      }
      if (*parsing_string == '.') {
        parsing_string++;
        while (check_simbol_for_parsing_string(parsing_string) == number) {
          parsing_string++;
        }
      }
      parsing_string--;
    } else if (check_simbol_for_parsing_string(parsing_string) == sign) {
      double y = 0;
      double x = 0;
      y = pop_number(&my_steck);
      x = pop_number(&my_steck);

      push_number(&my_steck, operation(*parsing_string, x, y));
    } else if (check_simbol_for_parsing_string(parsing_string) == function ||
               check_simbol_for_parsing_string(parsing_string) == unary_minus) {
      if (check_pair_function(parsing_string)) {
        double y = 0;
        double x = 0;
        y = pop_number(&my_steck);
        x = pop_number(&my_steck);
        // printf("\nx=%f y=%f ==%f\n", x,y,operation(*parsing_string,x,y));
        push_number(&my_steck, operation(*parsing_string, x, y));
      } else {
        double x = 0;
        x = pop_number(&my_steck);
        // printf("\nx=%f ==%f\n", x,operation(*parsing_string,x,0));
        push_number(&my_steck, operation(*parsing_string, x, 0));
      }
    }
  }
  res = pop_number(&my_steck);
  return res;
}
