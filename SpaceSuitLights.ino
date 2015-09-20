#include "FastLED.h"

#define DATA_PIN 2
#define NUM_LEDS 42

uint8_t armLeft[] = {0,1,2,3,4,5,6,7,8,9,10};
uint8_t fanLights[] = {11, 12, 13, 14, 15, 16, 17, 18, 19};
uint8_t threeFront[] = {20,21, 22};
uint8_t armRight[] = {23,24,25,26,27,28,29,30,31,32,33};
uint8_t fiberOne[] = {34,35};
uint8_t fiberTwo[] = {36,37};
uint8_t fiberThree[] = {38,39};
uint8_t fiberFour[] = {40,41};

CRGB leds[NUM_LEDS];

int currentProgram = 0;

void setup() 
{
  Serial.begin(9400);
  
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);

  LedPowerUp();//WIll glow all greens

  //WaitForButtonPress(); // holds the system until a button is pressed.
  
}

void loop() 
{
  ReadButtons();
  ActionRotatorLight();
  ActionLedProgram();
}



