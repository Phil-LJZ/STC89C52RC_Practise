#include <intrins.h>
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