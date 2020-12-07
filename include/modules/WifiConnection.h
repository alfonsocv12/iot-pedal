#ifndef WIFI_CONNECTION_H
#define WIFI_CONNECTION_h
#include <string>
#include <HTTPClient.h>
#include <WebServer.h>

#include "env.h"

class WiFiConnection {
    private:
        std::string handleErrors(HTTPClient*, int);
        void startAP();
        std::string mac_address;
        std::string ssid;
        std::string password;
        int wait_connection(int count=1);
        bool connected = false;
        WebServer* server;
        void serverStart();
        void connectWifi();
        void notFound();
        void credentials_recive_route();
        void reciveData();
    public:
        WiFiConnection() {
            WiFi.mode(WIFI_STA);
            WiFi.begin();
            if(wait_connection() == 0) {
                startAP();
            }
        }
        std::string request(char);
};

#endif
