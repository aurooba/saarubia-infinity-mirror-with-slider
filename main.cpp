#include <Arduino.h>

int redPin = 11;
int greenPin = 10;
int bluePin = 9;

float sliderLevel = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    

}

void loop() {
  // put your main code here, to run repeatedly:
  sliderLevel = analogRead(A3);
  Serial.println(sliderLevel);

  delay(100);

  // analogWrite(LED_BUILTIN,sliderLevel);
  analogWrite(redPin,sliderLevel/4);
  analogWrite(greenPin,sliderLevel/4);
  analogWrite(bluePin,sliderLevel/4);

  // digitalWrite(redPin,HIGH);
  // digitalWrite(greenPin,LOW);
  // digitalWrite(bluePin,LOW);
  // Serial.println("Red");
  // delay(2000);

  // digitalWrite(redPin,LOW);
  // digitalWrite(greenPin,HIGH);
  // digitalWrite(bluePin,LOW);
  // Serial.println("Green");
  // delay(2000);

  // digitalWrite(redPin,LOW);
  // digitalWrite(greenPin,LOW);
  // digitalWrite(bluePin,HIGH);
  // Serial.println("Blue");
  // delay(2000);

}