#ifndef __MOTOR_PASSOS_
#define __MOTOR_PASSOS_
#include <CheapStepper.h>
#include <Arduino.h>


class MotorPassos {
  private:
    CheapStepper stepper;
    boolean sentidoHorario;

  public:
    MotorPassos(uint8_t port1, uint8_t port2, uint8_t port3, uint8_t port4);

    CheapStepper getStepper();

    void mostrarInformacoes();

    void definirRpm(int rpm);

    void definirSentidoHorario();
    void definirSentidoAntiHorario();

    void moverParaStep(int step);

    void moverParaGrau(int grau);

    int pegarPosicaoAtual();
};

#endif