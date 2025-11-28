#include "BluetoothSerial.h"
#define pot 34
#include <

const float VREF = 3.3;

BluetoothSerial SerialBT

void setup() {
  Serial.begin(115200);               
  SerialBT.begin("ESP32_Potmeter");
  pinMode(pot, INPUT);
}

void loop() {
  int raw = analogRead(pot);              
  float voltage = (raw * VREF) / 4095.0; 

  Serial.println(voltage, 2);
  SerialBT.println(voltage, 2);        
  delay(500);
}
