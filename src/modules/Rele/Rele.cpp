#include <Arduino.h>
#include "Rele.h"


Rele::Rele(uint8_t port) : port(port), ligado(false){}

void Rele::ligar() {
  digitalWrite(this->port, HIGH);
}

void Rele::desligar() {
  digitalWrite(this->port, LOW);
}