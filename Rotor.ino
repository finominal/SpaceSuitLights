boolean rotatorOn = false; 
long nextRotatorToggleTime = 0;
int rotatorBrightness = BRIGHTNESS;

void InitializeRotatorLight()
{
   pinMode(5,OUTPUT);
   digitalWrite(5, HIGH);//turn off the rotator 
}

  
void CheckRotatorLightButton()
{
  
  if (B == true && nextRotatorToggleTime < millis() ) //if button pressed and its time to toggle
  {
    rotatorOn = !rotatorOn; //flip state
    Serial.println("Rotator Button Press Detected");
    
    nextRotatorToggleTime = millis() + 500; //set the next toggle time
  
    while(B == true) //wait for let go of buttons
    {
      ReadButtons();//read for change
    } 

    Serial.println("Exit ToggleRotator");
    delay(5);//debounce buttons
  }
}

  void ActionRotator()
  {
     if(rotatorOn == true) //action state
    {
      digitalWrite(5,LOW);
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
      if(rotatorBrightness < BRIGHTNESS)
      {
        rotatorBrightness++;
        FastLED.setBrightness(rotatorBrightness);
       }
      
      //Serial.println("Rotator Turned off");
    }
 }
