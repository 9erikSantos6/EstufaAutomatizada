#include  "SensorHumidadeSolo.h"
#include "BombaIrrigacao.h"

SensorHumidadeSolo::SensorHumidadeSolo(uint8_t port) : port(port) {}

void SensorHumidadeSolo::init() {
    pinMode(port, INPUT);
}

boolean SensorHumidadeSolo::soloHumido() {
    return digitalRead(this->port);
}

void SensorHumidadeSolo::controlarBombaIrrigacao(BombaIrrigacao bomba) {
    if (!this->soloHumido()/*&& !bomba.estadoBomba()*/) { 
      bomba.iniciarIrrigacao();
      Serial.println("BOMBA DESLIGADA");
    } else if (this->soloHumido() /*&& bomba.estadoBomba()*/) {
      bomba.pararIrrigacao();
      Serial.println("BOMBA LIGADA");
    }
}