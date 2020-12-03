#ifndef UTILITIES_H
#define UTILITIES_h

class Utilities {
    private:
        int constructor;
    public:
        Utilities(): constructor(1) {}
        int readAnalogPort();
        void serialPrintString(string s);
};

#endif