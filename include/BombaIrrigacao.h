#ifndef __BOMBA_IRRIGACAO_H_
#define __BOMBA_IRRIGACAO_H_

#include <Arduino.h>
#include "Rele.h"

class BombaIrrigacao {
  private:
    Rele rele;

  public:
    BombaIrrigacao(uint8_t port);

    void init();
    void iniciarIrrigacao();
    void pararIrrigacao();
    bool estadoBomba();
};

#endif