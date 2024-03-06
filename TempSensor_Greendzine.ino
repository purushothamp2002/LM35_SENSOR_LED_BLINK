#include<elapsedMillis.h>

const int lm35Pin = A0; // analog pin to read analog reading from LM35 sensor



void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);  /// Set the built-in LED pin as an output

}

void loop() {
  // put your main code here, to run repeatedly:

  uint8_t Temp_ADC_Val;
  float tempVal;
  Temp_ADC_Val = analogRead(lm35Pin); // Read analog voltage from LM35
  tempVal = (Temp_ADC_Val * 4.88) / 10; /// Convert ADC value to temperature in Celsius

  if(tempVal < 30.0)
  {
    BlinkLed(250);   // Blink LED every 250 milliseconds if temperature is below 30°C
  }
  else if (tempVal >= 30.0)   // Blink LED every 500 milliseconds if temperature is 30°C or above
  {
    BlinkLed(500);
  }

}

// funtion to blink LED according to temperature
void BlinkLed(int delay)
{
  static elapsedMillis previousMillis = 0;
  static int LedState = LOW;

  if(previousMillis >= delay)
  {
    previousMillis = 0;
    LedState = !LedState;     // Toggle LED state
    digitalWrite(LED_BUILTIN,LedState); // Set the built-in LED state

  }
}
