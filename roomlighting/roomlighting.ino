#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 50 
#define BRIGHTNESS 200

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 6
//#define CLOCK_PIN 13
#define LED_TYPE WS2812
#define COLOR_ORDER RGB

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
  Serial.begin(57600);
  Serial.println("resetting");
  LEDS.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(Typical8mmPixel); //Typical8mmPixel or TypicalPixelString 
  LEDS.setBrightness(BRIGHTNESS);
}

// List of patterns to cycle through.  Each is defined as a separate function below.
typedef void (*SimplePatternList[])();
SimplePatternList gPatterns = { breathEffect, rainbow, cylon};
uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current
uint8_t gHue = 0; // rotating "base color" used by many of the patterns

void loop() { 
  /* uint8_t hue = 0;
     cylon();
     delay(1000);
     rainbow();
     delay(1000);
  //hue++;
   */
  // Call the current pattern function once, updating the 'leds' array
  gPatterns[gCurrentPatternNumber]();
  //gPatterns[2]();
  Serial.print("Current Pattern number is: ");
  Serial.print(gCurrentPatternNumber);
  Serial.print("\t Current gHue is: ");
  Serial.println(gHue);

  // send the 'leds' array out to the actual LED strip
 // FastLED.show();  
  // insert a delay to keep the framerate modest
  FastLED.delay(1000/120); 

  // do some periodic updates
  EVERY_N_MILLISECONDS( 20 ) { gHue++; } // slowly cycle the "base color" through the rainbow
  EVERY_N_SECONDS( 20 ) { nextPattern(); } // change patterns periodically


}

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

void nextPattern(){
  // add one to the current pattern number, and wrap around at the end
  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE( gPatterns);
}

void fadeall(){
  for(int i = 0; i < NUM_LEDS; i++){
    leds[i].nscale8(250); 
  } 
}


void cylon(){
  LEDS.setBrightness(BRIGHTNESS/2);
  static uint8_t hue = 0;
  Serial.print(hue);
  // First slide the led in one direction
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue++, 255, BRIGHTNESS);
    FastLED.show(); 
    fadeall();
    delay(12);
  }
  //Serial.print("x");

  // Now go in the other direction.  
  for(int i = (NUM_LEDS)-1; i >= 0; i--) {
    leds[i] = CHSV(hue++, 255, BRIGHTNESS);
    FastLED.show();
    fadeall();
    delay(12);
  }   
  //Serial.println("x");
}

void rainbow() 
{
  // FastLED's built-in rainbow generator
  fill_rainbow( leds, NUM_LEDS, gHue, 7);
  LEDS.setBrightness(BRIGHTNESS/4);
  //FastLED.show();
}



void breathEffect(){
  LEDS.setBrightness(BRIGHTNESS/2);
  int a = millis();
  byte b = triwave8(a/15);
  byte breath = ease8InOutApprox(b);
  breath = map(breath, 0, 255, 10, BRIGHTNESS);
  fill_solid(leds, NUM_LEDS, CHSV(gHue, 255, breath));
  //Serial.println(breath);
  //adjust_gamma();
}


void adjust_gamma()
{
  for (uint16_t i = 0; i < NUM_LEDS; i++)
  {
    leds[i].r = dim8_video(leds[i].r);
    leds[i].g = dim8_video(leds[i].g);
    leds[i].b = dim8_video(leds[i].b);
  }
}

void blink(){
  fill_solid(leds, NUM_LEDS, CHSV(gHue, 255, BRIGHTNESS));
  FastLED.show();   
  delay(300);
  fill_solid(leds, NUM_LEDS, CHSV(gHue, 0, 50));
  FastLED.show();    
  delay(300);
}
