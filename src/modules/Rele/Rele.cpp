#include "Rele.h"

Rele::Rele(uint8_t port) : port(port), estadoRele(LOW) {}

void Rele::init() {
  pinMode(port, OUTPUT);
}

void Rele::ligar() {
  this->estadoRele = HIGH;
  digitalWrite(this->port, HIGH);
}

void Rele::desligar() {
  this->estadoRele = LOW;
  digitalWrite(this->port, LOW);
}

bool Rele::estado() {
  return this->estadoRele;
}