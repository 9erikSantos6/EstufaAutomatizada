#include <Arduino.h>
#include "Botao.h"


Botao::Botao(uint8_t port) : port(port) {}

void Botao::init() {
  pinMode(this->port, INPUT_PULLUP);
}

bool Botao::pegarEstado() {
  if (digitalRead(this->port) == LOW) {
    delay(100);
    return true;
  }
  return false;
}