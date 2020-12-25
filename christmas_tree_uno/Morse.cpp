#ifndef MORSE_h
#define MORSE_h

#include "Arduino.h"

/**
 * This code is unused due to time constraints
 * 
*/

class Morse {
    private:
        static const char morse[26][5] = {
            /**
             * . : dot
             * - : dash
             * ~ : nothing
            */
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
        };
        static const char alphabet[27] = "ABCDEFGHUJKLMNOPQRSTUVWXYZ";
    
    public:
        static void toMorse(char letter, char * answer) {
            // returns the equivalent morse code for a letter
            // the answer is expected to be 5 chars long
            // letter = strupr(letter);// make it uppercase

            for (byte i=0; i<27; i++){
                char temp_letter = Morse::alphabet[i];
                if (letter == temp_letter) {
                    memcpy(answer, Morse::morse[i], 5*sizeof(char));
                }
                memcpy(answer, "~~~~", 5*sizeof(char));
            }

        }

};


#endif