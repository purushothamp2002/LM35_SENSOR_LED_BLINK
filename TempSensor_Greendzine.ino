#include<elapsedMillis.h>

const int lm35Pin = A0;
//const int ledPin = 13;


void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  uint8_t Temp_ADC_Val;
  float tempVal;
  Temp_ADC_Val = analogRead(lm35Pin);
  tempVal = (Temp_ADC_Val * 4.88) / 10;

  if(tempVal < 30.0)
  {
    BlinkLed(250);
  }
  else if (tempVal >= 30.0) 
  {
    BlinkLed(500);
  }

}

void BlinkLed(int delay)
{
  static elapsedMillis previousMillis = 0;
  static int LedState = LOW;

  if(previousMillis >= delay)
  {
    previousMillis = 0;
    LedState = !LedState;
    digitalWrite(LED_BUILTIN,LedState);

  }
}
