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
	byte i = 0;
	while (i < leds_num) {
		if (leds[i].state()){
			leds[i].off();
			i++;
			continue;
		} else {
			leds[i].on();
			i=0;
		}
		delay(1000);
	}
	
	delay(1000);
	for (int i=0; i<leds_num; i++){
		leds[i].off();
	}
	delay(1000);
}
