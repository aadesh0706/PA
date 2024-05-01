// NMAE:- Aniruddha Avhad.
// ROLL NO:- 01. SE-IT.


#include <stdio.h>
#include <stdlib.h>
#include <p18f4550.h>

void main (void){
	int mul,div;
	mul = 0;
	div = 0;
	mul = 0x04 * 0x02;
	div = 0x08 / 0x04;


	TRISD = 0;
	TRISC = 0;

	PORTD = mul;
	PORTC = div;

}
