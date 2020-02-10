/**
 * 4.5 inch infinity mirrir with a slider to change brightness
 *
 */
#include "Arduino.h"

// Set LED_BUILTIN if it is not defined by Arduino framework
// #define LED_BUILTIN 13
#define RED 11
#define GREEN 10
#define BLUE 9
#define SLIDER A3

const int COLOUR_TIME_LENGTH = 3000;
unsigned long lastColorChange = millis(); 


// function converts a regular RGB number to one in the 0 - 1023 range (roughly)
int rgbConverter(float number) {
  int result;
  result = 1023 - (number * 4);
  return result;
}

// function sends the colour to the LEDs, wit the correct brightness
void doColour(float r, float g, float b) {
  float sliderLevel = float (analogRead(SLIDER)) / 1023;
  // Serial.println(sliderLevel);
  analogWrite(RED, (r * sliderLevel));
  analogWrite(GREEN, (g * sliderLevel));
  analogWrite(BLUE, (b * sliderLevel));
}

// function makes sure numbers never overshoot 255 and never go negative
float correctNumber(float number) {
  if (number >= 255) {
    number = 255;
  } else if (number <= 0) {
    number = 0;
  }
  return number;
}


float r = 255;
float g = 0;
float b = 0;
float r2;
float g2;
float b2;

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  Serial.begin(9600);

}



void loop()
{

  doColour(r, g, b);

  // if the the last time the colour changed subtracted from the current time is COLOUR_TIME_LENGTH
  // choose a new colour and resent the last time the colour changed to now
  if ((millis() - lastColorChange) >= COLOUR_TIME_LENGTH) {
    // Target colour
    r2 = round(random(0, 255));
    g2 = round(random(0, 255));
    b2 = round(random(0, 255));
    lastColorChange = millis();
  }

  // change r, g, b by 0.5 every time this loop runs, either increasing or decreasing to get to the new
  // target colour
  do {
    float changeBy = 0.5;
    if (r2 > r) {
      r = correctNumber(r + changeBy);
    } else if (r2 < r) {
      r = correctNumber(r - changeBy);
    }

    if (g2 > g) {
      g = correctNumber(g + changeBy);
    } else if (g2 < g) {
      g = correctNumber(g - changeBy);
    }

    if (b2 > b) {
      b = correctNumber(b + changeBy);
    } else if (b2 < b) {
      b = correctNumber(b - changeBy);
    }
    doColour(r, g, b);
    // Serial.println(r);
    // Serial.println(g);
    // Serial.println(b);
    delay(3);
  } while ( (r != r2) || (g != g2) || (b != b2) );

}

