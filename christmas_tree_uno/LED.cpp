#ifndef LED_h
#define LED_h

#include "Arduino.h"


class LED {
    private:
        byte _pin;
        byte _m_bright;
        float _f_del;
        int _f_dur;
        int _flash_dur;
        
    public:
        LED(byte pin, int max_brightness, int fade_duration = 1000, int flash_duration = 500) {
            _pin = pin;
            _m_bright = max_brightness;
            _f_dur = fade_duration;
            _f_del = ((float) fade_duration/(float) max_brightness);
            _flash_dur = flash_duration;

            pinMode(_pin, OUTPUT);

        }

        int fade() {
            for (int bright = 0; bright <= _m_bright; bright++) {
                analogWrite(_pin, bright);
                delay(_f_del/2);
            }
            for (int bright = _m_bright; bright >= 0; bright--) {
                analogWrite(_pin, bright);
                delay(_f_del/2);
            }
            return _f_del*_m_bright;
        }

        void flash() {
            analogWrite(_pin, _m_bright);
            delay(_flash_dur);
            analogWrite(_pin, 0);
            // delay(_flash_dur/2);
        }

        void on() {
            analogWrite(_pin, _m_bright);
        }

        void off() {
            analogWrite(_pin, 0);
        }

};

#endif
