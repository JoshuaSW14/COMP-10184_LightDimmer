//I, Joshua Symons-Webb, 000812836 certify that this material is my original work. No
//other person's work has been used without due acknowledgement.

#include <Arduino.h>

int led = LOW;
int buttonState;
int lastButtonState;

void setup()
{
  Serial.begin(115200);

  pinMode(D5, INPUT_PULLUP);
  pinMode(D4, OUTPUT);

  buttonState = digitalRead(D5);
}

void loop()
{
  float iVal;
  int aVal;
  float resolution;

  resolution = 255 / (float)1024;
  aVal = analogRead(A0);
  iVal = resolution * aVal;

  lastButtonState = buttonState;
  buttonState = digitalRead(D5);

  if (lastButtonState == HIGH && buttonState == LOW)
  {
    led = !led;
  }

  if (led == 1)
  {
    Serial.println(iVal);
    analogWrite(D4, iVal);
  }else{
    digitalWrite(D4, HIGH);
  }

  // The variable resistor is used to control the LED brightness

  // Pressing the push button will turn off the LED, regardless of its brightness
  // Pessing the button again will turn on the LED, at the brightness level indicated by the variable resistor

  // While the LED is OFF, rotating the variable resistor must not cause the LED to illuminate
  // When first powered up, the LED must be off regardless of the variable resistor settings
}