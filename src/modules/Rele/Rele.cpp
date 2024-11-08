#include <Arduino.h>
#include "Rele.h"


Rele::Rele(uint8_t port) : port(port), estadoLigado(false) {}

void Rele::init() {
  pinMode(port, OUTPUT);
}

void Rele::ligar() {
  digitalWrite(this->port, HIGH);
}

void Rele::desligar() {
  digitalWrite(this->port, LOW);
}

bool Rele::estaLigado() {
  return this->estadoLigado;
}