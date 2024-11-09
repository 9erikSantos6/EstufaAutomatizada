#ifndef __RELE_H_
#define __RELE_H_
#include <Arduino.h>

class Rele {
  private:
    uint8_t port;
    bool estadoRele;

  public:
    Rele(uint8_t port);

    void init();
    void ligar();
    void desligar();
    bool estado();
};

#endif