#ifndef __BOTAO_H_
#define __BOTAO_H_
#include <Arduino.h>

class Botao {
  private:
    uint8_t port;

  public:
    Botao(uint8_t port);

    void init();
    bool pegarEstado();
};

#endif