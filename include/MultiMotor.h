#ifndef __MULTI_MOTOR_
#define __MULTI_MOTOR_
#include "MotorPassos.h"
#include "Arduino.h"

class MultiMotor{
    private:
    MotorPassos* motores;
    int quantidadeMotores;
    int grauDestino; 
    int grauPorMovimento;

    public:
        MultiMotor(MotorPassos* motores, int quantidadeMotores, int grauDestino, int grauPorMovimento);
        void moverMotoresEmSincronia();

};


#endif