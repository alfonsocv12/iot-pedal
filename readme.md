# ESP32 wifi guitar pedal

This repository requires, plataformio to work, we are looking to
acomplish a well structure firmware for our iot device

## Getting started on the devteam

Read a little of the plataformio documentation, but most of the time we use
this commands


```
$ pio run
$ pio run --target upload
$ pio device monitor -b 115200
```

Each command has his own function, run is for compile the code, run upload is for
uploading the new code into our esp32, and device monitor is use to monitor
the serial.

Before you run the pio run commant the plataform requieres a env.h file
This is a little snipped of what you need to put on that

```
#define API "http://localhost.com"
#define serialNumber "useTheOneProvidedOnTheBoard"
```