#ifndef UTILITIES_H
#define UTILITIES_h
#include <string>
#include <HTTPClient.h>

using namespace std;

class WifiConnection {
    private:
        int constructor;
        string handleErrors(HTTPClient*, int);
    public:
        WifiConnection(): constructor(1) {}
        void setupWifi();
        string request(char*, char*);
};

#endif