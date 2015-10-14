boolean rotatorOn = false; 
long nextRotatorToggleTime = 0;
int rotatorBrightness = BRIGHTNESS;

void InitializeRotatorLight()
{
   pinMode(5,OUTPUT);
   digitalWrite(5, HIGH);//turn off the rotator, reverse polarity to action: LOW = ON
}

  
void CheckForRotatorToggle()
{
  
  if (B == true && nextRotatorToggleTime < millis() ) //if button pressed and its time to toggle
  {
    
    Serial.println("Rotator Button Press Detected");
    rotatorOn = !rotatorOn; //flip state
    
    nextRotatorToggleTime = millis() + 1000; //set the next toggle time, stops flipping and helps debounce
  
    while(B == true) //wait for let go of buttons
    {
      ReadButtons();//read for change
    } 
    
  }

  ActionRotator(); //electrically action the rotator state. (may have changed)
  
}

void ActionRotator()
  {
     if(rotatorOn == true) //action state
    {
      digitalWrite(5,LOW);

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
      digitalWrite(5,HIGH);

      //Bring the main lights brightness back up to max.
      if(rotatorBrightness < BRIGHTNESS)
      {
        rotatorBrightness++;
        FastLED.setBrightness(rotatorBrightness);
       }
      
      //Serial.println("Rotator Turned off");
    }
 }
