boolean rotatorOn = false; 

void ActionRotatorLight()
{
  ToggleRotator();
}

void ToggleRotator()
{
  
  if (B == true) //if button pressed
  {
    rotatorOn = !rotatorOn; //flip state
    Serial.println("Rotator Button Press Detected");
  
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
  
