#ifndef WIFI_CONNECTION_H
#define WIFI_CONNECTION_h
#include <string>
#include <HTTPClient.h>
#include <WiFiMulti.h>
#include <WebServer.h>
#include <Preferences.h>
#include <Esp32WifiManager.h>

using namespace std;

class WiFiConnection {
    private:
        int construct;
        WiFiMulti* wifi_multi;
        string handleErrors(HTTPClient*, int);
    public:
        WiFiConnection(){
            server = new WebServer(80);
            manager.setupAP();
            server->begin();
        }
        void serverStart();
        WebServer* server;
        WifiManager manager;
        void reciveData();
        string request(char);
};

#endif