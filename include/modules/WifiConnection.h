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
        int wait_connection(int count=1);
        bool connected = false;
        void serverStart();
        void connectWifi();
    public:
        WiFiConnection() {
            WiFi.mode(WIFI_STA);
            WiFi.begin();
            if(wait_connection() == 0) {
                startAP();
            }
        }
        void notFound();
        void response();
        WebServer* server;
        void reciveData();
        std::string request(char);
};

#endif
