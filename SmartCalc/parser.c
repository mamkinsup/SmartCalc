#include "my_heder.h"
void parser(const char* introductory_line, char* output) {
  if (check_null(introductory_line) ||
      check_string_correct(introductory_line)) {
  } else {
    elem* my_steck;
    int count_steck = 0;
    // char output[200] = {'\0'};
    int i = 0;
    for (; i < 200 && *introductory_line; introductory_line++) {
      if (check_simbol(introductory_line) == number ||
          *introductory_line == '.') {
        while (
            (check_simbol(introductory_line) == number && *introductory_line) ||
            *introductory_line == '.') {
          output[i] = *introductory_line;
          i++;
          introductory_line++;
        }
        introductory_line--;
        output[i] = ' ';
        i++;
      } else if (check_simbol(introductory_line) == function) {
        push(&my_steck, converter_function_for_steck(introductory_line));
        introductory_line += check_function(introductory_line) - 1;
        count_steck++;
      } else if (check_simbol(introductory_line) == parenthesis) {
        if (*introductory_line == '(') {
          push(&my_steck, *introductory_line);
          count_steck++;
        } else {
          if (count_steck) {
            while (my_steck->value != '(') {
              output[i] = pop(&my_steck);
              count_steck--;
              i++;
            }
          }
          if (count_steck) {
            pop(&my_steck);
            count_steck--;
          }
          if (count_steck) {
            if (check_steck_function(my_steck->value)) {
              output[i] = pop(&my_steck);
              count_steck--;
              i++;
            }
          }
        }
      } else if (check_simbol(introductory_line) == sign ||
                 check_simbol(introductory_line) == unary_minus ||
                 check_simbol(introductory_line) == modd) {
        if (count_steck) {
          //  printf("\nsimbol: %c, prior:
          //  %d",my_steck->value,my_steck->priority);
          while (check_steck_simbol(my_steck->value) &&
                 my_steck->priority >= priority_operator(introductory_line)) {
            // printf("\nsteck simbol = %c , priority = %d; input simbol = %c
            // priority = %d",
            // my_steck->value,my_steck->priority,*introductory_line,priority_operator(introductory_line));
            output[i] = pop(&my_steck);
            count_steck--;
            i++;
            if (!count_steck) {
              break;
            }
          }
        }
        //  printf("\nHERE= %d %c\n", priority_operator(introductory_line),
        //          *introductory_line);
        push(&my_steck, *introductory_line);

        count_steck++;
      }
    }
    while (count_steck) {
      output[i] = pop(&my_steck);
      count_steck--;
      i++;
    }
    // printf("\n%s\n", output);
  }
}