#include <Arduino.h>
#include <constants.h>
#include <mux.h>

Mux datas(PIN_S0, PIN_S1, PIN_S2, PIN_S3, PIN_SIG);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  datas.getAllData();
  datas.showData();
  // Serial.println(datas.getDigitalData(1));
}
