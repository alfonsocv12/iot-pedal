#include "Utilities.h"
#include <Arduino.h>

int input_jack = A0;

int Utilities::ReadAnalogPort(){
    delay(100);
    return analogRead(input_jack);
}

void Utilities::serialPrintString(string s) {
    int n = s.length();
    char char_array[n+1];
    strcpy(char_array, s.c_str());
    for (int i = 0; i < n; i++)
        Serial.print(char_array[i]);
    Serial.println();
}