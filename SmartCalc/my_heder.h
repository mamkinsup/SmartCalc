#ifndef MY_HEDER_H
#define MY_HEDER_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct one_elem {
  char value;
  struct one_elem* next;
  int priority;

} elem;

typedef struct two_elem {
  double value;
  struct two_elem* next;
  int priority;
} elem_number;

enum num { number, sign, parenthesis, unary_minus, modd, function, variable };
enum result { incorrect_input, OK };

// help functions
int check_last_mod(const char* check_string);
int check_variable(const char* check_string);
void result_number(double* current_res, const char* current_string);
int check_dot(const char* check_string);
double operation(char sign_or_function, double x, double y);
int check_simbol_for_parsing_string(const char* check_string);
char converter_function_for_steck(const char* current_string);
void swap_minus(char* current_string);
int check_steck_function(char simbol);
int check_steck_simbol(char simbol);
int check_unary_minus(const char* check_string);
int priority_operator(const char* simbol);
double pop_number(elem_number** current_elem);
int pop(elem** current_elem);
int prioryty_for_steck(char* simbol);
int push_number(elem_number** current_elem, double current_value);
int push(elem** current_elem, char current_value);
int check_string_correct(const char* check_string);
int check_presens_value(const char* check_string);
int check_mod(const char* check_string);
int check_parenthesis(char char_parenthesis);
int check_simbol(const char* check_string);
int check_null(const char* check_sctring);
int check_pair_function(const char* current_string);
int check_function(const char* check_string);

double my_test(const char* current_string);
void parser(const char* introductory_line, char* output);
double variable_result(const char* current_string, const char* variable);
double calculation(const char* parsing_string);
#endif  //  SRC_MY_HEDER_H_
