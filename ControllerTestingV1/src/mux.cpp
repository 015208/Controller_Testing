#include <mux.h>

Mux::Mux(uint8_t S0, uint8_t S1, uint8_t S2, uint8_t S3, uint8_t SIG) : m_S0(S0), m_S1(S1), m_S2(S2), m_S3(S3), m_SIG(SIG)
{
    pinMode(m_S0, OUTPUT);
    pinMode(m_S1, OUTPUT);
    pinMode(m_S2, OUTPUT);
    pinMode(m_S3, OUTPUT);
    digitalWrite(m_S0, LOW);
    digitalWrite(m_S1, LOW);
    digitalWrite(m_S2, LOW);
    digitalWrite(m_S3, LOW);
}

void Mux::selectChannel(uint8_t selChannel)
{
    int Bit0 = bitRead(selChannel, 0);
    int Bit1 = bitRead(selChannel, 1);
    int Bit2 = bitRead(selChannel, 2);
    int Bit3 = bitRead(selChannel, 3);
    digitalWrite(m_S0, Bit0);
    digitalWrite(m_S1, Bit1);
    digitalWrite(m_S2, Bit2);
    digitalWrite(m_S3, Bit3);
}

void Mux::getAllData()
{
    for (int i = 0; i < 16; i++)
    {
        selectChannel(i);
        arr[i] = analogRead(m_SIG);
    }
}

int16_t Mux::getAnalogData(uint8_t channel)
{
    return arr[channel];
}

int Mux::getDigitalData(uint8_t channel) // switch > 682 -> 5V return 2,
                                         // 341 < switch < 681 -> 2.5V return 1,
                                         // switch <341 -> 0V return 0
{
    int16_t buttonState = arr[channel];
    if (buttonState >= 768)
        return 1;

    if (buttonState >= 511 && buttonState <= 767)
        return 2;

    return 0;
}

void Mux::showData()
{
    for (int i = 0; i < 16; i++)
    {
        if (i == 15)
        {
            Serial.println(arr[i]);
        }
        else
        {
            Serial.print(arr[i]);
            Serial.print(",");
        }
    }
}
