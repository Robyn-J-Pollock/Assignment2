/*
===============================================================================
 Name        : Assignment2.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

//TODO: set register 0 and register 1
#define FIO0DIR (*(volatile unsigned int *)0x2009c000)
#define FIO0PIN (*(volatile unsigned int *)0x2009c014)

#define PINMODE1 (*(volatile unsigned int *)0x4002c044)

int main(void) {
	/*
	 *LED setup:
	 *Green Pin(0-3); Blue Pin(4-7); Red Pin(8-11)
	 */
	//Sets first 12 pins to output
	FIO0DIR |= (4095 << 0);
	//Sets first 12 pins low (LEDs active high)
	FIO0PIN &= ~(4095 << 0);

	/*Switch setup:
	 * Player1 Pin(16-18); Player2 Pin(24-26)
	 */
	//Sets first pins 16-18 and  to inputs
	//FIO0DIR &= ~(3 << 16) & ~(3 << 24);
	//Sets pins 16-22 to pull down resistors
//	PINMODE1 |= (6 << 0) | (6 << 16);
	int count = 0;
	int iterator = 1;
	//TODO: make loop for game
	//Always loops
	while(1) {
		FIO0PIN = iterator;
		while (count < 50000)
			count++;
		count = 0;
		iterator = 2*iterator;
		if (iterator > 2048) iterator = 1;

	}
	//TODO: Make logic to ignore switches
	//TODO: Make logic to turn off LEDs
	return 0;
}
