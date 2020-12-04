#ifndef WIFI_CONNECTION_H
#define WIFI_CONNECTION_h
#include <string>
#include <HTTPClient.h>
#include <WiFiMulti.h>

using namespace std;

class WiFiConnection {
    private:
        WiFiMulti* wifi_multi;
        string handleErrors(HTTPClient*, int);
    public:
        WiFiConnection(){
            wifi_multi = new WiFiMulti();
            for(uint8_t t = 4; t > 0; t--) {
                Serial.printf("[SETUP] WAIT %d...\n", t);
                Serial.flush();
                delay(1000);
            }

            wifi_multi->addAP("Chatrol5/1", "Chihuahua123");
        }
        string request(char);
};

#endif