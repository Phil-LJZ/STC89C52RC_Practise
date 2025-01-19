#include <REGX52.H>
#include <INTRINS.h>

void Delay(void);

int main(void)
{
	int temp = 0x01;
	int i;
	int LED_count = 8;
	
	for (i = 0, temp = 0x01; i < LED_count; i++)
	{
		P2 = ~temp;
		temp <<= 1;
		Delay();
		P2 = 0xff;
	}
	
	for (i = 0, temp = 0x80; i < LED_count; i++)
	{
		P2 = ~temp;
		temp >>= 1;
		Delay();
		P2 = 0xff;
	}
	
	return 0;
}

void Delay()		//@11.0592MHz
{
	unsigned char i, j;

	i = 180;
	j = 73;
	do
	{
		while (--j);
	} while (--i);
}
