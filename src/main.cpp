#include <Arduino.h>
#include <string.h>

#include <WiFi.h>
#include <WebServer.h>
#include <Preferences.h>
#include <Esp32WifiManager.h>

// #include "modules/Utilities.h"
// #include "modules/WiFiConnection.h"

// WiFiConnection* wifi_connection;
WebServer server(80);
WifiManager manager;

void handle_root() {
  String HTML = "<!DOCTYPE html>\
  <html>\
    <body>\
      <h1>Welcome</h1>\
      <p>Your first Iot Project made with ESP32</p>\
      <p>&#128522;</p>\
    </body>\
  </html>";
  server.send(200, "text/html", HTML);
}

/**
  * Setup all the previews initial commands
*/
void setup() {
  Serial.begin(115200);
  manager.setupAP();
  server.on("/", handle_root);
  server.begin();
  // wifi_connection = new WiFiConnection();
}

/**
  * Loop function, if you want something to be done on the esp putit here
  * 
*/
void loop() {
  // Utilities utilities;
  server.handleClient();
  manager.loop();
	if (manager.getState() == Connected) {
		// use the Wifi Stack now connected and a device is connected to the AP
    // WebServer* server = new WebServer(80);
	}
}