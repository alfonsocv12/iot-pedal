#include <Arduino.h>
#include "Read.h"

Read* read_obj = new Read();

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println(read_obj->ReadAnalogPort());
}