#include <REGX52.H>
#include <intrins.h>

void delay(unsigned int);
void show_digital(char, char);

void main(void)
{
	int i = 0;
	// 0 0 0 0  0 0 0 0
	//dp g f e  d c b a
	
	//     0 0 0 0  0 0 0 0
	// P2_7  6 5 4  3 2 1 0
	
	// P2 = 0x04;
	while (1)
	{
		for (i = 0; i < 8; i++)
		{
			show_digital(i, i);
			delay(1);
			show_digital(0, i);
		}
	}
	
	while(1);
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
void show_digital(char num, char index)
{
	static char led_digital[] = {
		0x06, 0x5b, 0x4f, // 1, 2, 3
		0x66, 0x6d, 0x7d, // 4, 5, 6
		0x07, 0x7f, 0x6f,// 7, 8, 9
		0x3f // 0
	};
	
	P2 = 0x00;
	index = index << 2;
	P2 = P2 | index;

	P0 = led_digital[num];
}
