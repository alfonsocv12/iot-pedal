#include <Arduino.h>
#include <string.h>

#include "modules/WiFiConnection.h"

WiFiConnection* wifi_connection = new WiFiConnection();

void response();

/**
  * Setup all the previews initial commands
*/
void setup() {
  Serial.begin(115200);
  wifi_connection->serverStart();
  wifi_connection->server->on("/", response);
}


/**
  * Loop function, if you want something to be done on the esp putit here
  * 
*/
void loop() {
  wifi_connection->manager.loop();
	if (wifi_connection->manager.getState() == Connected) {
		// use the Wifi Stack now connected and a device is connected to the AP
	}
}

/**
 * Function that returns the response
*/
void response(){
  Serial.println("request");
  wifi_connection->server->send(200, "text/plain", "ready");
}