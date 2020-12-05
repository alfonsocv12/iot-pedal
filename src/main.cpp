#include <Arduino.h>
#include <string.h>

// #include "modules/Utilities.h"
#include "modules/WiFiConnection.h"

WebServer server(80);
WiFiConnection* wifi_connection;

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
  // server->on("/", reciveData);
  server.begin();
  // wifi_connection = new WiFiConnection();
  // Utilities utilities;
  // wifi_connection->server->handleClient();
  // wifi_connection->manager.loop();
	// if (wifi_connection->manager.getState() == Connected) {
	// 	// use the Wifi Stack now connected and a device is connected to the AP
  //   // WebServer* server = new WebServer(80);
	// }
}