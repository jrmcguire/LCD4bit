/* 
 * File:   LCD4bit.h
 * Author: Jason McGuire (j.mcguire.2015@ieee.org)
 * Description: A sample program showing how to configure
 * and use the LCD4bit library. Used on a PIC18F25K20, you 
 * can use it on any PIC18F and possibly more.
 * Created on September 25, 2015, 9:08 AM
 
License Information:
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
 
 
 */
 
#ifndef LCD4BIT_H
#define LCD4BIT_H
 
#include <string.h>
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

// PIC LCD Frequency
#define _XTAL_FREQ  1000000

// LCD Control Pins - Change if using different ones
#define rs LATBbits.LB2
#define rw LATBbits.LB1
#define en LATBbits.LB0


//LCD Data pins - Change if using different ones
#define lcdport LATC

/*
 * Initializes the LCD: 
 * Display ON, cursor OFF, First Line
 */
void lcd_init();

/*
 * Clears the LCD Screen 
 * On the Current Line
 */
void lcdclr();

/*
 * Puts the cursor on the first line
 * Clear or Write will take place here
 */
void firstline();

/*
 * Puts the cursor on the second line
 * Clear or Write will take place here
 */
void secondline();

/*
 * Sends a LCD command to the LCD
 * See data sheet for commands
 */
void lcdcmd(char);

/*
 * Sends a single char to the LCD 
 */
void lcddata(char);

/*
 * Sends a string to the LCD
 * Note: LCD size is 16 chars long
 */
void lcdstr(char[]);

#endif // LCD4BIT_H