#ifndef WIFI_CONNECTION_H
#define WIFI_CONNECTION_h
#include <string>
#include <HTTPClient.h>
#include <WiFiMulti.h>
#include <WebServer.h>
#include <Preferences.h>
#include <Esp32WifiManager.h>

class WiFiConnection {
    private:
        int construct;
        WiFiMulti* wifi_multi;
        std::string handleErrors(HTTPClient*, int);
    public:
        WiFiConnection() {
            server = new WebServer(80);
            manager.setup();
            server->on("/", std::bind(&WiFiConnection::response, this));
            server->on("/LED", HTTP_POST, std::bind(&WiFiConnection::response, this));
            server->onNotFound(std::bind(&WiFiConnection::notFound, this));
            server->begin();
        }
        void notFound();
        void response();
        void serverStart();
        WebServer* server;
        WifiManager manager;
        std::string request(char);
};

#endif