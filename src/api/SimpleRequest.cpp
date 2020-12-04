#include "api/SimpleRequest.h"

std::string get(WiFiConnection* wifi) {
    return wifi->request("/");
}