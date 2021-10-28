#pragma config FEXTOSC = HS     // External Oscillator mode Selection bits (HS (crystal oscillator) above 8 MHz; PFM set to high power)
#pragma config RSTOSC = EXTOSC_4PLL// Power-up default value for COSC bits (EXTOSC with 4x PLL, with EXTOSC operating per FEXTOSC bits)
#pragma config WDTE = OFF        // WDT operating mode (WDT enabled regardless of sleep)

#include <xc.h>
#include "LEDarray.h"
#include "ADC.h"
#include <math.h>

#define _XTAL_FREQ 64000000 //note intrinsic _delay function is 62.5ns at 64,000,000Hz  
//----------------------------------------------------------------------------

//Exercise 1.1

//int main(void) 
//{
//	unsigned int count=0;
//    LEDarray_init();
//  
//    while (1) {
//		if(PORTFbits.RF2) {count++;}// increment count
//		if (count>511) {count=0;} //reset a when it gets too big
//		LEDarray_disp_bin(count); //output a on the LED array in binary
//		__delay_ms(50); // Delay so human eye can see change
//    }
//}

//----------------------------------------------------------------------------

//Exercise 1.2

//Making the LED go back and forth along the array
//int main(void) 
//{
//	unsigned int count=1;
//    LEDarray_init();
//    unsigned int end = 1;// creating a placeholder to represent which end the LED hit last
//    LEDarray_disp_bin(count);
//    __delay_ms(200);
//    while (1) { //Loop lasting forever
//        if(count==1) {end=1;}// When the counter is 1, the end int is represents it's just come from the 1 side of the LED array
//        if(count==256) {end=256;}// When the counter is 256, the end int is represents it's just come from the 1 side of the LED array
//        if(PORTFbits.RF2 && end==256) {count=count/2;}// Going back the other way (decreasing))
//		if(PORTFbits.RF2 && end==1) {count=count*2;}// increment count
//      //  if (count>511) {count=0;} //reset a when it gets too big
//		LEDarray_disp_bin(count); //output a on the LED array in binary
//		__delay_ms(50); // Delay so human eye can see change
//    }
//}

//----------------------------------------------------------------------------

//Exercise 1.3

//int main(void) 
//{
//	unsigned int count=0;
//    LEDarray_init();
//  
//    while (1) {
//		if(PORTFbits.RF2==0) {count++;}// increment count
//		if (count>511) {count=0;} //reset a when it gets too big
//		LEDarray_disp_bin(count); //output a on the LED array in binary
//		__delay_ms(300); // Delay so human eye can see change
//    }
//}

//----------------------------------------------------------------------------

//Exercise 1.4
//Questions for GTA: Why does this work? Why does it continuously
//                   increase the count when there is a delay??
//                   Delay only kicks in when the button is clicked
//                   Once.

//int main(void) 
//{
//	unsigned int count=0;
//    LEDarray_init();
//  
//    while (1) {
//		if(PORTFbits.RF2==0) {count++;}// increment count
//		if (count>511) {count=0;} //reset a when it gets too big
//		LEDarray_disp_bin(count); //output a on the LED array in binary
//		__delay_ms(500); // Delay so human eye can see change
//    }
//}

//----------------------------------------------------------------------------

//Exercise 1.5
//Questions for GTA:

//int main(void) 
//{
//	unsigned int count=0;
//    LEDarray_init();
//  
//    while (1) {
//		if(PORTFbits.RF2) {count++;}// increment count
//		if (count>90) {count=0;} //reset a when it gets too big
//		LEDarray_disp_dec(count); //output a on the LED array in binary
//		__delay_ms(50); // Delay so human eye can see change
//    }
//}

//----------------------------------------------------------------------------

//Exercise 2.1
//Questions for GTA:


//int main(void)
//{
//    unsigned int value = 0b000000000;
//    ADC_init(); // setting the pins (initialising)
//    LEDarray_init();// setting pins (initialising)
//    while(1){
//        value = ADC_getval(); // returns the value of the LDR resistance
//        LEDarray_disp_bin(value);// displays the resistance value
//        __delay_ms(500);
//    }
//}

//----------------------------------------------------------------------------

//Exercise 2.2
//Questions for GTA:

//int main(void)
//{
//    unsigned int value = 0b000000000;
//    unsigned int divider = floor(255/9);
//    ADC_init(); // setting the pins (initialising)
//    LEDarray_init();// setting pins (initialising)
//    while(1){
//        value = ADC_getval(); // returns the value of the LDR resistance
//        LEDarray_disp_bin(pow(2,floor(value/divider)));// displays the resistance value
//        __delay_ms(500);
//    }
//}

//----------------------------------------------------------------------------

//Exercise 3
//Questions for GTA:
//nearly got it working
void main(void){
    
    ADC_init(); // setting the pins (initialising)
    LEDarray_init();// setting pins (initialising)
    unsigned int curvalue = 0b000000000;
    unsigned int maxvalue = 0b000000000;
    while(1){
        curvalue = ADC_getval();
        if(curvalue>maxvalue) {maxvalue=curvalue;}
        LEDarray_disp_PPM(curvalue, maxvalue);
        maxvalue=maxvalue-(255/9);
        __delay_ms(1000);
    }
}