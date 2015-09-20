int fanLightsLoc = 0;
int fanLightsLastMovement = 0;
long nextAnimationChangeTime = 0;
long changeIntervalMS = 40;

void FanLightsRotate(int color)
{
  //turn off last light

if(nextAnimationChangeTime < millis())
 {
  //reset all the fan lights
  for(int i = 0; i<9;i++)
  {
    leds[fanLights[i]] = CRGB::Black;
  }
    
    if(fanLightsLoc>=8)
    {fanLightsLoc = 0;}
    else
    {fanLightsLoc++;}
    
       
    leds[fanLights[fanLightsLoc]] = color;
    
    nextAnimationChangeTime = millis() + changeIntervalMS;
 }//end if statement for timer
  
}


void FanLightsSparkle()
{

if(nextAnimationChangeTime < millis())
 {
      //reset all the fan lights
  for(int i = 0; i<9;i++)
  {
    leds[fanLights[i]] = CRGB::Green;
  }

    fanLightsLoc = random(0,9);//upper value is exclusive so go one higher.
    leds[fanLights[fanLightsLoc]] = CRGB::White;
    
    nextAnimationChangeTime = millis() + changeIntervalMS;
 }//end if statement for timer
  
}
