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
        WiFiMulti* wifi_multi;
        string handleErrors(HTTPClient*, int);
        void serverStart();
    public:
        WiFiConnection(){
            serverStart();
            // manager.setupAP();
        }
        // WebServer server;
        WifiManager manager;
        // void reciveData();
        string request(char);
};

#endif