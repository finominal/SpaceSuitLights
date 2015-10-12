void CheckForSerialProgram()
{
serialEvent();
}
 
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

     if(inByte == 9)
     {
       rotatorOn = !rotatorOn; //flip state
     }
     
  }
}
