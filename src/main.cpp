#include <Arduino.h>
#include "SensorTemperatura.h"
#include "MotorPassos.h"

#define DHTPIN 2
#define DHTTYPE DHT11

SensorTemperatura sensorTemp(DHTPIN, DHTTYPE);
MotorPassos motorPassos(1, 2, 3, 4);
MotorPassos mortoPassos2(8, 9, 10, 11);


void setup() {
  Serial.begin(9600);

  motorPassos.mostrarInformacoes();
  motorPassos.definirRpm(10);
  mortoPassos2.definirRpm(10);
}

void loop() {

  Serial.println(motorPassos.pegarPosicaoAtual());
  motorPassos.definirSentidoAntiHorario();
  motorPassos.moverParaStep(120);
  mortoPassos2.definirSentidoHorario();
  mortoPassos2.moverParaStep(120);
}