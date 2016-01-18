boolean rotatorOn = false; 
long nextRotatorToggleTime = 0;
int rotatorBrightness = BRIGHTNESS;

void InitializeRotatorLight()
{
   pinMode(5,OUTPUT);
   digitalWrite(5, HIGH);//turn off the rotator, reverse polarity to action: LOW = ON
}

void ActionRotator()
  {
     if(rotatorOn == true) //action state
    {
      digitalWrite(rotatorPin,LOW);//low turns rotator on

      //dim the main brightness to emphasize the rotator
      if(rotatorBrightness > BRIGHTNESS/4)
      {
        rotatorBrightness--;
        FastLED.setBrightness(rotatorBrightness);
      }
      
      //Serial.println("Rotator Turned on");
    }
    else
    {
      digitalWrite(rotatorPin,HIGH);//low turns rotator on

      //Bring the main lights brightness back up to max.
      if(rotatorBrightness < BRIGHTNESS)
      {
        rotatorBrightness++;
        FastLED.setBrightness(rotatorBrightness);
       }
      
      //Serial.println("Rotator Turned off");
    }
 }
