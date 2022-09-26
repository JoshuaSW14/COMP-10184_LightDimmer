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

  aVal = analogRead(A0);
  iVal = map(aVal, 0, 1023, 0, 255);

  lastButtonState = buttonState;
  buttonState = digitalRead(D5);

  if (lastButtonState == HIGH && buttonState == LOW)
  {
    led = !led;
  }

  if (led == 1)
  {
    analogWrite(D4, iVal);
  }else{
    digitalWrite(D4, HIGH);
  }
}