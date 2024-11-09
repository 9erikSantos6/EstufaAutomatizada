#include  "SensorHumidadeSolo.h"
#include "BombaIrrigacao.h"

SensorHumidadeSolo::SensorHumidadeSolo(uint8_t port) : port(port) {}

void SensorHumidadeSolo::init() {
    pinMode(port, INPUT);
}

boolean SensorHumidadeSolo::soloSeco() {
    return analogRead(this->port);
}

void SensorHumidadeSolo::controlarBombaIrrigacao(BombaIrrigacao bomba) {
    if (this->soloSeco() && !bomba.estadoBomba()) { 
      bomba.iniciarIrrigacao();
    } else if (!this->soloSeco() && bomba.estadoBomba()) {
      bomba.pararIrrigacao();
    }
}