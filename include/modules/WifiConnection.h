#ifndef WIFI_CONNECTION_H
#define WIFI_CONNECTION_h
#include <string>
#include <HTTPClient.h>
#include <WiFiMulti.h>
#include <WebServer.h>
#include <esp_wifi.h>
// #include <Esp32WifiManager.h>

class WiFiConnection {
    private:
        int construct;
        WiFiMulti* wifi_multi;
        std::string handleErrors(HTTPClient*, int);
        void startAP();
        void setup();
    public:
        WiFiConnection() {
            server = new WebServer(80);
            WiFi.mode(WIFI_STA);
            WiFi.begin();
            if(WiFi.status() != WL_CONNECTED) {
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
        std::string getPassword(std::string, std::string);
};

#endif