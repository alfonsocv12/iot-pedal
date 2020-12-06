#include <WiFi.h>
#include <HTTPClient.h>

#include "env.h"
#include "modules/WiFiConnection.h"
#include "modules/Utilities.h"


/**
 * Start WiFi as accespoint if needed
*/
void WiFiConnection::startAP() {
	WiFi.mode(WIFI_STA);
	WiFi.disconnect();
	delay(100);
	setup();
}

/**
 * Setup AP
*/
void WiFiConnection::setup() {
	WiFi.mode(WIFI_MODE_AP);

	uint8_t mac[6];
	char macStr[18] = { 0 };

	esp_wifi_get_mac(WIFI_IF_STA, mac);
	sprintf(macStr, "%02X-%02X", mac[4], mac[5]);
	std::string defaultap =  "esp32-" + String(macStr);

	preferences.begin("wifi", true);
	networkNameServer 	= preferences.getString("ssid", 					"none");    //NVS key ssid
	networkPswdServer 	= getPassword(networkNameServer); //NVS key password
	apNameServer 		= preferences.getString("apssid",					defaultap); //NVS key ssid
	apPswdServer 		= getPassword(apNameServer, "Wumpus3742"); 
	preferences.end();

	staticRef = this;
	connectionAttempts = 0;
	WiFi.onEvent(WiFiEventWifiManager);
	connectionAttempts = 1;
	setupDone = true;
}

/**
 * This function is dedicated to estart de server loop for reciving the wifi and password
*/
void WiFiConnection::serverStart() {
    server->handleClient();
	// server->on("/", );
	// server->on("/wifi", HTTP_POST, std::bind(&WiFi));
	// server->on("/", );
	server->begin();
    loop();
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