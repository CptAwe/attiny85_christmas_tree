/**
 * This is a program to test and experiment with a simpler hardware
 * 
*/ 
#include "LED.cpp"

#define red_LEDs_pin     PIN_PB4
#define yellow_LEDs_pin  PIN_PB1
#define blue_LEDs_pin    PIN_PB0
#define flash_duration 500

LED red(red_LEDs_pin, 100, 1000, 100);
LED yellow(yellow_LEDs_pin, 200);
LED blue(blue_LEDs_pin, 15);

int pause_duration = 300;
int smaller_pause_duration = 70;
int pause_after_each_note = 360;

// This represents the notes for Stand by Me - Ben E. King
char red_notes[]    = "._._-----------------------------..._._..._._";
char blue_notes[]   = "----..._._-----------------..._._------------";
char yellow_notes[] = "----------..._._.._._..._._------------------";
byte num_of_notes = sizeof(red_notes)/sizeof(char);

void setup() {
	// nothing to do here
}

void loop() {
	for (byte note=0; note < num_of_notes; note++){

		if (red_notes[note] == '.') {
			red.on();
		} else if (red_notes[note] == '_') {
			delay(pause_duration);
			continue;
		} else if (red_notes[note] == '~') {
			delay(smaller_pause_duration);
			continue;
		}

		if (blue_notes[note] == '.') {
			blue.on();
		} else if (blue_notes[note] == '_') {
			delay(pause_duration);
			continue;
		} else if (red_notes[note] == '~') {
			delay(smaller_pause_duration);
			continue;
		}

		if (yellow_notes[note] == '.') {
			yellow.on();
		} else if (yellow_notes[note] == '_') {
			delay(pause_duration);
			continue;
		} else if (red_notes[note] == '~') {
			delay(smaller_pause_duration);
			continue;
		}

		delay(pause_after_each_note/2);

		red.off();
		blue.off();
		yellow.off();

		delay(pause_after_each_note/2);

	}
}
