#include <WiFi.h>
#include <HTTPClient.h>

#include "modules/WiFiConnection.h"
#include "modules/Utilities.h"


/**
 * Put wifi on AP mode
*/
void WiFiConnection::startAP() {
	WiFi.disconnect(true);
	server = new WebServer(80);
	WiFi.mode(WIFI_MODE_AP);
	mac_address = WiFi.macAddress().c_str();
	WiFi.softAP(AP_NAME, AP_PASSWORD);
}

/**
 * This function is dedicated to estart de server loop for reciving the wifi and password
*/
void WiFiConnection::serverStart() {
	server->begin();
	server->on("/", std::bind(&WiFiConnection::response, this));
	server->on("/LED", HTTP_POST, std::bind(&WiFiConnection::response, this));
	server->onNotFound(std::bind(&WiFiConnection::notFound, this));
	while(1) {
		if(connected) break;
		if(ssid != "" && password != "") {
			connectWifi();
		}
		server->handleClient();
	}
}

/**
 * 
*/
void WiFiConnection::connectWifi(){
	Serial.println("Try connecting ...");
	WiFi.mode(WIFI_STA);
	WiFi.disconnect(true);
	delay(100);
	WiFi.begin(ssid.c_str(), password.c_str());
	int count = 0;
	Serial.print("Connectiong ..");
	while(WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print("..");
		count += 1;
	}
	Serial.println("");
	Serial.print("connected time: ");
	Serial.println(count*500);
	connected = true;
}

/**
 * Request to the server returning payload or error
 * 
 * @param url thats the url of the server to request
 * @param path the path or route for the server
 * @return payload string
*/
std::string WiFiConnection::request(char path) {
    if((wifi_multi->run() == WL_CONNECTED)) {
        Utilities util;
        HTTPClient* http = new HTTPClient();
        std::string url(std::string(API) + path);
        http->begin(url.c_str());
        int httpCode = http->GET();
        std::string payload = handleErrors(http, httpCode);
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
std::string WiFiConnection::handleErrors(HTTPClient* http, int code) {
    if (code > 0) {
        return http->getString().c_str();
    }
    return "Error on request code: "+code;
}

/**
 * Landign of the server
*/
void WiFiConnection::response() {
    ssid = server->arg("s").c_str();
    password = server->arg("p").c_str();
	server->send(200, "text/plain", "ready prras");
}


/**
 * Not found function for the server
*/
void WiFiConnection::notFound() {
    server->send(400, "text/plain", "tranquilo mate");
}