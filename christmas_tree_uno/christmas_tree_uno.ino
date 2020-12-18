/**
 * This is a program to test and experiment with a simpler hardware
 * 
*/ 

#define red_LEDs_pin     3
#define yellow_LEDs_pin  5
#define blue_LEDs_pin    6

int pins[] = {red_LEDs_pin, yellow_LEDs_pin, blue_LEDs_pin};


void setup() {
	for (byte i=0; i<3; i++){
		pinMode(pins[i], OUTPUT);
	}
}

void loop() {
	for (byte i=0; i<=2; i++){
		for (int j=0; j<=255; j++) {
			analogWrite(pins[i], j);
			delay(10);
		}
		delay(100);
		for (int j=255; j>=0; j--) {
			analogWrite(pins[i], j);
			delay(10);
		}
		delay(100);
	}
}
