#pragma once
#include <Arduino.h>

class Mux
{
public:
    Mux(uint8_t S0, uint8_t S1, uint8_t S2, uint8_t S3, uint8_t SIG);
    void getAllData();
    int16_t getAnalogData(uint8_t channel);
    int getDigitalData(uint8_t channel);
    void showData();

private:
    uint8_t m_S0, m_S1, m_S2, m_S3, m_SIG;
    int16_t arr[16];

    void selectChannel(uint8_t selChannel);
};
