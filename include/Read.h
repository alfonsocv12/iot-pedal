#ifndef READ_H
#define READ_h

class Read {
    private:
        int constructor;
    public:
        Read(): constructor(1) {}
        int ReadAnalogPort();
};

#endif