#include <Arduino.h>
#include <string.h>

#include "Utilities.h"
#include "BluetoothSerial.h"

using namespace std;
Utilities* utilities_pointer = new Utilities();
BluetoothSerial* bluetooth_serial_pointer = new BluetoothSerial();

/**
  * Setup all the previews initial commands
*/
void setup() {
  Serial.begin(115200);
}

/**
  * Loop function, if you want something to be done on the esp putit here
  * 
*/
void loop() {
  utilities_pointer->serialPrintString(
    bluetooth_serial_pointer->pairingMode()
  );
}