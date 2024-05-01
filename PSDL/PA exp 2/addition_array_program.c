/* NAME:- Aniruddha Avhad.
   ROLL NO:- 01. SE-IT. */


#include <stdio.h>
#include <stdlib.h>
#include <p18f4550.h>

void main(void){
	int i,sum,n;
	int number[] = {1,4,6};
	sum = 0;
	for(i=0; i<=14; i++){
		sum = sum+number[i];
	}
	
	TRISD = 0;
	PORTD = sum;
}
