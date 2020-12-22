/**
 * This is a program to test and experiment with a simpler hardware
 * 
*/ 
#include "LED.cpp"

#define red_LEDs_pin     PIN_PB4
#define yellow_LEDs_pin  PIN_PB1
#define blue_LEDs_pin    PIN_PB0

LED red(red_LEDs_pin, 100, 2000);
LED yellow(yellow_LEDs_pin, 200, 2000);
LED blue(blue_LEDs_pin, 15, 2000);
LED leds[] = {red, yellow, blue};
byte led_num = sizeof(leds)/sizeof(LED);

/**
 * The tree is calmly fading in and out each LED
 * but will randomly start flashing them for a bit
 * before reverting back to fading them
 * 
*/

byte num_of_flahses = 3;// it will be locked to flash for this many loops minimum

bool fade_or_flash = true;// true -> fade | false -> flash
byte previous_led = led_num+1;
byte current_flash = 1;

void setup() {
	randomSeed(analogRead(0));
}

void loop() {
	if (random(10) > 7) {
		current_flash = 1;
		fade_or_flash = false;// 30% probability (not true but who cares) to flash
	} else {
		if (current_flash > num_of_flahses){
			fade_or_flash = true;
		}
	}

	byte current_led;
	do {
		current_led = random(3);
	} while (current_led == previous_led);
	previous_led = current_led;
	
	if (fade_or_flash){
		leds[current_led].fade();
	} else {
		leds[current_led].flash();
		current_flash++;
	}

}
