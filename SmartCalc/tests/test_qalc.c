#include "s21_test_calc.h"

START_TEST(add1) {
  char start_line[200] = "2+4";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 2 + 4, 1e-6);
  ck_assert_int_eq(res, 6);
}
END_TEST

START_TEST(add2) {
  char start_line[200] = "2++4";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add3) {
  char start_line[200] = "2+(-2)+4";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 2 + (-2) + 4, 1e-6);
  ck_assert_int_eq(res, 4);
}
END_TEST

START_TEST(add4) {
  char start_line[200] = "2+(-2)-(-sin(2))+4";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 2 + (-2) - (-sin(2)) + 4, 1e-6);
  ck_assert_int_eq(res, 4);
}
END_TEST

START_TEST(add5) {
  char start_line[200] = "9mod4";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 9 % 4, 1e-6);
  ck_assert_int_eq(res, 9 % 4);
}
END_TEST

START_TEST(add6) {
  char start_line[200] = "9myd4";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add7) {
  char start_line[200] = "9mok4";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add8) {
  char start_line[200] = "acos(0.2)";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, acos(0.2), 1e-6);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(add9) {
  char start_line[200] = "asin(0.2)";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, asin(0.2), 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add10) {
  char start_line[200] = "acon(0.2)";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add11) {
  char start_line[200] = "asos(0.2)";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add12) {
  char start_line[200] = "tan(2)";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, tan(2), 1e-6);
  ck_assert_int_eq(res, -2);
}
END_TEST

START_TEST(add13) {
  char start_line[200] = "tac(2)";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add14) {
  char start_line[200] = "tyn(2)";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add15) {
  char start_line[200] = "sic(2)";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add16) {
  char start_line[200] = "con(2)";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add17) {
  char start_line[200] = "atan(2)";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, atan(2), 1e-6);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(add18) {
  char start_line[200] = "atac(2)";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add19) {
  char start_line[200] = "asic(2)";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add20) {
  char start_line[200] = "ln(2)";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, log(2), 1e-6);
  ck_assert_int_eq(res, (int)log(2));
}
END_TEST

START_TEST(add21) {
  char start_line[200] = "log(2)";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, log10(2), 1e-6);
  ck_assert_int_eq(res, (int)log10(2));
}
END_TEST

START_TEST(add22) {
  char start_line[200] = "lon(2)";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add23) {
  char start_line[200] = "lk(2)";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add24) {
  char start_line[200] = "lk()(2)";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add25) {
  char start_line[200] = "lk(()(2)";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add26) {
  char start_line[200] = "2sin(2)";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add27) {
  char start_line[200] = "2-mod(2)";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add28) {
  char start_line[200] = "()";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add29) {
  char start_line[200] = ")9";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add30) {
  char start_line[200] = "(2mod)";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add31) {
  char start_line[200] = "(2+)";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add32) {
  char start_line[200] = "(2+-2)";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add33) {
  char start_line[200] = "2--1";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add34) {
  char start_line[200] = "(2-)())-1";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add35) {
  char start_line[200] = "2^2";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, pow(2, 2), 1e-6);
  ck_assert_int_eq(res, (int)pow(2, 2));
}
END_TEST

START_TEST(add36) {
  char start_line[200] = "2*2";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 2 * 2, 1e-6);
  ck_assert_int_eq(res, 2 * 2);
}
END_TEST

START_TEST(add37) {
  char start_line[200] = "2/0.23";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 2 / 0.23, 1e-6);
  ck_assert_int_eq(res, (int)2 / 0.23);
}
END_TEST

START_TEST(add38) {
  char start_line[200] = "2/x";
  char x_line[200] = "in 25";
  double res = 0;
  res = variable_result(start_line, x_line);
  ck_assert_double_eq_tol(res, 2.0 / 25, 1e-6);
  ck_assert_int_eq(res, (int)2 / 25);
}
END_TEST

START_TEST(add39) {
  char start_line[200] = "2^x";
  char x_line[200] = "in 3";
  double res = 0;
  res = variable_result(start_line, x_line);
  ck_assert_double_eq_tol(res, 8, 1e-6);
  ck_assert_int_eq(res, (int)8);
}
END_TEST

START_TEST(add40) {
  char start_line[200] = "(2^x+x-x^2)+7.25-(-2)";
  char x_line[200] = "in 3";
  double res = 0;
  res = variable_result(start_line, x_line);
  ck_assert_double_eq_tol(res, (pow(2, 3) + 3 - pow(3, 2)) + 7.25 - (-2), 1e-6);
  ck_assert_int_eq(res, (int)(pow(2, 3) + 3 - pow(3, 2)) + 7.25 - (-2));
}
END_TEST

START_TEST(add41) {
  char start_line[4] = "sin";
  double res = 0;
  res = my_test(start_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add42) {
  char start_line[200] = "x++x";
  char x_line[200] = "in 3";
  double res = 0;
  res = variable_result(start_line, x_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add43) {
  char start_line[200] = "2+n.2";
  char x_line[200] = "in 3";
  double res = 0;
  res = variable_result(start_line, x_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add44) {
  char start_line[200] = "2+x2";
  char x_line[200] = "in 3";
  double res = 0;
  res = variable_result(start_line, x_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add45) {
  char start_line[200] = "2+x";
  char x_line[200] = "in 3q";
  double res = 0;
  res = variable_result(start_line, x_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add46) {
  char x_line[200] = "-0.2";
  double res = 0;
  res = check_variable(x_line);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(add47) {
  char x_line[200] = "2*(-2)";
  double res = 0;
  res = my_test(x_line);
  ck_assert_double_eq_tol(res, 2 * (-2), 1e-6);
  ck_assert_int_eq(res, 2 * (-2));
}
END_TEST

START_TEST(add48) {
  char x_line[200] = "sqrt(4)";
  double res = 0;
  res = my_test(x_line);
  ck_assert_double_eq_tol(res, sqrt(4), 1e-6);
  ck_assert_int_eq(res, (int)sqrt(4));
}
END_TEST

START_TEST(add49) {
  char x_line[200] = "2^(sqrt(4)+sqrt(8))";
  double res = 0;
  res = my_test(x_line);
  ck_assert_double_eq_tol(res, pow(2, (sqrt(4) + sqrt(8))), 1e-6);
  ck_assert_int_eq(res, (int)pow(2, (sqrt(4) + sqrt(8))));
}
END_TEST

Suite *suite_test_calc(void) {
  Suite *s = suite_create("suite_test_calc");
  TCase *tc = tcase_create("test_calc_tc");

  tcase_add_test(tc, add1);
  tcase_add_test(tc, add2);
  tcase_add_test(tc, add3);
  tcase_add_test(tc, add4);
  tcase_add_test(tc, add5);
  tcase_add_test(tc, add6);
  tcase_add_test(tc, add7);
  tcase_add_test(tc, add8);
  tcase_add_test(tc, add9);
  tcase_add_test(tc, add10);
  tcase_add_test(tc, add11);
  tcase_add_test(tc, add12);
  tcase_add_test(tc, add13);
  tcase_add_test(tc, add14);
  tcase_add_test(tc, add15);
  tcase_add_test(tc, add16);
  tcase_add_test(tc, add17);
  tcase_add_test(tc, add18);
  tcase_add_test(tc, add19);
  tcase_add_test(tc, add20);
  tcase_add_test(tc, add21);
  tcase_add_test(tc, add22);
  tcase_add_test(tc, add23);
  tcase_add_test(tc, add24);
  tcase_add_test(tc, add25);
  tcase_add_test(tc, add26);
  tcase_add_test(tc, add27);
  tcase_add_test(tc, add28);
  tcase_add_test(tc, add29);
  tcase_add_test(tc, add30);
  tcase_add_test(tc, add31);
  tcase_add_test(tc, add32);
  tcase_add_test(tc, add33);
  tcase_add_test(tc, add34);
  tcase_add_test(tc, add35);
  tcase_add_test(tc, add36);
  tcase_add_test(tc, add37);
  tcase_add_test(tc, add38);
  tcase_add_test(tc, add39);
  tcase_add_test(tc, add40);
  tcase_add_test(tc, add41);
  tcase_add_test(tc, add42);
  tcase_add_test(tc, add43);
  tcase_add_test(tc, add44);
  tcase_add_test(tc, add45);
  tcase_add_test(tc, add46);
  tcase_add_test(tc, add47);
  tcase_add_test(tc, add48);
  tcase_add_test(tc, add49);
  suite_add_tcase(s, tc);
  return s;
}
