/*
  Hacked off input event

*/

/*
   Neopixel Stuff

*/
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?

#define PIN        5


// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      120


Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.


/*
   Regular Stuff
*/
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
int StringNum = 0;

int MINLED = 0;
int MAXLED = NUMPIXELS - 1;

int currentpixel = 0;

/*
 * Lobe Mapping: We are mapping the lobes based on some research. Obviously this will be an esoteric (both figuratively since we are not experts, 
 * and literally since the insied of the brain is not mapped with our sensors), but  this tool can be easily reconfigured at any time to improve the sharing of its design concepts according to the latest research
 * 
 * 
 * Key:
 * f= front side
 * i = inside
 * v= visual
 * s = speech
 * t = thinking
 * m = moving
 * c = coordination (around cerebellum)
 * a = talking and auditory processing
 */

char* LLobe[NUMPIXELS] = {"fv_0", "fv_1", "fv_2", "fv_3", "fv_4", "fv_5", "fc_6",
                          "ic_7", "i_8", "i_9", "i_10", "i_11", "i_12", "i_13",
                          
                          "f_14", "f_15", "f_16", "fv_17", "fv_18", "fv_19", "f_20", "fc_21", "fc_22", "fc_23", "fc_24",
                          "ic_25", "i_26", "i_27", "i_28", "i_29", "i_30", "i_31", 
                          
                          "f_32", "f_33", "f_34", "f_35", "f_36", "f_37", "fs_38", "fs_39", "f_40", "fc_41", "fc_42", "fc_43", "fc_44",
                          "fc_45", "fc_46",
                          "i_47", "i_48", "i_49", "i_50", "i_51", "i_52", 
                          
                          "f_53", "f_54", "f_55", "f_56", "f_57", "f_58", "f_59", "f_60", "f_61", "f_62", "f_63", "fa_64", "fa_65",
                          "fa_66", "f_67", 
                          
                          "i_68", "i_69", "i_70", "i_71", "i_72", "i_73", "i_74", "i_75", "i_76", 
                          
                         "fm_77", "fm_78", "fm_79", "fm_80", "fm_81", "fm_82", "fm_83", "fs_84", "fs_85", "fa_86", "fa_87", "fa_88",
                          "fa_89", "fa_90",
                          "i_91", "i_92", "i_93", "i_94", "i_95", "i_96", "i_97", 
                          
                          "ft_98", "ft_99", "ft_100", "ft_101", "ft_102", "ft_103", "ft_104", "ft_105", "ft_106",
                          "ft_107",
                          
                          "i_108", "i_109", 
                          
                          "ft_110", "ft_111", "ft_112", "ft_113", "ft_114", "ft_115", "ft_116", "ft_117", "ft_118", "ft_119"
                         };


void setup() {


  //Neopixel setup
  strip.begin();
  strip.show(); // Initialize all pixels to 'off';


  pixAllSameColor(0, 0, 150);
  delay(100);
  pixAllSameColor(0, 150, 150);
  delay(100);
  pixAllSameColor(150, 0, 150);
  delay(100);
  pixAllBlack();

  //Neopixel setup
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);

}

void loop() {
  // print the string when a newline arrives:


  if (stringComplete) {
    StringHandler();
  }


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

void StringHandler() {
  Serial.print ("Input was: ");
  Serial.println(inputString);
  StringNum = inputString.toInt();

  //Next
  if (inputString == "+" || inputString == "") {
    Serial.print("Move to Next LED: ");

    currentpixel++;

    Serial.println(currentpixel);
    pixAllBlack();
    strip.setPixelColor(currentpixel, strip.Color(0, 0, 120));
      strip.show(); // This sends the updated pixel color to the hardware.
  }

  //Previous
  else if (inputString == "-") {
    Serial.print("Move to Previous LED: ");



    currentpixel--;
    Serial.println(currentpixel);
    pixAllBlack();
    strip.setPixelColor(currentpixel, strip.Color(0, 120, 0));
      strip.show(); // This sends the updated pixel color to the hardware.
  }
  else if (inputString == "b") {
    //all black
    pixAllBlack();
  }

  else if (inputString == "i") {
    //all inside
    pixOnlyInside();
  }
  else if (inputString == "o") {
    //all inside
    pixOnlyOutside();
  }
  else if (inputString == "allblue") {
    //all
    pixAllSameColor(0, 0, 150);
  }

  else if (inputString == "allgreen") {
    //all
    pixAllSameColor(0, 150, 0);
  }
  else if (inputString == "allred") {
    //all
    pixAllSameColor(150, 0, 0);
  }
  else if (inputString == "allpurple") {
    //all
    pixAllSameColor(150, 0, 150);
  }
  else if (inputString == "f") {
    //run freakout
    theaterChaseRainbow(5);

  }


  //Check numbers and gotoLED
  else {
    Serial.print("Inputted Num was: ");
    Serial.print(StringNum);

    if (StringNum > 0 && StringNum < MAXLED)
    {
      Serial.print("  Target LED turn on : ");
      Serial.println(StringNum);
      currentpixel = StringNum;

      pixAllBlack();
      strip.setPixelColor(currentpixel, strip.Color(0, 120, 0));
      strip.show(); // This sends the updated pixel color to the hardware.

    }

  }

//  strip.show(); // This sends the updated pixel color to the hardware.
//  strip2.show(); // This sends the updated pixel color to the hardware.

  //End loop
  //Clear the string
  inputString = "";

  stringComplete = false;
}







/*
  SerialEvent occurs whenever a new data comes in the
  hardware serial RX.  This routine is run between each
  time loop() runs, so using delay inside loop can delay
  response.  Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:

    if (inChar == '\n') {
      stringComplete = true;
    }
    else {
      // add it to the inputString:
      inputString += inChar;
    }

  }
}


