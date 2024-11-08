#include "MotorPassos.h"
#include <Arduino.h>

MotorPassos::MotorPassos(uint8_t port1, uint8_t port2, uint8_t port3, uint8_t port4)
  : stepper(port1, port2, port3, port4), sentidoHorario(true) {}

void MotorPassos::mostrarInformacoes() {
  Serial.println();
  Serial.print(stepper.getRpm()); 
  Serial.print(" rpm = delay de ");
  Serial.print(stepper.getDelay());
  Serial.print(" microsegundos entre steps");
  Serial.println();
}

void MotorPassos::definirSentidoHorario() {
  this->sentidoHorario = true;
}

void MotorPassos::definirRpm(int rpm) {
  this->stepper.setRpm(rpm);
}

void MotorPassos::definirSentidoAntiHorario() {
  this->sentidoHorario = false;
}

void MotorPassos::moverParaStep(int step) {
  if (0 <= step && step <= 2048) {
    stepper.moveDegrees(sentidoHorario, step);
  }
}

void MotorPassos::moverParaGrau(int grau) {
  if (0 <= grau && grau <= 360) {
    stepper.moveDegrees(sentidoHorario, grau);
  }
}

int MotorPassos::pegarPosicaoAtual() {
  return this->stepper.getStep();
}


