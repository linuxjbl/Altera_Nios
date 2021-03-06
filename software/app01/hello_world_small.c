#include "sys/alt_stdio.h"
#include "system.h"
#include <altera_avalon_pio_regs.h>
#include <altera_avalon_uart.h>
#include <altera_avalon_uart_fd.h>
#include <altera_avalon_uart_regs.h>


unsigned long Period[8];
unsigned long Decode[8];

int pn = 0;
int dn = 0;
int BlinkEnb = 0;
unsigned long blinkco = 0;
char state[3];
int Category = 0;
int Duty[8];
int ChN = 0;

unsigned long 	regval;
//char 		onechar;

void _wait(loop_count)
int loop_count;
{
	volatile int sum, data;
	sum	= 0;
	for (data = 0; data < loop_count; data++) {
		sum = (data << 8);
	}
  return;
}

int Seg7Enc(int n) {
	int res;
	if(n == 0) res = 0xc0;
	else if(n == 1) res = 0xf9;
	else if(n == 2) res = 0xa4;
	else if(n == 3) res = 0xb0;
	else if(n == 4) res = 0x99;
	else if(n == 5) res = 0x92;
	else if(n == 6) res = 0x82;
	else if(n == 7) res = 0xf8;
	else if(n == 8) res = 0x80;
	else if(n == 9) res = 0x98;
	else if(n == 10) res = 0x88; // A
	else if(n == 11) res = 0x83; // b
	else if(n == 12) res = 0xa7; // c
	else if(n == 13) res = 0xa1; // d
	else if(n == 14) res = 0x86; // E
	else if(n == 15) res = 0x8e; // F
	else if(n == 100) res = 0x8b; // h(hundred)
	else if(n == 1000) res = 0x79; // 1.(1k)
	else if(n == 2000) res = 0x24; // 2.(2k)
	else if(n == 5000) res = 0x12; // 5.(5k)
	else if(n == 10000) res = 0x40; // 0.(10k)
	else if(n == 100000) res = 0x0b; // h.(100k)
	else res = 0xff;
	return res;
}

void TurnOffSeg(int n) {
	if(n == 1) {
		*(volatile unsigned long *)HEX3_BASE = Seg7Enc(-1);
	} else if(n == 2) {
		*(volatile unsigned long *)HEX2_BASE = Seg7Enc(-1);
	} else {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(-1);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(-1);
	}
}

void DispPeriod(int byState) {
	if((byState == 0 && Period[ChN] == 50000000) || (byState == 1 && state[2] == '0')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(0);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(1);
	} else if((byState == 0 && Period[ChN] == 25000000) || (byState == 1 && state[2] == '1')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(0);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(2);
	} else if((byState == 0 && Period[ChN] == 10000000) || (byState == 1 && state[2] == '2')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(0);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(5);
	} else if((byState == 0 && Period[ChN] == 5000000) || (byState == 1 && state[2] == '3')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(1);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(0);
	} else if((byState == 0 && Period[ChN] == 2500000) || (byState == 1 && state[2] == '4')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(2);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(0);
	} else if((byState == 0 && Period[ChN] == 1000000) || (byState == 1 && state[2] == '5')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(5);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(0);
	} else if((byState == 0 && Period[ChN] == 500000) || (byState == 1 && state[2] == '6')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(1);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(100);
	} else if((byState == 0 && Period[ChN] == 250000) || (byState == 1 && state[2] == '7')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(2);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(100);
	} else if((byState == 0 && Period[ChN] == 100000) || (byState == 1 && state[2] == '8')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(5);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(100);
	} else if((byState == 0 && Period[ChN] == 50000) || (byState == 1 && state[2] == '9')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(0);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(1000);
	} else if((byState == 0 && Period[ChN] == 25000) || (byState == 1 && state[2] == 'a')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(0);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(2000);
	} else if((byState == 0 && Period[ChN] == 10000) || (byState == 1 && state[2] == 'b')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(0);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(5000);
	} else if((byState == 0 && Period[ChN] == 5000) || (byState == 1 && state[2] == 'c')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(1);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(10000);
	} else if((byState == 0 && Period[ChN] == 2500) || (byState == 1 && state[2] == 'd')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(2);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(10000);
	} else if((byState == 0 && Period[ChN] == 1000) || (byState == 1 && state[2] == 'e')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(5);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(10000);
	} else if((byState == 0 && Period[ChN] == 500) || (byState == 1 && state[2] == 'f')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(1);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(100000);
	} else if((byState == 0 && Period[ChN] == 250) || (byState == 1 && state[2] == 'g')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(2);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(100000);
	} else if((byState == 0 && Period[ChN] == 100) || (byState == 1 && state[2] == 'h')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(5);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(100000);
	}
}

void DispDuty(int byState) {
	if((byState == 0 && Duty[ChN] == 1) || (byState == 1 && state[2] == '0')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(1);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(0);
	} else if((byState == 0 && Duty[ChN] == 2) || (byState == 1 && state[2] == '1')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(2);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(0);
	} else if((byState == 0 && Duty[ChN] == 3) || (byState == 1 && state[2] == '2')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(3);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(0);
	} else if((byState == 0 && Duty[ChN] == 4) || (byState == 1 && state[2] == '3')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(4);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(0);
	} else if((byState == 0 && Duty[ChN] == 5) || (byState == 1 && state[2] == '4')) {
		*(volatile unsigned long *)HEX1_BASE = Seg7Enc(5);
		*(volatile unsigned long *)HEX0_BASE = Seg7Enc(0);
	}
}

void DispChN(int byState) {
	if((byState == 0 && ChN == 0) || (byState == 1 && state[2] == '0')) {
		*(volatile unsigned long *)HEX3_BASE = Seg7Enc(0);
	} else if((byState == 0 && ChN == 1) || (byState == 1 && state[2] == '1')) {
		*(volatile unsigned long *)HEX3_BASE = Seg7Enc(1);
	} else if((byState == 0 && ChN == 2) || (byState == 1 && state[2] == '2')) {
		*(volatile unsigned long *)HEX3_BASE = Seg7Enc(2);
	} else if((byState == 0 && ChN == 3) || (byState == 1 && state[2] == '3')) {
		*(volatile unsigned long *)HEX3_BASE = Seg7Enc(3);
	} else if((byState == 0 && ChN == 4) || (byState == 1 && state[2] == '4')) {
		*(volatile unsigned long *)HEX3_BASE = Seg7Enc(4);
	}
}

void DispAll() {
	if(state[1] == 'U') { // "RUN"
		DispChN(0); // display by the ChN
		if(Category == 0) {
			*(volatile unsigned long *)HEX2_BASE = Seg7Enc(0xF);
			DispPeriod(0); // display by the variable
		} else {
			*(volatile unsigned long *)HEX2_BASE = Seg7Enc(0xd);
			DispDuty(0); // display by the variable
		}
	}

	else if(state[1] == 'N') { // "PNx"
		DispChN(1); // display by the state[2]
		if(Category == 0) {
			*(volatile unsigned long *)HEX2_BASE = Seg7Enc(0xF);
			DispPeriod(0); // display by the variable
		} else {
			*(volatile unsigned long *)HEX2_BASE = Seg7Enc(0xd);
			DispDuty(0); // display by the variable
		}
	}

	else if(state[1] == 'C') { // "xCx"
		DispChN(0); // display by the ChN
		if(state[2] == '0') {
			*(volatile unsigned long *)HEX2_BASE = Seg7Enc(0xF);
		} else if(state[2] == '1') {
			*(volatile unsigned long *)HEX2_BASE = Seg7Enc(0xd);
		}
		if(Category == 0) DispPeriod(0); // display by the variable
		else DispDuty(0); // display by the variable
	}

	else if(state[1] == 'F') { // "xFx"
		DispChN(0); // display by the ChN
		*(volatile unsigned long *)HEX2_BASE = Seg7Enc(0xF);
		DispPeriod(1); // display by the state
	}

	else if(state[1] == 'd') { // "xdx"
		DispChN(0); // display by the ChN
		*(volatile unsigned long *)HEX2_BASE = Seg7Enc(0xd);
		DispDuty(1); // display by the state
	}

}

void uart_print_help() {

	alt_putstr("\r\n");
	alt_putstr("==============  This is a Help ===============  \r\n");
	alt_putstr("=  a : AAAA \r\n");
	alt_putstr("=  b : BBBB \r\n");
	alt_putstr("=  r : Read \r\n");
	alt_putstr("=  w : Write \r\n");
	alt_putstr("==============  End of Help    ===============  \r\n");
	alt_putstr("\r\n");

}

void uart_rx_char() {
	char 		onechar;

		alt_putstr("You enter a character \r\n");
		onechar = alt_getchar();

		if(onechar == 'p'){
			alt_putstr("ABCDPPPP0123\r\n");
		}
		else if(onechar == 'a'){
			alt_putstr("AAAAaaaaaa\r\n");
		}
		else if(onechar == 'b'){
			alt_putstr("BBBBbbbbbb\r\n");
		}
		else if(onechar == 'h' || onechar == '?'){
			uart_print_help();
		}
		else if(onechar == '\n' ){
			alt_putstr("nnn\r\n");
		}
		else if(onechar == '\r' ){
			alt_putstr("rrr\r\n");
		}
}


int main()
{
	unsigned long reg1, reg1old, reg1tmp, reg2tmp, reg3tmp;
	int i;

	for(i = 0; i < 8; i++) {
		Period[i] = 50000000;
		Decode[i] = 25000000;
		Duty[i] = 5;
	}
	*(volatile unsigned long *)PERIOD1_BASE = Period[1];
	*(volatile unsigned long *)DECODE1_BASE = Decode[1];
	*(volatile unsigned long *)PERIOD2_BASE = Period[2];
	*(volatile unsigned long *)DECODE2_BASE = Decode[2];
	*(volatile unsigned long *)PERIOD3_BASE = Period[3];
	*(volatile unsigned long *)DECODE3_BASE = Decode[3];
	*(volatile unsigned long *)PERIOD4_BASE = Period[4];
	*(volatile unsigned long *)DECODE4_BASE = Decode[4];

	state[0] = 'R';	state[1] = 'U';	state[2] = 'N';
	DispAll();

	regval = 0;  // UART rx buffer clear

	alt_putstr("Nios UART Test by JBL ... \r\n");
	while (1) {
		//alt_putstr("Nios UART Test by JBL ... \r\n");

		regval = *(volatile unsigned long *)(UART_0_BASE+2*4);
		if((regval & 0x0080) == 0x80){
			uart_rx_char();
			regval = 0;
		}

    	reg1old = reg1;
      	reg1tmp = *(volatile unsigned long *)PUSH_BASE;
    	_wait(10000);
      	reg2tmp = *(volatile unsigned long *)PUSH_BASE;
    	_wait(10000);
     	reg3tmp = *(volatile unsigned long *)PUSH_BASE;
    	_wait(10000);
    	reg1 = *(volatile unsigned long *)PUSH_BASE;
    	if(reg1 == reg1tmp && reg1 == reg2tmp && reg1 == reg3tmp) {
    	} else {
    		reg1 = reg1old;
		alt_putstr("push button Event \r\n");
    		if((reg1 & 0x0F) == 0x01) {
			alt_putstr("push button One \r\n");
		}
		else if((reg1 & 0x0F) == 0x02) {
			alt_putstr("push button Two \r\n");
		}
		else if((reg1 & 0x0F) == 0x04) {
			alt_putstr("push button Three \r\n");
		}
		else if((reg1 & 0x0F) == 0x08) {
			alt_putstr("push button Four \r\n");
		}
		else if((reg1 & 0x0F) == 0x0E) {
			alt_putstr("push button E \r\n");
		}
		else if((reg1 & 0x0F) == 0x0D) {
			alt_putstr("push button D \r\n");
		}
		else if((reg1 & 0x0F) == 0x0B) {
			alt_putstr("push button B \r\n");
		}
		else if((reg1 & 0x0F) == 0x07) {
			alt_putstr("push button 7 \r\n");
		}
		else{
			alt_putstr("push button What ?? \r\n");
		}
    	}

    	if(reg1 != reg1old) {
    		_wait(200000);
    	}

    	if((reg1 & 0x03) == 0x01) { // button2?i?I???{?^???j??????????
    		if(state[1] == 'N') { // "PNx", Pwm ChN selection
    			if(state[2] == '0') {
    				state[2] = '1';
    			} else if(state[2] == '1') {
    				state[2] = '2';
    			} else if(state[2] == '2') {
    				state[2] = '3';
    			} else if(state[2] == '3') {
    				state[2] = '0';
    			}
      		}

    		else if(state[1] == 'C') { // "xCx", Category selection
    			if(state[2] == '0') {
    				state[2] = '1';
    			} else if(state[2] == '1') {
    				state[2] = '0';
    			}
    		}

    		else if(state[1] == 'F') { // "xFx", Frequency selection
    			if(state[2] == '0') {
    				state[2] = '1';
    			} else if(state[2] == '1') {
    				state[2] = '2';
    			} else if(state[2] == '2') {
    				state[2] = '3';
    			} else if(state[2] == '3') {
    				state[2] = '4';
    			} else if(state[2] == '4') {
    				state[2] = '5';
    			} else if(state[2] == '5') {
    				state[2] = '6';
    			} else if(state[2] == '6') {
    				state[2] = '7';
    			} else if(state[2] == '7') {
    				state[2] = '8';
    			} else if(state[2] == '8') {
    				state[2] = '9';
    			} else if(state[2] == '9') {
    				state[2] = 'a';
    			} else if(state[2] == 'a') {
    				state[2] = 'b';
    			} else if(state[2] == 'b') {
    				state[2] = 'c';
    			} else if(state[2] == 'c') {
    				state[2] = 'd';
    			} else if(state[2] == 'd') {
    				state[2] = 'e';
    			} else if(state[2] == 'e') {
    				state[2] = 'f';
    			} else if(state[2] == 'f') {
    				state[2] = 'g';
    			} else if(state[2] == 'g') {
    				state[2] = 'h';
    			} else if(state[2] == 'h') {
    				state[2] = '0';
    			}
    		}

    		else if(state[1] == 'd') { // "xdx", Frequency selection
    			if(state[2] == '0') {
    				state[2] = '1';
    			} else if(state[2] == '1') {
    				state[2] = '2';
    			} else if(state[2] == '2') {
    				state[2] = '3';
    			} else if(state[2] == '3') {
    				state[2] = '4';
    			} else if(state[2] == '4') {
    				state[2] = '0';
    			}
    		}

    		DispAll();
			if(pn == 17) pn = 0;
			else pn++;
    	}

    	if((reg1 & 0x03) == 0x02) { // button1?i?????{?^???j??????????
    		if(state[1] == 'U') { // "RUN", free-run state
				state[0] = 'P';	state[1] = 'N';
				if(ChN == 0) state[2] = '0';
				else if(ChN == 1) state[2] = '1';
				else if(ChN == 2) state[2] = '2';
				else if(ChN == 3) state[2] = '3';
				else if(ChN == 4) state[2] = '4';
      		}

    		else if(state[1] == 'N') { // "PNx", Pwm number selection
    			if(state[2] == '0') ChN = 0;
    			else if(state[2] == '1') ChN = 1;
    			else if(state[2] == '2') ChN = 2;
    			else if(state[2] == '3') ChN = 3;
    			else if(state[2] == '4') ChN = 4;
				state[0] = 48+ChN;
				state[1] = 'C';
    			if(Category == 0) state[2] = '0';
    			else state[2] = '1';
      		}

    		else if(state[1] == 'C') { // "xCx", Category selection
    			if(state[2] == '0') {
    				Category = 0;
    				state[0] = 48+ChN;
    				state[1] = 'F';
    				if(Period[ChN] == 50000000) state[2] = '0';
    				else if(Period[ChN] == 25000000) state[2] = '1';
    				else if(Period[ChN] == 10000000) state[2] = '2';
    				else if(Period[ChN] == 5000000) state[2] = '3';
    				else if(Period[ChN] == 2500000) state[2] = '4';
    				else if(Period[ChN] == 1000000) state[2] = '5';
    				else if(Period[ChN] == 500000) state[2] = '6';
    				else if(Period[ChN] == 250000) state[2] = '7';
    				else if(Period[ChN] == 100000) state[2] = '8';
    				else if(Period[ChN] == 50000) state[2] = '9';
    				else if(Period[ChN] == 25000) state[2] = 'a';
    				else if(Period[ChN] == 10000) state[2] = 'b';
    				else if(Period[ChN] == 5000) state[2] = 'c';
    				else if(Period[ChN] == 2500) state[2] = 'd';
    				else if(Period[ChN] == 1000) state[2] = 'e';
    				else if(Period[ChN] == 500) state[2] = 'f';
    				else if(Period[ChN] == 250) state[2] = 'g';
    				else if(Period[ChN] == 100) state[2] = 'h';
    			} else {
    				Category = 1;
    				state[0] = 48+ChN;
    				state[1] = 'd';
    				if(Duty[ChN] == 1) state[2] = '0';
    				else if(Duty[ChN] == 2) state[2] = '1';
    				else if(Duty[ChN] == 3) state[2] = '2';
    				else if(Duty[ChN] == 4) state[2] = '3';
    				else if(Duty[ChN] == 5) state[2] = '4';
    			}
      		}

    		else if(state[1] == 'F') { // "xFx", Category selection
				if(state[2] == '0') {
					Period[ChN] = 50000000; // 1Hz
				} else if(state[2] == '1') {
						Period[ChN] = 25000000; // 2Hz
				} else if(state[2] == '2') {
						Period[ChN] = 10000000; // 5Hz
				} else if(state[2] == '3') {
						Period[ChN] = 5000000; // 10Hz
				} else if(state[2] == '4') {
						Period[ChN] = 2500000; // 20Hz
				} else if(state[2] == '5') {
						Period[ChN] = 1000000; // 50Hz
				} else if(state[2] == '6') {
						Period[ChN] = 500000; // 100Hz
				} else if(state[2] == '7') {
						Period[ChN] = 250000; // 200Hz
				} else if(state[2] == '8') {
						Period[ChN] = 100000; // 500Hz
				} else if(state[2] == '9') {
						Period[ChN] = 50000; // 1kHz
				} else if(state[2] == 'a') {
						Period[ChN] = 25000; // 2kHz
				} else if(state[2] == 'b') {
						Period[ChN] = 10000; // 5kHz
				} else if(state[2] == 'c') {
						Period[ChN] = 5000; // 10kHz
				} else if(state[2] == 'd') {
						Period[ChN] = 2500; // 20kHz
				} else if(state[2] == 'e') {
						Period[ChN] = 1000; // 50kHz
				} else if(state[2] == 'f') {
						Period[ChN] = 500; // 100kHz
				} else if(state[2] == 'g') {
						Period[ChN] = 250; // 200kHz
				} else if(state[2] == 'h') {
						Period[ChN] = 100; // 500kHz
				}
				Decode[ChN] = Period[ChN] * Duty[ChN] / 10;
				if(ChN == 0) {
					*(volatile unsigned long *)PERIOD1_BASE = Period[ChN];
					*(volatile unsigned long *)DECODE1_BASE = Decode[ChN];
				} else if(ChN == 1) {
					*(volatile unsigned long *)PERIOD2_BASE = Period[ChN];
					*(volatile unsigned long *)DECODE2_BASE = Decode[ChN];
				} else if(ChN == 2) {
					*(volatile unsigned long *)PERIOD3_BASE = Period[ChN];
					*(volatile unsigned long *)DECODE3_BASE = Decode[ChN];
				} else if(ChN == 3) {
					*(volatile unsigned long *)PERIOD4_BASE = Period[ChN];
					*(volatile unsigned long *)DECODE4_BASE = Decode[ChN];
				}
				state[0] = 'R';	state[1] = 'U';	state[2] = 'N';
    		}

	    	else if(state[1] == 'd') { // "xdx", Category selection
				if(state[2] == '0') {
					Duty[ChN] = 1;
				} else if(state[2] == '1') {
					Duty[ChN] = 2;
				} else if(state[2] == '2') {
					Duty[ChN] = 3;
				} else if(state[2] == '3') {
					Duty[ChN] = 4;
				} else if(state[2] == '4') {
					Duty[ChN] = 5;
				} 
				Decode[ChN] = Period[ChN] * Duty[ChN] / 10;
				if(ChN == 0) {
					*(volatile unsigned long *)DECODE1_BASE = Decode[ChN];
				} else if(ChN == 1) {
					*(volatile unsigned long *)DECODE2_BASE = Decode[ChN];
				} else if(ChN == 2) {
					*(volatile unsigned long *)DECODE3_BASE = Decode[ChN];
				} else if(ChN == 3) {
					*(volatile unsigned long *)DECODE4_BASE = Decode[ChN];
				} 
				state[0] = 'R';	state[1] = 'U';	state[2] = 'N';
      		}
    		DispAll();
    	}

    	if(state[1] == 'U') { // "RUN"?X?e?[?g???S???_??
   			DispAll();
    	} else if(state[1] == 'N') { // "PNx"?X?e?[?g??1?????_??
        		if(blinkco < 3) {
        			TurnOffSeg(1);
        		} else {
        			DispAll();
        		}
    	} else if(state[1] == 'C') { // "xCx"?X?e?[?g??2?????_??
    		if(blinkco < 3) {
    			TurnOffSeg(2);
    		} else {
    			DispAll();
    		}
    	} else if(state[1] == 'F' || state[1] == 'd') { // "xFx"?X?e?[?g??3,4?????_??
    		if(blinkco < 3) {
    			TurnOffSeg(3);
    		} else {
    			DispAll();
    		}
    	}

    	if(blinkco == 9) {
    		blinkco = 0;
    	} else {
    		blinkco++;
    	}

	}

  return 0;
}
