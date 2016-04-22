/* 
 * File:   LCD4bit.c
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

#include "LCD4bit.h"

// Available Functions:
void lcd_init(); // Initializes the LCD 
void lcdclr(); // Clears the current line
void firstline(); // Sets the cursor to the first line
void secondline(); // Sets the cursor to the second line
void lcdcmd(char); // Sends a valid command to the LCD
void lcddata(char); // Sends a single char to the LCD for display
void lcdstr(char[]); // Sends a string to the LCD for display


//Initialization to use LCD with 4-bit mode
void lcd_init(void){
   __delay_ms(5);
   lcdcmd(0x02);	//Initilize the LCD in 4-bit mode
   lcdcmd(0x28);        //
   lcdcmd(0x0C);	// Display ON cursor OFF
   lcdcmd(0x80);	// Cursor to First line First Position
   lcdcmd(0x01);	// Clear the LCD
}


void lcdcmd(char cmd){
    lcdport=(cmd & 0xF0); // send high nibble
    rs=0;
    rw=0;
    en=1;
    __delay_ms(10);
    en=0;

    __delay_us(10); // wait

    lcdport=((cmd<<4) & 0xF0); // send low nibble
    rs=0;
    rw=0;
    en=1;
    __delay_ms(10);
    en=0;
    __delay_ms(1);
}

void lcddata(char data){
    
    lcdport=(data & 0xF0);   // send high nibble
    rs=1;
    rw=0;
    en=1;
    __delay_ms(10);
    en=0;

    __delay_us(10); // wait

    lcdport=((data<<4) & 0xF0); // send low nibble
    rs=1;
    rw=0;
    en=1;
    __delay_ms(10);
    en=0;
    __delay_ms(1);
} 

void lcdstr(char str[]){
    for(int i=0; i<strlen(str); i++){
        lcddata(str[i]);
  }
}

void lcdclr(void){
    lcdcmd(0x01); // Command to clear LCD
}

void firstline(void){
    lcdcmd(0x80); // Command to go to first line of LCD
}

void secondline(void){
    lcdcmd(0xC0); // Command to go to second line of LCD
}
