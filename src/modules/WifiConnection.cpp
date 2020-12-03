#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>

#include "env.h"
#include "modules/WifiConnection.h"
#include "modules/Utilities.h"

WiFiMulti wifiMulti;

/**
 * Function dedicated to connect to wifi
*/
void WifiConnection::setupWifi() {
  for(uint8_t t = 4; t > 0; t--) {
        Serial.printf("[SETUP] WAIT %d...\n", t);
        Serial.flush();
        delay(1000);
    }

  wifiMulti.addAP("Chatrol5/1", "Chihuahua123");
}

/**
 * Request to the server returning payload or error
 * 
 * @param url thats the url of the server to request
 * @param path the path or route for the server
 * @return payload string
*/
string WifiConnection::request(char* url, char* path) {
    if((wifiMulti.run() == WL_CONNECTED)) {
        Utilities util;
        HTTPClient* http = new HTTPClient();
        http->begin(API);
        int httpCode = http->GET();
        string payload = handleErrors(http, httpCode);
        http->end();
        delete http;
        return payload;
    }
    return NULL;
}

/**
 * Here its where we check if the response was and error and return it
 * 
 * @param http that is the pointer to the http object
 * @param code the response integer
 * @return payload string 
*/
string WifiConnection::handleErrors(HTTPClient* http, int code) {
    if (code > 0) {
        return http->getString().c_str();
    }
    return "Error on request code: "+code;
}