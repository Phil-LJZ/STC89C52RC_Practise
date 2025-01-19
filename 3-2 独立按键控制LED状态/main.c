#include <REGX52.H>
#include <intrins.h>

void delay(unsigned int);

void main(void)
{
	int had_clicked = 0;
	
	while (1)
	{
		if (P3_1 == 0)
		{
			delay(20); // Eliminate jitter
			while (P3_1 == 0);
			delay(20); // Eliminate jitter
			
			P2_0 = ~P2_0; // Each time a key is pressed, the value is negative.
		}
	}
}

void delay(unsigned int x)		//@11.0592MHz
{
	unsigned char i, j;

	while (x)
	{
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
		x--;
	}	
}