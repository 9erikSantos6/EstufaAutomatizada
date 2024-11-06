// DHT Temperature & Humidity Sensor
// Unified Sensor Library Example
// Written by Tony DiCola for Adafruit Industries
// Released under an MIT license.

// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include <Arduino.h>
#include "SensorTemperatura.h"

#define DHTPIN 2
#define DHTTYPE DHT22

SensorTemperatura sensorTemp(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(9600);
  sensorTemp.init();
  sensorTemp.mostrarInformacoes();
}

void loop() {
  Serial.println(sensorTemp.captarTemperatura());
}