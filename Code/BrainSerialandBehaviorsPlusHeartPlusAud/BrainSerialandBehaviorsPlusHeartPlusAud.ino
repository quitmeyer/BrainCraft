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

//mapping the left lobe
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

//mapping the right lobe
char* RLobe[NUMPIXELS] = {"fv_0", "fv_1", "fv_2", "fv_3", "fv_4", "fv_5", "fc_6",
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





//Simulated Senses - From recordings and for demo purposes

/*
 * Heart Beat
 */

 int heartPWR = 0;
 int heartPWRreading = 500;
long heartBeatArray[] = {
    50, 100, 15, 1200};
int hbeatIndex = 1;    // this initialization is not important  
long prevMillis;

int LEDpin = 13;

/*
 * Breathing
 */



 // Global Fade Value
// but be bigger than byte and signed, for rollover
int breathPWR = 0;

const byte breathLED = 13;
 
 
// define directions for LED fade
#define UP 0
#define DOWN 1
 
// constants for min and max PWM
const int minPWM = 0;
const int maxPWM = 255;
 
// State Variable for Fade Direction
byte fadeDirection = UP;
 

 
// How smooth to fade?
byte fadeIncrement = 5;
 
// millis() timing Variable, just for fading
unsigned long previousFadeMillis;
 
// How fast to increment?
int fadeInterval = 30;
 

 

 

 /*
  * Brainwaves
  */

int eegPin = A1;

int eegPWR = 0;


  //Measured Senses

  //heart rate
  int heartPin=A0;


void setup() {


  //Neopixel setup
  strip.begin();
  strip.show(); // Initialize all pixels to 'off';


//startupRoutine
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


    pinMode(LEDpin, OUTPUT);

}

void loop() {

//Global Timer (though currently just Breath)
  unsigned long currentMillis = millis();
    


  
  if (stringComplete) {
    StringHandler();
  }

  //Present Mode
  
    breathFade(currentMillis);
    heartBeat();
    eegBASIC();
//    heartBeatS(.8);     

paintBrain();

}


