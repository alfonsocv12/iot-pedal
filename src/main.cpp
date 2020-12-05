#include <Arduino.h>
#include <string.h>

#include "modules/WiFiConnection.h"

WiFiConnection* wifi_connection;

void response();

/**
  * Setup all the previews initial commands
*/
void setup() {
  Serial.begin(115200);
  wifi_connection = new WiFiConnection();
  wifi_connection->server->on("/", response);
}


/**
  * Loop function, if you want something to be done on the esp putit here
  * 
*/
void loop() {
  wifi_connection->serverStart();
}

/**
 * Function that returns the response
*/
void response(){
  wifi_connection->server->send(200, "text/plain", "ready prras");
}