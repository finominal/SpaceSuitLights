
void RightArmTest()
{
  for(int i = 0; i>sizeof(armRight)/sizeof(int); i++)//might need  to divide by size of data type
  {
    leds[armRight[i]] = CRGB::Green;
  }
  FastLED.show();
}

void LeftArmTest()
{
  for(int i = 0; i>sizeof(armLeft)/sizeof(int); i++)
  {
    leds[armRight[i]] = CRGB::Green;
  }
  FastLED.show();
}
