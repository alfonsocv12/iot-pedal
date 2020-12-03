#include <Arduino.h>
#include <string.h>

#include "Utilities.h"
#include "BluetoothSerial.h"

using namespace std;
Utilities* utilities_pointer = new Utilities();
BluetoothSerial* bluetooth_serial_pointer = new BluetoothSerial();

void setup() {
  Serial.begin(115200);
}

void loop() {
  utilities_pointer->serialPrintString(
    bluetooth_serial_pointer->pairingMode()
  );
}