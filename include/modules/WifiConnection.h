#ifndef WIFI_CONNECTION_H
#define WIFI_CONNECTION_h
#include <string>
#include <HTTPClient.h>
#include <WiFiMulti.h>
#include <WebServer.h>

#include "env.h"

class WiFiConnection {
    private:
        int construct;
        WiFiMulti* wifi_multi;
        std::string handleErrors(HTTPClient*, int);
        void startAP();
        std::string mac_address;
        std::string ssid;
        std::string password;
        bool connected = false;
        void serverStart();
        void connectWifi();
    public:
        WiFiConnection() {
            WiFi.mode(WIFI_STA);
            WiFi.begin();
            delay(1000);
            if(WiFi.status() != WL_CONNECTED) {
                startAP();
                Serial.print("Mac address: ");
	        Serial.println(mac_address.c_str());
	        Serial.println("");
	        Serial.print("ssid: ");
	        Serial.println(AP_NAME);
	        Serial.print("password: ");
                Serial.println(AP_PASSWORD);
                serverStart();
            }
        }
        void notFound();
        void response();
        WebServer* server;
        void reciveData();
        std::string request(char);
};

#endif