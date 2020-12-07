# ESP32 wifi guitar pedal

This repository requires, platformio to work, we are looking to
accomplish a well structure firmware for our iot device

## Getting started on the devteam

Before you try running this code, you have 2 options, you can install de
platformio extension for atom, vscode or your ide of preference, or you can just
use the platformio python cli.

For more deep instructions for platformio read the [documentation](https://platformio.org/)

### Python CLI

If you want to use this method we add the requirements.txt so you just run

```
$ pip install -r requirements.txt
```

For my self i use virtualenv to have everything content on the same folder and
we have a modules folder ignore on the git ignore, if you want to use this method
just run the following

```
$ virtualenv --python=python3 modules
$ source modules/bin/activate
$ pip install -r requirements.txt
```

For more deep instructions of virtualenv read the [documentation](https://virtualenv.pypa.io/en/latest/)

## Run the code

Read a little of the platformio documentation, but most of the time we use
this commands


```
$ pio run
$ pio run --target upload
$ pio device monitor -b 115200
```

Each command has his own function, run is for compile the code, run upload is for
uploading the new code into our esp32, and device monitor is use to monitor
the serial.

Before you run the pio run command the platform requieres a env.h file
This is a little snipped of what you need to put on that

```
#define API "http://localhost.com"
#define serialNumber "useTheOneProvidedOnTheBoard"
```
