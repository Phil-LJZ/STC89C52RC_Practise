#include <REGX52.H>
#include "Delay.h"

unsigned char get_value(void)
{
	P1 = 0xff;
	
	while (1)
	{
		P1_0 = 0;
		if (!P1_4) {delay(20); while (!P1_4) return 16;};
		if (!P1_5) {delay(20); while (!P1_5) return 12;};
		if (!P1_6) {delay(20); while (!P1_6) return 8;};
		if (!P1_7) {delay(20); while (!P1_7) return 4;};
		P1_0 = 1;
		
		P1_1 = 0;
		if (!P1_4) {delay(20); while (!P1_4) return 15;};
		if (!P1_5) {delay(20); while (!P1_5) return 11;};
		if (!P1_6) {delay(20); while (!P1_6) return 7;};
		if (!P1_7) {delay(20); while (!P1_7) return 3;};
		P1_1 = 1;
		
		P1_2 = 0;
		if (!P1_4) {delay(20); while (!P1_4) return 14;};
		if (!P1_5) {delay(20); while (!P1_5) return 10;};
		if (!P1_6) {delay(20); while (!P1_6) return 6;};
		if (!P1_7) {delay(20); while (!P1_7) return 2;};
		P1_2 = 1;
		
		P1_3 = 0;
		if (!P1_4) {delay(20); while (!P1_4) return 13;};
		if (!P1_5) {delay(20); while (!P1_5) return 9;};
		if (!P1_6) {delay(20); while (!P1_6) return 5;};
		if (!P1_7) {delay(20); while (!P1_7) return 1;};
		P1_3 = 1;
	}
}