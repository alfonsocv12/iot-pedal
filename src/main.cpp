#include <Arduino.h>
#include <string.h>

#include "modules/BluetoothSerial.h"
#include "modules/Utilities.h"
#include "api/SimpleRequest.h"

BluetoothSerial bluetooth_serial;
Utilities utilities;
WiFiConnection* wifi_connection = new WiFiConnection();

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
  delay(1000);
  utilities.serialPrintString(get(wifi_connection));
}