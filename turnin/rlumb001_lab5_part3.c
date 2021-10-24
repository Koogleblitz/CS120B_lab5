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

//enum states{wait,cMin,cPlus,clear}state;
int main(void) {
	DDRA = 0x00; PORTA = 0x00;
	DDRB = 0xFF; PORTB = 0x00;

	unsigned char A,prev,state,B,flag;
	prev = 0;
	state = 0;
	flag = 0;


    while (1) {
	    A = (~PINA) & 1;
	  
	    
	    switch(state){
	    	case 0:
				prev = 0;
				if(A){
					state++; 
				 }
				break;
			case 1:
				prev = 1;
				if(A){
					if(flag == 0){state++; }
					else{ state = state -1; }
				 }
				break;
			case 2:
				prev = 2;
				if(A){
					if(flag == 0){state++; }
					else{ state = state -1; }
				 }
				break;
			case 3:
				prev = 0;
				if(A){
					if(flag == 0){state++; }
					else{ state = state -1; }
				 }
				break;
			case 4:
				prev = 0;
				if(A){
					if(flag == 0){state++; }
					else{ state = state -1; }
				 }
				break;
			case 5:
				prev = 0;
				if(A){
					if(flag == 0){state++; }
					else{ state = state -1; }
				 }
				break;
			case 6:
				prev = 0;
				if(A){
					if(flag == 0){state++; }
					else{ state = state -1; }
				 }
				break;
			case 7:
				prev = 0;
				state = state - 1;
				break;
	    }

	    //-----------------------------------------------------------

	    switch(state){
		case 0:
			B = 0;
			flag = 0;
			break;

		case 1:
			B = 1
			break;

		case 2:
			B = 3;
			break;
		case 3:
			B = 7;
			break;

		case 4:
			B = 15 ;
			break;

		case 5:
			B = 31 ;
			break;
		case 6:
			B = 63;
			break;

		case 7:
			B = 0;
			flag = 1;
			break;
	    }

    }
    return 0;
}
