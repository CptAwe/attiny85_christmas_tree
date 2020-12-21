/**
 * This is a program to test and experiment with a simpler hardware
 * 
*/ 
#include "LED.cpp"

#define red_LEDs_pin     5
#define yellow_LEDs_pin  6
#define blue_LEDs_pin    3

LED red(red_LEDs_pin, 100);
LED yellow(yellow_LEDs_pin, 200);
LED blue(blue_LEDs_pin, 15);

/**
 * Binary Counter
 * 
 * msb [red - yellow - blue] lsb
*/

LED leds[] = {red, yellow, blue};
byte leds_num = sizeof(leds)/sizeof(LED);

void setup() {
}

void loop() {
	for (int i=0; i<leds_num; i++){
		if (leds[i].state()) {
			if (i<leds_num){
				leds[i+1].flip();
			}
		} else {
			leds[i].flip();
		}
		delay(700);
	}
	for (int i=0; i<leds_num; i++){
		leds[i].off();
	}
	delay(1000);
}
