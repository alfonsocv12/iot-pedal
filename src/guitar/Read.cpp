#include "Read.h"
#include <Arduino.h>

int input_jack = A0;

int Read::ReadAnalogPort(){
    delay(100);
    return analogRead(input_jack);
}