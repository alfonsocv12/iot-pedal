#include "modules/Utilities.h"
#include <Arduino.h>

int input_jack = A0;

/**
 * readAnalogPort is the function dedicated to read the input jack
 * values
 * 
 * @return readValue 
*/
int Utilities::readAnalogPort(){
    delay(100);
    return analogRead(input_jack);
}

/**
 * Function dedicated to print strings on the
 * Serial line
 * 
 * @param s whose values ara parse into char array to be printed
*/
void Utilities::serialPrintString(string s) {
    int n = s.length();
    char char_array[n+1];
    strcpy(char_array, s.c_str());
    for (int i = 0; i < n; i++)
        Serial.print(char_array[i]);
    Serial.println();
}