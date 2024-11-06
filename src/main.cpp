#include <Arduino.h>
#include "SensorTemperatura.h"

#define DHTPIN 2
#define DHTTYPE DHT11

SensorTemperatura sensorTemp(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(9600);
  sensorTemp.init();
  sensorTemp.mostrarInformacoes();
}

void loop() {
  delay(sensorTemp.pegarDelay());
  Serial.println(int(sensorTemp.captarTemperatura()));
  Serial.print("°");
}