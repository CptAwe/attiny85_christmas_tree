/**
 * This tree rolls a dice each time it boots
 * 
 * Each led represents a number:
 * 
 * blue = 1
 * yellow = 2
 * red = 3
 * 
 * The rest of the numbers are formed uniquely as follows:
 * 4 = red + blue
 * 5 = red + yellow
 * 6 = red + yellow + blue
 * 
 * -------
 * 
 * The following is a needlessly complicated way to find what leds to light
 * to form a particular number.
 * 
 * The arduino finds which leds to flash by substracting each number starting from
 * the biggest until the result of a substraction is 0. If it is smaller than zero,
 * go a step back and redo the substraction with the second biggest number.
 * eg.
 *  To form 5:
 *          5 - 3 = 2
 *          2 - 2 = 0
 *  So, light the leds that represent 3 and 2
 * 
 *  To form 4:
 *          4 - 3 = 1
 *          1 - 2 = -1
 *          (redo last substraction)
 *          1 - 1 = 0
 *  So, light the leds that represent 3 and 1
 * 
 *  To form 6:
 *          6 - 3 = 3
 *          3 - 2 = 1
 *          1 - 1 = 0
 *  So, light the leds that represent 3, 2 and 1
 * 
 * 
*/ 
#include "LED.cpp"

#define red_LEDs_pin     PIN_PB4
#define yellow_LEDs_pin  PIN_PB1
#define blue_LEDs_pin    PIN_PB0


LED red(red_LEDs_pin, 100);
LED yellow(yellow_LEDs_pin, 200);
LED blue(blue_LEDs_pin, 15);
LED leds[] = {blue, red, yellow};
byte leds_num = sizeof(leds)/sizeof(LED);

int flash_duration = 7000;
byte numbers[] = {1, 2, 3};
byte numbers_num = sizeof(numbers)/sizeof(byte);

byte randomizer();// play an effect and return a random (kinda) number

void setup() {
	randomSeed(analogRead(0));
	// Serial.begin(9600);
}

void loop() {
	bool leds_flash[] = {  0, 0, 0};// blue, red, yellow
	byte result = randomizer() + 1;

	// Serial.println(result);

	for (byte i=numbers_num-1; i>=0; i--){
		int temp = result - numbers[i];
		
		if (temp > 0){
			leds_flash[numbers[i] - 1] = true;
			result = temp;
		} else if (temp < 0) {
			continue;
		} else {// == 0
			leds_flash[numbers[i] - 1] = true;
			break;
		}
	}

	// for (byte i=0; i<leds_num; i++) {
	// 	Serial.print(leds_flash[i]);
	// }

	// Show the result
	for (byte i=0; i<leds_num; i++) {
		if (leds_flash[i]) {
			leds[i].on();
		}
	}
	delay(flash_duration);
	red.off();
	blue.off();
	yellow.off();
}


byte randomizer() {
	// blink the leds one after the other with increasing delay

	int varialbe_delay = 200;
	byte increments = 100;
	int max_delay = varialbe_delay + 700;

	while (true) {
		for (byte i=0; i<leds_num; i++) {
			leds[i].on();
			delay(varialbe_delay/2);
			leds[i].off();
			delay(varialbe_delay/2);
		}
		varialbe_delay += increments;

		if (varialbe_delay > max_delay) {
			return random(6);
		}
	}
}