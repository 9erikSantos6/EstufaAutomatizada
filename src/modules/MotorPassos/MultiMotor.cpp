/*
Ainda não implementado

*/

#include <Arduino.h>
#include "MultiMotor.h"

MultiMotor::MultiMotor(MotorPassos* motores, int quantidadeMotores, int grauDestino, int grauPorMovimento)
    : motores(motores), quantidadeMotores(quantidadeMotores), grauDestino(grauDestino), grauPorMovimento(grauPorMovimento) {}

void MultiMotor::moverMotoresEmSincronia() {
    if (this->grauDestino > 0) {
        for (int i = 0; i < this->quantidadeMotores; i++) {
            motores[i].moverParaGrau(this->grauPorMovimento);
            this->grauDestino -= grauPorMovimento;
            Serial.print("Motor ");
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.println(motores[i].pegarPosicaoAtual());
        }
    }
}
