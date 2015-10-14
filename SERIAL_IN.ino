void CheckForSerialProgram()
{
  serialEvent();
}

//Serial Interrupts are meant to be intrinsic, but not observed to work. Perhaps hardware interrupt for serial needs to be enabled? 
//Hardware interrupts might cause glitching in the LEDS if enabled, so better to call manually.
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    int inByte = Serial.read();
    Serial.print("DataRecieved: "); Serial.println(inByte);
    inByte -= 48;
    Serial.print("DataModified: "); Serial.println(inByte);
     if(inByte < numberOfPrograms)
     {
       currentProgram = inByte;
       Serial.print("Program Set as "); Serial.println(inByte);
     }

     //Custom - Toggle Rotator - This variable must be actioned against later
     if(inByte == 9)
     {
       rotatorOn = !rotatorOn; //flip state
     }
     
  }
}
