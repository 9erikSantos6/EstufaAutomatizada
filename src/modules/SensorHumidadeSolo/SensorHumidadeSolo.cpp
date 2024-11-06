#include <Arduino.h>
#include <DHT.h>
#include <DHT_U.h>
#include  "SensorHumidadeSolo.h"

SensorHumidadeSolo::SensorHumidadeSolo(uint8_t port) {
    this->port = port;
}

void SensorHumidadeSolo::init() {
    pinMode(port, INPUT);
}

boolean SensorHumidadeSolo::getPortValue() {
    return analogRead(this->port);
}