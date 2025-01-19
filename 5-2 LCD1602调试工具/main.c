#include <REGX52.H>
#include <Delay.h>
#include <LCD1602.h>

int main(void)
{
	LCD_Init();
	LCD_ShowString(0, 0, "Hello world");
	while(1);
	
	return 0;
}