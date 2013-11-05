/* 
 * File:   minunit_h.h
 * Author: angelo
 *
 * Created on November 3, 2013, 4:01 PM
 */

#ifndef MINUNIT_H_H
#define	MINUNIT_H_H

/*
 * Configuration Options
 */
#ifndef RUN_TESTS
#define RUN_TESTS 1 //enable/disable testing compile and execution
#endif

#define PRINT_USART puts1USART  //select which usart will be used for debug
#define MSG_BUFFER  100         //buffer length for single test message

#endif	/* MINUNIT_H_H */

