#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "get_martrixkey_value.h"

void main(void)
{
	LCD_Init();
	
	while (1) LCD_ShowNum(0, 0, get_value(), 2);
	
	while (1);
}