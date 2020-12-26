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

	
}
