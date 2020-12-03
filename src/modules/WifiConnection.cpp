#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>

#include "WifiConnection.h"
#include "Utilities.h"

WiFiMulti wifiMulti;

void WifiConnection::setupWifi() {
  for(uint8_t t = 4; t > 0; t--) {
        Serial.printf("[SETUP] WAIT %d...\n", t);
        Serial.flush();
        delay(1000);
    }

  wifiMulti.addAP("Chatrol5/1", "Chihuahua123");
}

string WifiConnection::request(char* url, char* path) {
    if((wifiMulti.run() == WL_CONNECTED)) {
        Utilities util;
        HTTPClient* http = new HTTPClient();
        http->begin(url);
        int httpCode = http->GET();
        string payload = handleErrors(http, httpCode);
        http->end();
        delete http;
        return payload;
    }
    return NULL;
}

string WifiConnection::handleErrors(HTTPClient* http, int code) {
    if (code > 0) {
        return http->getString().c_str();
    }
    return "Error on request code: "+code;
}