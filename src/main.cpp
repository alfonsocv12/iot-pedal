#include <Arduino.h>
#include <string.h>

#include "modules/BluetoothSerial.h"
#include "modules/Utilities.h"
#include "modules/WiFiConnection.h"

WiFiConnection* wifi_connection;

/**
  * Setup all the previews initial commands
*/
void setup() {
  Serial.begin(115200);
  BluetoothSerial bluetooth_serial;
  wifi_connection = new WiFiConnection();
}

/**
  * Loop function, if you want something to be done on the esp putit here
  * 
*/
void loop() {
  Utilities utilities;
  delay(1000);
}