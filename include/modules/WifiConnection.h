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
        bool connected;
    public:
        WiFiConnection() {
            WiFi.mode(WIFI_STA);
            WiFi.begin();
            delay(100);
            if(WiFi.status() != WL_CONNECTED) {
                startAP();
                serverStart();
            } else {
                Serial.println("Connected");
            }
        }
        void notFound();
        void response();
        void serverStart();
        WebServer* server;
        void reciveData();
        std::string request(char);
};

#endif