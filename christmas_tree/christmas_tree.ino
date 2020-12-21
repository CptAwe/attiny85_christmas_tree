/**
 * This is a program to test and experiment with a simpler hardware
 * 
*/ 
#include "LED.cpp"

#define red_LEDs_pin     PIN_PB4
#define yellow_LEDs_pin  PIN_PB1
#define blue_LEDs_pin    PIN_PB0
#define flash_duration 500

byte led;
int previous_choice = 0;

LED red(red_LEDs_pin, 100);
LED yellow(yellow_LEDs_pin, 200);
LED blue(blue_LEDs_pin, 15);

void setup() {
	randomSeed(analogRead(0));
}

void loop() {

	while (true) {
		// Avoid doing the same thing twice
		led = random(7);
		if (led != previous_choice) {
			break;
		}
	}
	switch (led) {
		case 0:
			red.flash();
			break;
		case 1:
			yellow.flash();
			break;
		case 2:
			blue.flash();
			break;
		case 3:
			red.on();
			yellow.on();
			delay(flash_duration);
			red.off();
			yellow.off();
		case 4:
			yellow.on();
			blue.on();
			delay(flash_duration);
			yellow.off();
			blue.off();
		case 5:
			red.on();
			blue.on();
			delay(flash_duration);
			red.off();
			blue.off();
			break;
		default:
			red.on();
			yellow.on();
			blue.on();
			delay(flash_duration);
			red.off();
			yellow.off();
			blue.off();
			break;
	}
	previous_choice = led;
}
