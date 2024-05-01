#include<p18f4520.h>
#pragma config OSC=HS
#pragma config PWRT=OFF
#pragma config WDT=OFF
#pragma config DEBUG=OFF, LVP=OFF

void msdelay(unsigned int itime);
void Right(void);
void Left(void);

#define SW2 PORTBbits.RB0
#define SW1 PORTBbits.RB1
#define relay PORTBbits.RB3
#define buzzer PORTBbits.RB2
#define D1 PORTBbits.RB4
#define D2 PORTBbits.RB5
#define D3 PORTBbits.RB6
#define D4 PORTBbits.RB7

void main(){
	ADCON1=0x0F;
	TRISBbits.TRISB0=1;
	TRISBbits.TRISB1=1;
	TRISBbits.TRISB2=0;
	TRISBbits.TRISB3=0;
	TRISBbits.TRISB4=0;
	TRISBbits.TRISB5=0;
	TRISBbits.TRISB6=0;
	TRISBbits.TRISB7=0;
	D1=D2=D3=D4=0;
	SW1=SW2=1;
	relay=0;
	
	while(1){
		if(SW2==0 & SW1==1){
			relay=1;
			buzzer=1;
			Right();
		}
		if(SW1==0 & SW2==1){
			relay=0;
			buzzer=0;
			Left();
		}
	}
}
	
void Right(void){
	D1=D2=D3=D4=0;
	while(SW1 != 0){
		relay=1;
		buzzer=1;
		D1=1;D2=0;D3=0;D4=0;
		msdelay(10);
		D1=0;D2=1;D3=0;D4=0;
		msdelay(10);
		D1=0;D2=0;D3=1;D4=0;
		msdelay(10);
		D1=0;D2=0;D3=0;D4=1;
		msdelay(10);
	}
}
	
void Left(void){
	D1=D2=D3=D4=0;
	while(SW2 != 0){
		relay=0;
		buzzer=0;
		D1=0;D2=0;D3=0;D4=1;
		msdelay(10);
		D1=0;D2=0;D3=1;D4=0;
		msdelay(10);
		D1=0;D2=1;D3=0;D4=0;
		msdelay(10);
		D1=1;D2=0;D3=0;D4=0;
		msdelay(10);
	}
}
	
void msdelay(unsigned int itime){
	int i,j;
	for(i=0; i<itime; i++)
		for(j=0; j<1275; j++);
}