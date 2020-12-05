#include <WiFi.h>
#include <HTTPClient.h>

#include "env.h"
#include "modules/WiFiConnection.h"
#include "modules/Utilities.h"


/**
 * 
*/
void WiFiConnection::serverStart() {
    server->handleClient();
    manager.loop();
	if (manager.getState() == Connected) {
		// use the Wifi Stack now connected and a device is connected to the AP
	}
}

/**
 * Request to the server returning payload or error
 * 
 * @param url thats the url of the server to request
 * @param path the path or route for the server
 * @return payload string
*/
string WiFiConnection::request(char path) {
    if((wifi_multi->run() == WL_CONNECTED)) {
        Utilities util;
        HTTPClient* http = new HTTPClient();
        string url(string(API) + path);
        http->begin(url.c_str());
        int httpCode = http->GET();
        string payload = handleErrors(http, httpCode);
        http->end();
        delete http;
        return payload;
    }
    return NULL;
}

/**
 * Here its where we check if the response was and error and return it
 * 
 * @param http that is the pointer to the http object
 * @param code the response integer
 * @return payload string 
*/
string WiFiConnection::handleErrors(HTTPClient* http, int code) {
    if (code > 0) {
        return http->getString().c_str();
    }
    return "Error on request code: "+code;
}