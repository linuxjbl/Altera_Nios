#include "sys/alt_stdio.h"
#include "system.h"

int main()
{
	*(volatile unsigned long *)HEX0_BASE = 0xc0;

	*(volatile unsigned long *)PERIOD1_BASE = 50000000;
	*(volatile unsigned long *)DECODE1_BASE = 25000000;
	*(volatile unsigned long *)PERIOD2_BASE = 20000000;
	*(volatile unsigned long *)DECODE2_BASE = 10000000;
	*(volatile unsigned long *)PERIOD3_BASE = 100000000;
	*(volatile unsigned long *)DECODE3_BASE = 50000000;
	*(volatile unsigned long *)PERIOD4_BASE = 50000000;
	*(volatile unsigned long *)DECODE4_BASE = 10000000;

	while (1) {
	}

  return 0;
}
