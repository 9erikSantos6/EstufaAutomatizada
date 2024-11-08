#ifndef __SENSOR_HUMIDADE_SOLO_
#define __SENSOR_HUMIDADE_SOLO_

#include <Arduino.h>
#include "Rele.h"

class SensorHumidadeSolo {
    private: 
        uint8_t port;

    public:
        SensorHumidadeSolo(uint8_t port);

        void init();
        boolean getPortValue();
        void ativarQuando();
        void gerenciarRele(Rele rele);
};

#endif