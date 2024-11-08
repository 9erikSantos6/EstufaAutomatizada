#include <Arduino.h>
#include <DHT.h>
#include <DHT_U.h>
#include  "SensorHumidadeSolo.h"
#include "Rele.h"

SensorHumidadeSolo::SensorHumidadeSolo(uint8_t port) {
    this->port = port;
}

void SensorHumidadeSolo::init() {
    pinMode(port, INPUT);
}

boolean SensorHumidadeSolo::getPortValue() {
    return analogRead(this->port);
}

void SensorHumidadeSolo::gerenciarRele(Rele rele) {
    if (this->getPortValue() && !rele.estaLigado()) { 
      rele.ligar();
    } else if (!this->getPortValue() && rele.estaLigado()) {
      rele.desligar();
    }
}