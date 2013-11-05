/* 
 * File:   minunit.h
 * Author: angelo
 *
 * Created on November 2, 2013, 3:35 PM
 */

#ifndef PICUNIT_H
#define	PICUNIT_H

#include "picunit_conf.h"

#if RUN_TESTS

extern unsigned int tests_run, tests_failed;
extern const char * (*picunit_tests[]) ();

#define PICUNIT_INIT(x) unsigned int tests_run = 0; \
                        unsigned int tests_failed = 0; \
                        const char * (*picunit_tests[x])();

#define picunit_assert(message, test) do { if (!(test)) return message; } while (0)
#define picunit_run_test(test) do { const char *message = test(); tests_run++; \
                                if (message) return message; } while (0)
#define RUN_ALL_TESTS() do { char str[MSG_BUFFER]; \
                             for(tests_run = 0; tests_run < (sizeof(picunit_tests)/sizeof(picunit_tests[0]));tests_run++ ){ \
                                const char *result = picunit_tests[tests_run](); \
                                if (result != 0) { \
                                    sprintf(str, "TEST %d FAILED: %s\n", tests_run, result); \
                                    PRINT_USART(str); \
                                    tests_failed++; \
                                } \
                                else { \
                                    sprintf(str, "TEST %d PASSED\n", tests_run); \
                                    PRINT_USART(str); \
                                } \
                             } \
                             sprintf(str, "ALL TESTS %d, FAILED %d\n", tests_run, tests_failed); \
                             PRINT_USART(str); } while (0)
#else
#define PICUNIT_INIT(x)
#endif

#endif	/* PICUNIT_H */

