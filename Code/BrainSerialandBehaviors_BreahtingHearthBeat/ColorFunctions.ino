//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j = 0; j < 256; j++) {   // cycle all 256 colors in the wheel
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, Wheel( (i + j) % 255)); //turn every third pixel on

      }
      strip.show();

      delay(wait);

      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, 0);      //turn every third pixel off

      }
    }
  }
}

void pixAllBlack() {
  for (int i = 0; i < NUMPIXELS; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    strip.setPixelColor(i, strip.Color(0, 0, 0));


  }
  strip.show(); // This sends the updated pixel color to the hardware.

}


void pixOnlyInside() {
  for (int i = 0; i < NUMPIXELS; i++) {

    char* type = LLobe[i];

    if (type[0] == 'f') {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      strip.setPixelColor(i, strip.Color(0, 0, 0));

      //Serial.println("foundoutsideepix ");

    }
    else {
      strip.setPixelColor(i, strip.Color(0, 200, 200));

      // Serial.println("foundinsidepix ");
    }
    strip.show(); // This sends the updated pixel color to the hardware.

  }
}

void pixOnlyOutside() {
  for (int i = 0; i < NUMPIXELS; i++) {

    char* type = LLobe[i];

    if (type[0] == 'f') {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      strip.setPixelColor(i, strip.Color(0, 200, 200));

      //Serial.println("foundoutsideepix ");

    }
    else {
      strip.setPixelColor(i, strip.Color(200, 0, 0));

      //Serial.println("foundinsidepix ");
    }

  }
  strip.show(); // This sends the updated pixel color to the hardware.


}


void pixAllRed() {
  for (int i = 0; i < NUMPIXELS; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    strip.setPixelColor(i, strip.Color(10, 0, 0));

    strip.show(); // This sends the updated pixel color to the hardware.

  }
}
void pixAllSameColor(int r, int g, int b) {
  for (int i = 0; i < NUMPIXELS; i++) {

    strip.setPixelColor(i, strip.Color(r, g, b));
  }
  strip.show(); // This sends the updated pixel color to the hardware.
}
void pixAllSameColorWheel(uint32_t c) {
  for (int i = 0; i < NUMPIXELS; i++) {

    strip.setPixelColor(i, Wheel(c & 255));
    strip.show(); // This sends the updated pixel color to the hardware.
  }
}
// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

