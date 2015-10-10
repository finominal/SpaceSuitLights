int fanLightsLoc = 0;
int fanLightsLastMovement = 0;
int lastLight = 0;
long nextAnimationChangeTime = 0;
long changeIntervalMS = 10;

void FanLightsRotate(CRGB color)
{
  //turn off last light

if(nextAnimationChangeTime < millis())
 {
  //reset all the fan lights
  for(int i = 0; i<10;i++)
  {
    leds[fanLights[i]] = CRGB::Black;
  }

    //move to the next led locaiton
    if(fanLightsLoc >= 9)//nine lights, zero index, max = 8
    {fanLightsLoc = 0;}
    else
    {fanLightsLoc++;}
    
       
    leds[fanLights[fanLightsLoc]] = color;
    
    nextAnimationChangeTime = millis() + changeIntervalMS;
 }//end if statement for timer
  
}


void FanLightsSparkle()
{
  //reset all the fan lights
  for(int i = 0; i<10;i++)
  {
    leds[fanLights[i]] = CRGB::Green;
  }
  

  if(nextAnimationChangeTime < millis())
  {
    while(fanLightsLoc == lastLight) {fanLightsLoc = random(0,10);}
    leds[fanLights[fanLightsLoc]] = CRGB::White;
    lastLight = fanLightsLoc;
    
    nextAnimationChangeTime = millis() + changeIntervalMS;
 }//end if statement for timer
  
}
