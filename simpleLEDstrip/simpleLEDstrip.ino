#include <Adafruit_NeoPixel.h>

#define PIN 6 // define the arduino pin that is sending data to the LED strip
#define NUMPIXELS 8 // set NUMPIXELS to the number of LED's on the light strip, this is a max value
#define DELAYVAL 500 // define a delay (defining here makes it easier to make changes in larger code files)

Adafruit_NeoPixel pixels(NUMPIXELS, PIN); // sets the max number of LED's and pin to acquire data from

void setup() {
  pixels.begin(); // starts it
}

void loop() {
  pixels.clear(); // clears the LED strip (turns everything off)
  for(int i=0; i<NUMPIXELS; i++) { // create a for loop to iterate through each LED
    pixels.setPixelColor(i, 150, 20, 20); // sets the LED colour
    pixels.show(); // turns on each LED in sequence
    delay(DELAYVAL);
  }
}
