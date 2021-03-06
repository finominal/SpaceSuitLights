#include "FastLED.h"

volatile int currentProgram = 0;

#define DATA_PIN 3
#define NUM_LEDS 42
#define BRIGHTNESS  128
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 30

uint8_t armLeft[] = {0,1,2,3,4,5,6,7,8,9,10};
uint8_t fanLights[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
uint8_t threeFront[] = {21, 22,23};
uint8_t armRight[] = {24, 25,26,27,28,29,30,31,32,33,34};
//fix below
uint8_t fiberCaripace[] = {35,36};
int rotatorPin = 5;


CRGBPalette16 currentPalette;
TBlendType    currentBlending;

int numberOfPrograms = 4; //used in serial program change

void setup() 
{
  Serial.begin(9600);
  
  //Serial.println();
  //Serial.println("***SystemRestart***");
  //Serial.println();
  
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(  BRIGHTNESS );

  InitializeRotatorLight();
  
  LedPowerUp();//Will glow all greens

  //WaitForButtonPress(); // holds the system until a button is pressed.

  //ReadButtons();
  //PrintAnalogPorts();
  //PrintButtonStates();
}

void loop() 
{

  CheckForSerialProgram(); //acccepts numerical program changes via serial
  
  ActionLedProgram();

  ActionRotator();
}



