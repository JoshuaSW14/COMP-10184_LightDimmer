//I, Joshua Symons-Webb, 000812836 certify that this material is my original work. No
//other person's work has been used without due acknowledgement.

#include <Arduino.h>

int led = LOW;
int buttonState;
int lastButtonState;

void setup()
{
  Serial.begin(115200);

  pinMode(D5, INPUT_PULLUP); //Button Pin
  pinMode(D4, OUTPUT); //On Board LED

  buttonState = digitalRead(D5); //Sets the button state
}

void loop()
{
  float iVal;
  int aVal;

  aVal = analogRead(A0); //Reads the value from the variable resistor
  iVal = map(aVal, 0, 1023, 0, 255); //Maps the variable resistor value to the LED value

  lastButtonState = buttonState;
  buttonState = digitalRead(D5);

  if (lastButtonState == HIGH && buttonState == LOW) //If button is pressed
  {
    led = !led; //If LED is On, turn off. If LED is Off, turn on.
  }

  if (led == 1) //If LED State is On
  {
    analogWrite(D4, iVal);
  }else{ //If LED State is Off
    digitalWrite(D4, HIGH);
  }

  delay(1); //Delay added because of possible double button press
}