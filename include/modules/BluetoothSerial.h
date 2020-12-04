#ifndef BLUETOOTH_SERIAL_H
#define BLUETOOTH_SERIAL_h
#include <string>

using namespace std;

class BluetoothSerial {
    private:
        int constructor;
    public:
        BluetoothSerial(): {
            
        }
        void startConnection();
        string pairingMode();
};

#endif