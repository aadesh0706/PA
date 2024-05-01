#include<P18F4550.h>

void Delay_ms(int ms);

void main()
{
	TRISB = 0x00;
	
	while(1)
	{
		PORTB = 0xFF;
		Delay_ms(100);
		PORTB = 0x00;
		Delay_ms(100);
	}
}

void Delay_ms(int ms)
{
	int i,count;
	
	for(i=0;i<ms;i++)
	{
		count = 98;
		while(count != 1)
		{
			count--;
		}
	}
}