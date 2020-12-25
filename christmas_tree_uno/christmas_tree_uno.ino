/**
 * This is a program to test and experiment with a simpler hardware
 * 
*/ 
#include "LED.cpp"

#define red_LEDs_pin     3
#define yellow_LEDs_pin  6
#define blue_LEDs_pin    5

int flash_duration = 500;
int fade_duration = 2000;

LED red(red_LEDs_pin, 100, fade_duration, flash_duration);
LED yellow(yellow_LEDs_pin, 200, fade_duration, flash_duration);
LED blue(blue_LEDs_pin, 15, fade_duration, flash_duration);
LED leds[] = {red, yellow, blue};
byte led_num = sizeof(leds)/sizeof(LED);

/**
 * This tree sends a message in morse code
 * 
*/

/**
	".-~~", // A
	"-...", // B
	"-.-.", // C
	"-..~", // D
	".~~~", // E
	"..-.", // F
	"--.~", // G
	"....", // H
	"..~~", // I
	".---", // J
	"-.-~", // K
	".-..", // L
	"--~~", // M
	"-.~~", // N
	"---~", // O
	".--.", // P
	"--.-", // Q
	".-.~", // R
	"...~", // S
	"-~~~", // T
	"..-~", // U
	"...-", // V
	".--~", // W
	"-..-", // X
	"-.--", // Y
	"--.."  // Z
*/

char message[] = ".--..-...-.. -..----.. .--..--..---...----..";// Well Done Panagioti
byte message_len = sizeof(message)/sizeof(char) - 1;// keep the EOL character out

byte current_led;
byte previous_led = led_num;

void setup() {
	randomSeed(analogRead(0));
}

void loop() {
	for (byte i=0; i<message_len; i++) {
		do
		{
			current_led = random(3);
		} while (current_led == previous_led);
		
		if (message[i] == '.') {
			leds[current_led].flash();
		} else if ((message[i] == '-')) {
			leds[current_led].fade();
		}
		delay(1000);
	}

	for (byte i=0; i<3; i++) {
		red.on();
		yellow.on();
		blue.on();
		delay(flash_duration);
		red.off();
		yellow.off();
		blue.off();
		delay(flash_duration);
	}

	delay(2000);
}
