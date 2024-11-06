#ifndef __SENSOR_HUMIDADE_SOLO_
#define __SENSOR_HUMIDADE_SOLO_

#include <Arduino.h>

class SensorHumidadeSolo {
    private: 
        uint8_t port;

    public:
        SensorHumidadeSolo(uint8_t port);

        void init();
        boolean getPortValue();
};

#endif