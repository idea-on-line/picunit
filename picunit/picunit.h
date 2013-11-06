/* 
 * The MIT License (MIT)
 * 
 * Copyright (c) <2013> IDEA SOC. COOP.
 * 
 * Author: Angelo Compagnucci <a.compagnucci@idea-on-line.it>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef PICUNIT_H
#define	PICUNIT_H

#include "picunit_conf.h"

#if RUN_TESTS
#include <batchdebug.h>

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

