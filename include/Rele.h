#ifndef __RELE_
#define __RELE_

#include <Arduino.h>

class Rele {
private:
  uint8_t port;
  bool ligado;

public:
  Rele::Rele(uint8_t port);

  void init();
  void ligar();
  void desligar();
  bool estaLigado();
};

#endif