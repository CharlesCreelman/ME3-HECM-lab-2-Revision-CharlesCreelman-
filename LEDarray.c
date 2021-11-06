#include <xc.h>
#include "LEDarray.h"

/************************************
/ LEDarray_init
/ Function used to initialise pins to drive the LEDarray
************************************/
void LEDarray_init(void)
{
    TRISG = 0b11111100;	//set up TRIS registers for pins connected to LED array
    TRISA = 0b11001011; //the 0's are set to output pins, this sets up the LED as well as the LDR outputs
    TRISF = 0b10111110; //the 0's are the pins connected to the LED array, this sets the TRIS for the LED and the button
    TRISB = 0b11111100;

    LATA = 0b00000000; //set up LAT registers for pins connected to LED array
    LATG = 0b00000000; //this is setting them all to 0 for now
    LATF = 0b00000100; //this sets the LAT for the LED and the button
    LATB = 0b00000000;

            //set initial output LAT values (they may have random values when powered on)
}

/************************************
/ LEDarray_disp_bin
/ Function used to display a number on the LED array in binary
************************************/
void LEDarray_disp_bin(unsigned int number)
{
    if(number>=0b00000001) {LATBbits.LATB1=1;} else {LATBbits.LATB1=0;}
    if(number>=0b00000010) {LATBbits.LATB0=1;} else {LATBbits.LATB0=0;}
    if(number>=0b00000100) {LATFbits.LATF0=1;} else {LATFbits.LATF0=0;}
    if(number>=0b00001000) {LATAbits.LATA5=1;} else {LATAbits.LATA5=0;}
    if(number>=0b00010000) {LATAbits.LATA4=1;} else {LATAbits.LATA4=0;}
    if(number>=0b00100000) {LATFbits.LATF6=1;} else {LATFbits.LATF6=0;}
    if(number>=0b01000000) {LATAbits.LATA2=1;} else {LATAbits.LATA2=0;}
    if(number>=0b10000000) {LATGbits.LATG1=1;} else {LATGbits.LATG1=0;}
    //some code to turn on/off the pins connected to the LED array
	//if statements and bit masks can be used to determine if a particular pin should be on/off
	//see Readme.md for examples
}

/************************************
/ Function LEDarray_disp_dec
/ Used to display a number on the LEDs
/ where each LED is a value of 10
************************************/
void LEDarray_disp_dec(unsigned int number)
{
	unsigned int disp_val;
	
	//some code to manipulate the variable number into the correct
	//format and store in disp_val for display on the LED array

	LEDarray_disp_bin(disp_val); 	//display value on LED array
}


/************************************
/ LEDarray_disp_PPM
/ Function used to display a level on the LED array with peak hold
/ cur_val is the current level from the most recent sample, and max is the peak value for the last second
/ these input values need to calculated else where in your code
************************************/
void LEDarray_disp_PPM(unsigned int cur_val, unsigned int max)
{
	unsigned int disp_val;
	
	// some code to format the variable cur_val and max, store in disp_val for display on the LED array
	// hint: one method is to manipulate the variables separately and then combine them using the bitwise OR operator

	LEDarray_disp_bin(disp_val);	//display value on LED array
}

