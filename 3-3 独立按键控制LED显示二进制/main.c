#include <REGX52.H>
#include <intrins.h>

void delay(unsigned int);

void main(void)
{
	int temp = 0x80; // 1000 0000
	
	P2 = 0x7f; // 0111 1111
	
	while (1)
	{
		if (P3_1 == 0)
		{
			delay(20); // Eliminate jitter
			while (P3_1 == 0);
			delay(20); // Eliminate jitter
			
			temp = temp >> 1;
			if (temp == 0x00) // 0000 0000
			{
				temp = 0x80; // 1000 0000
			}
			P2 = ~temp;
		}
		else if (P3_0 == 0)
		{
			delay(20); // Eliminate jitter
			while (P3_0 == 0);
			delay(20); // Eliminate jitter
			
			temp = temp << 1;
			if (temp == 0x100) // 1 0000 0000
			{
				temp = 0x01;
			}
			P2 = ~temp;
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