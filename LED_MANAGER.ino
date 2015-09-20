long frontLightsNextChange = 0;

void ActionLedProgram()
{
  switch(currentProgram)
  {
    case 0:
      Program0();
      break;
    case 1:
      Program1();
      break;
  }
}

void Program0()
{
   FanLightsRotate(CRGB::Blue);
   ArmsOrange();
   FrontLightsRandom();
}

void Program1()
{
   FanLightsSparkle();
   ArmsOrange();
   FrontLightsRandom();
}

void FrontLightsRandom()
{
  if(frontLightsNextChange < millis())
  {
    leds[threeFront[random(3)]] =  pickColor();
    frontLightsNextChange = millis()+500;
  }
}

void ArmsOrange()
{
    //reset all the fan lights
  for(int i = 0; i<11;i++)
  {
    leds[armLeft[i]] = CRGB::Orange;
    leds[armRight[i]] = CRGB::Orange;
  }    
}



void LedPowerUp()
{
  int bright = 0;
  while(bright<255)
  {
    for(int i = 0; i>NUM_LEDS; i++)
    {
      leds[i] = CRGB::Green;
    }
    
    FastLED.show();
    delay(10);
    
    bright++; //add one in case we are at low brightness, and muliplying doesnt work yet.
    bright *= 1.3; //multiply to overcome log brightness
  }
  
  //dimdown
  while(bright>0)
  {
    for(int i = 0; i>NUM_LEDS; i++)
    {
      leds[i] = CRGB::Green;
    }
    
    FastLED.show();
    delay(1);
    bright--;
    bright /= 1.3; //multiply to overcome log brightness
  }
 }




long pickColor()
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
