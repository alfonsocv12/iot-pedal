#include <Arduino.h>
#include <string.h>
#include <WiFi.h>

#include "modules/WiFiConnection.h"

WiFiConnection* wifi_connection;

/**
  * Setup all the previews initial commands
*/
void setup() {
  Serial.begin(115200);
  wifi_connection = new WiFiConnection();
}


/**
  * Loop function, if you want something to be done on the esp putit here
  *
*/
void loop() {
  Serial.println("connected");
  delay(1000);
}
