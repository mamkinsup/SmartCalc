#ifndef SRC_S21_TEST_CALC_H_
#define SRC_S21_TEST_CALC_H_
#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../my_heder.h"

Suite *suite_test_calc(void);

void run_tests(void);
void run_testcase(Suite *testcase);

#endif  //  SRC_S21_TEST_CALC_H_
