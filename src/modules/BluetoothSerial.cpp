#include "modules/BluetoothSerial.h"
#include <Arduino.h>

/**
 * startConnection is the function dedicated to start the bluetooth
 * pairing proces
*/
void BluetoothSerial::startConnection(){
    
}

/**
 * pairingMode is dedicate to change the state of the bluetooth to be
 * visible to others
 * 
 * @return pair success code
*/
string BluetoothSerial::pairingMode(){
    delay(100);
    return "Funciona";
}