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

#ifndef MINUNIT_H_H
#define	MINUNIT_H_H

/*
 * Configuration Options
 */
#ifndef RUN_TESTS
#define RUN_TESTS 0 //enable/disable testing compile and execution
#endif

#define PRINT_USART puts1USART  //select which usart will be used for debug
#define MSG_BUFFER  100         //buffer length for single test message

#endif	/* MINUNIT_H_H */

