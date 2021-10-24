/*	Author: Richard Tobing, rlumb001@ucr.edu
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #5  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
//we do not include RIMS.h

enum states{wait,cMin,cPlus,clear}state;
int main(void) {
	DDRA = 0x00; PORTA = 0x00;
	//DDRB = 0xFF; PORTB = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char A,prev;
	prev = 0;
	state = wait;
	//unsigned char cnt = 7;
	signed long cnt = 7;

    while (1) {
	    A = (~PINA) & 3;
	    //cnt = 7;
	    
	    switch(state){
	    	case wait:
				prev = 0;
				if(A==3){state = clear; }
				else if(A==1){state = cPlus; }
				else if(A==2){state = cMin; }
				else{state = wait; }
				break;
		case cPlus:
				prev = 1;
				if(A==3){state = clear; }
				else if(A==1){state = cPlus; }
				else if(A==2){state = cMin; }
				else{state = wait; }
				break;
		case cMin:
				prev = 2;
				if(A==3){state = clear; }
				else if(A==1){state = cPlus; }
				else if(A==2){state = cMin; }
				else{state = wait; }
				break;
		case clear:
				prev = 4;
				if(A==0){state = wait; }
				else{state = clear; }
				break;
	    }

	    //-----------------------------------------------------------

	    switch(state){
		case wait:
			break;

		case cPlus:
			if((prev!=1)&&(cnt<9)){cnt++; }
			break;

		case cMin:
			if((prev!=2)&&(cnt>0)){
				if(cnt ==0){cnt = 0; }
				else{cnt = cnt -1; }
			}
			break;

		case clear:
			cnt = 0;
			break;
	    }

	    if(cnt > 9){PORTC = 9; }
	    else if(cnt < 0){PORTC = 0; }
	    else{PORTC = cnt; }
	    //PORTC = cnt;
		//PORTC = 0;
    }
    return 0;
}
