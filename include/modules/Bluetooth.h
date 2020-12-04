#ifndef BLUETOOTH_H
#define BLUETOOTH_h
#include <string>

#include "BluetoothSerial.h"

using namespace std;

class Bluetooth {
    private:
        int constructor;
        void wifiNamePass(BluetoothSerial);
    public:
        Bluetooth() {
            BluetoothSerial SerialBT;
            if(!SerialBT.begin("IODAL")){
                Serial.println("Error occured with bluetooth");
            }
            Serial.println("init");
            // wifiNamePass(SerialBT);
        }
        void startConnection();
        string pairingMode();
};

#endif