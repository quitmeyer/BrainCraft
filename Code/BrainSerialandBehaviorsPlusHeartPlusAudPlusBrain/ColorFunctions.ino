


//Mapped Out areas of the brain + add a bit randomness to their borders
void areasoftheBrainAnimated() {
  for (int i = 0; i < NUMPIXELS; i++) {

    char* type = LLobe[i];


//External Brain
    if (type[0] == 'f') {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
     /// strip.setPixelColor(i, strip.Color(heartPWR, heartPWR, heartPWR));
     strip.setPixelColor(i, strip.Color(0, 0, 0));
    }
    
    //Internal Brain
    else {
      strip.setPixelColor(i, strip.Color(0, 100+random(30), 100+random(30)));

    }
   if (type[1] == 'v') {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      strip.setPixelColor(i+random(2), strip.Color(0, 150+random(40), random(10)));
    }
    
    //speech
 if (type[1] == 's') {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      strip.setPixelColor(i, strip.Color(10, eegReading/5, 0));
    }
    
//auditory
 if (type[1] == 'a') {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      strip.setPixelColor(i, strip.Color(120, eegPWR+eegReading/5, 200));
    }


//thinking
 if (type[1] == 't') {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      strip.setPixelColor(i+random(2), strip.Color(0, random(10), eegPWR));
    }
    
//moving
 if (type[1] == 'm') {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      strip.setPixelColor(i+random(1), strip.Color(heartPWR, random(20), 20));
    }

//coordination
 if (type[1] == 'c') {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      strip.setPixelColor(i, strip.Color(0, 200, 200));
    }

    


  }
  //Finally turn on the whole strip with the values
    strip.show(); // This sends the updated pixel color to the hardware.
}

//Mapped Out areas of the brain
void areasoftheBrain() {
  for (int i = 0; i < NUMPIXELS; i++) {

    char* type = LLobe[i];


//External Brain
    if (type[0] == 'f') {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      strip.setPixelColor(i, strip.Color(10, 10, 10));
    }
    
    //Internal Brain
    else {
      strip.setPixelColor(i, strip.Color(0, 100, 100));

    }
    /*
     * Getting into the subtypes
     */

     //Visual
   if (type[1] == 'v') {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      strip.setPixelColor(i, strip.Color(0, 200, 0));
    }

    //speech
 if (type[1] == 's') {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      strip.setPixelColor(i, strip.Color(200, 200, 0));
    }
    
//auditory
 if (type[1] == 'a') {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      strip.setPixelColor(i, strip.Color(200, 0, 200));
    }


//thinking
 if (type[1] == 't') {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      strip.setPixelColor(i, strip.Color(0, 00, 220));
    }
    
//moving
 if (type[1] == 'm') {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      strip.setPixelColor(i, strip.Color(0, 00, 200));
    }

//coordination
 if (type[1] == 'c') {
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      strip.setPixelColor(i, strip.Color(0, 200, 200));
    }

    

  }
  //Finally turn on the whole strip with the values
    strip.show(); // This sends the updated pixel color to the hardware.

}

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

