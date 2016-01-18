

/* BUTTONS */
/*
THIS IS NOW IN THE SYSTEM COMTROLLER> 

At the time this was written there was only one controller operating 
for the leds. 

When the second system controller is created move this functionality out 
to that controller, and just pass in program numners via serial. 

*/

//if the buttons are not on the right alague ports, you can change them here. 
#define UP_BUTTON     A0
#define DOWN_BUTTON   A1
#define LEFT_BUTTON   A2
#define RIGHT_BUTTON  A3
#define A_BUTTON      A4
#define B_BUTTON      A5




//BUTTON STATES
boolean UP, DOWN, LEFT, RIGHT, A, B;
 

//dev, will display on the strip whatever buttons are currently being pressed. 
void ShowButtons()
{
  if(LEFT   == true) {leds[0] = CRGB::SeaGreen;}      else {leds[0] = CRGB::Black;}
  if(RIGHT  == true) {leds[1] = CRGB::Aquamarine;}    else {leds[1] = CRGB::Black;}
  if(UP     == true) {leds[2] = CRGB::LightSkyBlue;}  else {leds[2] = CRGB::Black;}
  if(DOWN   == true) {leds[3] = CRGB::DarkRed;}       else {leds[3] = CRGB::Black;}
  if(A      == true) {leds[4] = CRGB::White;}         else {leds[4] = CRGB::Black;}
  if(B      == true)  {leds[5] = CRGB::Red;}          else {leds[5] = CRGB::Black;}
  
  FastLED.show();
}

void ReadButtons()
{

  if(analogRead(UP_BUTTON     ) > 500  ) {UP     = true; } else {UP    = false;}
  if(analogRead(DOWN_BUTTON   ) > 500  ) {DOWN   = true; } else {DOWN  = false;}
  if(analogRead(LEFT_BUTTON   ) > 500  ) {LEFT   = true; } else {LEFT  = false;}
  if(analogRead(RIGHT_BUTTON  ) > 500  ) {RIGHT  = true; } else {RIGHT = false;}
  if(analogRead(A_BUTTON      ) > 500  ) {A      = true; } else {A     = false;}
  if(analogRead(B_BUTTON      ) > 500  ) {B      = true; } else {B     = false;}

}


void WaitForButtonPress()
{
  //wait for button press to start
  while( UP == false && DOWN == false && LEFT == false && RIGHT == false && A == false && B == false)
  {
    ReadButtons();
  }
}


void PrintButtonStates()
{
  Serial.print("LEFT=");
  Serial.print(LEFT);
  Serial.print(" ");
  Serial.print("RIGHT=");
  Serial.print(RIGHT);
  Serial.print(" ");
  Serial.print("UP=");
  Serial.print(UP);
  Serial.print(" ");
  Serial.print("DOWN=");
  Serial.print(DOWN);
  Serial.print(" ");
  Serial.print("A=");
  Serial.print(A);
  Serial.print(" ");
  Serial.print("B=");
  Serial.print(B);
  Serial.println(" ");
}

void PrintAnalogPorts()
{
  Serial.print("A0=");
  Serial.print(analogRead(A0));
  Serial.print(" ");
  Serial.print("A1=");
  Serial.print(analogRead(A1));
  Serial.print(" ");
  Serial.print("A2=");
  Serial.print(analogRead(A2));
  Serial.print(" ");
  Serial.print("A3=");
  Serial.print(analogRead(A3));
  Serial.print(" ");
  Serial.print("A4=");
  Serial.print(analogRead(A4));
  Serial.print(" ");
  Serial.print("A5=");
  Serial.print(analogRead(A5));
  Serial.print(" ");
  Serial.print("A6=");
  Serial.print(analogRead(A6));
  Serial.print(" ");
  Serial.print("A7=");
  Serial.println(analogRead(A7));
}
