/* 
 * File:   main.c
 * Author: Angelo Compagnucci <a.compagnucci@idea-on-line.it>
 *
 * Created on November 5, 2013, 11:57 AM
 */

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <usart.h>

// Including PICUNIT
#include "picunit.h"

int check_data_from_serial_protocol(int len);

static unsigned char BUFFER[64];

//WE HAVE 4 TOTAL TESTS
PICUNIT_INIT(4)

/*
 * Test functions
 */
#if RUN_TESTS
static const char * test_foo(){
    picunit_assert("test1", 1==1);
    picunit_assert("test2", 2==2);
    picunit_assert("test3", 3==3);
    return 0;
}

static const char * test_bar(){
    picunit_assert("Wrong math!", 1+1==3);
    return 0;
}

//SOME MORE COMPLEX EXAMPLE
static const char * test_check_data_from_serial_protocol(){
    // Loading dummy data
    int res;

    BUFFER[0] = 'A';
    BUFFER[1] = 'B';
    BUFFER[2] = 'C';
    BUFFER[3] = 0xBF;

    res = check_data_from_serial_protocol(4);

    picunit_assert("check_data_from_serial_protocol broken!", res==0);
    return 0;
}

static const char * test_check_data_from_serial_protocol_wrong(){
    // Purposefully wrong CRC
    int res;

    BUFFER[0] = 'A';
    BUFFER[1] = 'B';
    BUFFER[2] = 'C';
    BUFFER[3] = 'D';
    BUFFER[4] = 0xBF;

    res = check_data_from_serial_protocol(5);

    picunit_assert("check_data_from_serial_protocol broken!", res==0);
    return 0;
}
#endif

int main() {

#if RUN_TESTS
    // Assigning testing functions
    picunit_tests[0] = test_foo;
    picunit_tests[1] = test_bar;
    picunit_tests[2] = test_check_data_from_serial_protocol;
    picunit_tests[3] = test_check_data_from_serial_protocol_wrong;

    // CONFIGURE UART FOR TESTS OUTPUT
    Open1USART(USART_TX_INT_OFF &
       USART_RX_INT_OFF &
       USART_BRGH_HIGH &
       USART_CONT_RX &
       USART_EIGHT_BIT &
       USART_ASYNCH_MODE &
       USART_ADDEN_OFF,
       8);

    RUN_ALL_TESTS();
#endif

    while(1){
        //HERE GOES YOUR MAIN LOOP
    }
    return (EXIT_SUCCESS);
}

int check_data_from_serial_protocol(int len){
    //In this dummy protocol we have a buffer and a tail xor crc
    unsigned char i, crc;
    crc = 0xff;

    for(i=0; i<len-1; i++){
        crc ^= BUFFER[i];
    }

    if (crc == BUFFER[i])
        return 0;

    return -1;
}

