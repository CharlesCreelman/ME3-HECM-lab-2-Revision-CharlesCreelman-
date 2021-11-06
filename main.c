#pragma config FEXTOSC = HS     // External Oscillator mode Selection bits (HS (crystal oscillator) above 8 MHz; PFM set to high power)
#pragma config RSTOSC = EXTOSC_4PLL// Power-up default value for COSC bits (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)
#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep)

#include <xc.h>
#include "LEDarray.h"
#include "ADC.h"

#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  

//Exercise 1

//void main(void) 
//{
//	unsigned int count=0;
//    LEDarray_init(); //included in this is the init for the button
//    ANSELFbits.ANSELF2=0; //turn off analogue input on pin 
//    LATDbits.LATD7=0;   //set initial output state for left LED
//    TRISDbits.TRISD7=0; //set TRIS value for pin (output)
//    int i = 0;
//    while (1) {
//        while(!PORTFbits.RF2){
//            i = 1;
//        }
//        while(i) {
//            if(PORTFbits.RF2){
//            count++; //increment count
//            i=0;
//            if (count>80) {count=1;} //reset a when it gets too big
//            LEDarray_disp_bin(count); //output a on the LED array in binary
//            //__delay_ms(50); // Delay so human eye can see change
//            if (PORTFbits.RF2) {LATDbits.LATD7 = !LATDbits.LATD7;} //toggle LEDS, one should go off whilst the other turns on
//            }
//        }
//
//    }
//}

// Exercise 2

void main(void){
    LEDarray_init(); //included in this is the init for the LDR
    ADC_init();
    while(1){
        int value = ADC_getval();
        LEDarray_disp_bin(value);
    }
}

//CBA to do exercise 3