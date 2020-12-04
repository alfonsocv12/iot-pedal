#ifndef WIFI_CONNECTION_H
#define WIFI_CONNECTION_h
#include <string>
#include <HTTPClient.h>
#include <WiFiMulti.h>

using namespace std;
using namespace WiFiMulti;

class WifiConnection {
    private:
        int constructor;
        string handleErrors(HTTPClient*, int);
    public:
        WifiConnection(): constructor(1) {}
        WiFiMulti* setupWifi();
        string request(char*, char*);
};

#endif