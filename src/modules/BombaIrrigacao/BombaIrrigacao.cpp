#include <Arduino.h>
#include "BombaIrrigacao.h"
#include "Rele.h"

BombaIrrigacao::BombaIrrigacao(uint8_t port) : rele(port) {}

void BombaIrrigacao::init() {
  this->rele.init();
}

void BombaIrrigacao::iniciarIrrigacao() {
    this->rele.ligar();
}

void BombaIrrigacao::pararIrrigacao() {
  this->rele.desligar();
}

bool BombaIrrigacao::estadoBomba() {
  return this->rele.estado();
}