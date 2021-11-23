#include <Adafruit_NeoPixel.h>

#define trigPin 2
#define echoPin 3

#define PIN 6 // define the arduino pin that is sending data to the LED strip
#define NUMPIXELS 8 // set NUMPIXELS to the number of LED's on the light strip, this is a max value
#define DELAYVAL 500 // define a delay (defining here makes it easier to make changes in larger code files)

Adafruit_NeoPixel pixels(NUMPIXELS, PIN); // sets the max number of LED's and pin to acquire data from

void setup() {
  Serial.begin(9600);

  pixels.begin(); // starts it

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}

void loop() {

  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  pixels.clear(); // clears the LED strip (turns everything off)
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(echoPin, HIGH);
  float distance = 34400*duration/2000000;

  Serial.print("Distance in cm: ");
  Serial.println(distance);

  int value = map(round(distance), 0, 30, 0, 8);

   for(int i=1; i<=value; i++) { // create a for loop to iterate through each LED
    pixels.setPixelColor(i, 150, 20, 20); // sets the LED colour
    pixels.show(); // turns on each LED in sequence
   }
   delay(500);

/*




  pixels.setPixelColor(value, 150, 20, 20); // sets the LED colour
  pixels.show();
  delay(DELAYVAL);

  }
 */

}
