boolean rotatorOn = false; 
long nextRotatorToggleTime = 0;

void ActionRotatorLight()
{
  ToggleRotator();
}

void ToggleRotator()
{
  
  if (B == true && nextRotatorToggleTime < millis() ) //if button pressed and its time to toggle
  {
    rotatorOn = !rotatorOn; //flip state
    Serial.println("Rotator Button Press Detected");
    
    nextRotatorToggleTime = millis() + 1000; //set the next toggle time
  
    if(rotatorOn == true) //action state
    {
      digitalWrite(4,LOW);
      Serial.println("Rotator Turned On");
    }
    else
    {
      digitalWrite(4,HIGH);
      Serial.println("Rotator Turned On");
    }
  
    while(B == true) //wait for let go of buttons
    {
      ReadButtons();//read for change
    } 

    Serial.println("Exit ToggleRotator");
    delay(5);//debounce buttons
  }
}
  
