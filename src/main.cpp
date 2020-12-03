#include <Arduino.h>
#include <string.h>

#include "modules/BluetoothSerial.h"
#include "modules/Utilities.h"
#include "modules/WifiConnection.h"

using namespace std;

BluetoothSerial bluetooth_serial;
Utilities utilities;
WifiConnection* wifi_connection_pointer = new WifiConnection();

/**
  * Setup all the previews initial commands
*/
void setup() {
  Serial.begin(115200);
  wifi_connection_pointer->setupWifi();
}

/**
  * Loop function, if you want something to be done on the esp putit here
  * 
*/
void loop() {
  
}