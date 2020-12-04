#include "modules/Bluetooth.h"
#include <Arduino.h>

/**
 * startConnection is the function dedicated to start the bluetooth
 * pairing proces
*/
void Bluetooth::startConnection(){
    
}

/**
 * Ask wifi name and password
 * 
 * 
*/
void Bluetooth::wifiNamePass(BluetoothSerial SerialBT){
    
    while(SerialBT.available()){
        Serial.write(SerialBT.read());
    }
}

/**
 * pairingMode is dedicate to change the state of the bluetooth to be
 * visible to others
 * 
 * @return pair success code
*/
string Bluetooth::pairingMode(){
    delay(100);
    return "Funciona";
}