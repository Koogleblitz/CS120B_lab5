/*	Author: Richard Tobing, rlumb001@ucr.edu
 *  Partner(s) Name: 
 *	Lab Section:021
 *	Assignment: Lab #5  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
int main(void) {
    // A and B are inputs, C is output
    DDRA = 0x00; PORTA = 0x00;
    DDRB = 0x00; PORTB = 0x00;
    DDRC = 0xFF; PORTC = 0x00;

    unsigned char Aye,A;
	unsigned char Cee = 0;


    while (1) {
		A = ~PINA;
		Aye = A & 15;
		Cee = 0;

		if(Aye <= 1){
			Cee = 64;
		}
		else if(Aye <= 2){
			Cee = 32;
			Cee = Cee + 64;
		}
		else if(Aye <= 4){
			Cee = 32 + 16;
			Cee = Cee + 64;
		}
		else if(Aye <= 6){
			Cee = 32 + 16 + 8;
		}
		else if(Aye <= 9){
			Cee = 32 + 16 + 8 +4;
		}
		else if(Aye <= 12){
			Cee = 32 + 16 + 8 + 4 +2;
		}
		else{
			Cee = 32 + 16 + 8 + 4 + 2 + 1;
		}

		PORTC = Cee;
    }
	
   
 return 0;
}


