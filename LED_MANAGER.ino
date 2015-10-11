long frontLightsNextChange = 0;
volatile int currentProgram = 1;

void CheckProgramChange()
{
  if(UP==true)    {currentProgram = 0;}
  if(DOWN==true)  {currentProgram = 1;}
  if(LEFT==true)  {currentProgram = 2;}
  if(RIGHT==true) {currentProgram = 3;}
}

void ActionLedProgram()
{
  //Serial.println("ActionLedProgram");
  
  CheckProgramChange();
  
  switch(currentProgram)
  {
    case 0:
      Program0();
      break;
    case 1:
      Program1();
      break;
    case 2:
      ProgramPallet();
      break;
    case 3:
      Pulsator(CRGB::White);
      break; 

    default: 
    currentProgram = 0; //reset if outside the program values
    break;
  }
  //Serial.print("currentProgram=");Serial.println(currentProgram);
}

void Program0()
{
   ArmsStatic(CRGB::OrangeRed);
   FanLightsRotate(CRGB::Blue);
   FrontLightsRandom();
   FastLED.show();
}

void Program1()
{
   FanLightsSparkle();
   ArmsStatic(CRGB::Green);
   FrontLightsRandom();
   FastLED.show();
   delay(5);
}

void FrontLightsRandom()
{
  //Serial.println("FrontLightsRandom");
  if(frontLightsNextChange < millis())
  {
    //Serial.println("FrontLightsRandom-triggered");
    leds[threeFront[random(3)]] =  GetRandomColor();
    frontLightsNextChange = millis()+1000;
  }
}

void ArmsStatic(CRGB color)
{
  for(int i = 0; i<11;i++)
  {
    leds[armLeft[i]] = color;
  }    

  for(int i = 0; i<9;i++)
  {
    leds[armRight[i]] = color;
  }    
}

void Pulsator(int color)
{
    //reset all the fan lights
  for(int i = 0; i<NUM_LEDS;i++)
  {
    leds[i] = color;
  }    
  FastLED.show();

  delay(50);

  //reset all the fan lights
  for(int i = 0; i<NUM_LEDS;i++)
  {
    leds[i] = CRGB::Black;
  }    
   FastLED.show();
   delay(50);
}





void LedPowerUp()
{
  Serial.println();
  Serial.println("LedPowerUp");
  int bright = 0;

FastLED.setBrightness(bright);

    for(int i = 0; i<NUM_LEDS; i++)
    {
      leds[i] = CRGB::OrangeRed;
    }
  
  while(bright<255)
  {
    
    FastLED.setBrightness(bright);
    FastLED.show();
    delay(10);
    
    bright++; //add one in case we are at low brightness, and muliplying doesnt work yet.
    //bright *= 1.3; //multiply to overcome log brightness
  }

  
  //dimdown
  while(bright>0)
  {

    FastLED.setBrightness(bright);
    FastLED.show();
    delay(10);
    
    bright--;
    //bright /= 1.3; //multiply to overcome log brightness
  }

  Serial.println("LedPowerUp EXIT");
  Serial.println();

//reset all leds
      for(int i = 0; i<NUM_LEDS; i++)
    {
      leds[i] = CRGB::Black;
    }
  
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.show();
 }




long GetRandomColor()
{
  int color;
  int rand = random(1,7);
  
  //Serial.println(rand);
  switch(rand)
  {
        case 1:
     return CRGB::Green;
    break;
        case 2:
     return CRGB::Blue;
    break;
        case 3:
     return CRGB::Yellow;
    break;
        case 4:
     return CRGB::Purple;
    break;
        case 5:
     return CRGB::Aqua;
    break;
    case 6:
      return CRGB::Red;
    break;

  }
  //Serial.println(color);
  return color;
  }



  // Create a 24 bit color value from R,G,B
uint32_t Color(byte r, byte g, byte b)
{
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}
