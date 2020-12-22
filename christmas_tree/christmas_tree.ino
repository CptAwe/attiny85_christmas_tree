/**
 * This is a program to test and experiment with a simpler hardware
 * 
*/ 
#include "LED.cpp"

#define red_LEDs_pin     PIN_PB4
#define yellow_LEDs_pin  PIN_PB1
#define blue_LEDs_pin    PIN_PB0

int flash_duration = 500;
int fade_duration = 2000;

LED red(red_LEDs_pin, 100, fade_duration, flash_duration);
LED yellow(yellow_LEDs_pin, 200, fade_duration, flash_duration);
LED blue(blue_LEDs_pin, 15, fade_duration, flash_duration);
LED leds[] = {red, yellow, blue};
byte led_num = sizeof(leds)/sizeof(LED);

/**
 * The tree is calmly fading in and out each LED
 * but will randomly start flashing them for a bit
 * before reverting back to fading them
 * 
*/

byte num_of_flahses = 3;// it will be locked to flash for this many loops minimum
byte maximum_num_of_fades = 7;// it will be fade for maximum this many loops

bool fade_or_flash = true;// true -> fade | false -> flash
byte previous_led_fade = led_num+1;
byte previous_led_flash = led_num+1;
byte current_flash = 1;
byte current_fade = 1;

void setup() {
	randomSeed(analogRead(0));
}

void loop() {
	if (random(10) > 8 || current_fade >= maximum_num_of_fades) {
		// flash
		current_flash = 1;
		current_fade = 1;
		fade_or_flash = false;// 20% probability (not true but who cares) to flash
	} else {
		// fade
		if (current_flash > num_of_flahses){
			fade_or_flash = true;
		}
	}
	
	if (fade_or_flash){
		// fade

		byte current_led;
		do {
			current_led = random(3);
		} while (current_led == previous_led_fade);
		previous_led_fade = current_led;
		leds[current_led].fade();

		current_fade++;

	} else {
		// flash

		byte current_led;
		do {
			current_led = random(7);
		} while (current_led == previous_led_flash);
		previous_led_flash = current_led;
		
		switch (current_led) {
		case 0:
		case 1:
		case 2:
			leds[current_led].flash();
			break;
		case 3:
			leds[0].on();
			leds[1].on();
			delay(flash_duration);
			leds[0].off();
			leds[1].off();
		case 4:
			leds[1].on();
			leds[2].on();
			delay(flash_duration);
			leds[1].off();
			leds[2].off();
		case 5:
			leds[0].on();
			leds[2].on();
			delay(flash_duration);
			leds[0].off();
			leds[2].off();
		case 6:
			leds[0].on();
			leds[1].on();
			leds[2].on();
			delay(flash_duration);
			leds[0].off();
			leds[1].off();
			leds[2].off();
		default:
			break;
		}
		
		current_flash++;
	}

}
