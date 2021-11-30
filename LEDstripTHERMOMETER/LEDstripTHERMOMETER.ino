#include <Adafruit_NeoPixel.h>
#include <DHT.h>

#define LEDPIN 6 // define the arduino pin that is sending data to the LED strip
#define NUMPIXELS 8 // set NUMPIXELS to the number of LED's on the light strip, this is a max value
#define DHTPIN 2 // set the digital pin for the DHT sensor as 2
#define DHTTYPE DHT22 // set the sensor type
#define DELAYVAL 500 // define a delay (defining here makes it easier to make changes in larger code files)

float temperature; // declare temperature as a float variable

DHT dht(DHTPIN, DHTTYPE); //initialize the DHT sensor
Adafruit_NeoPixel pixels(NUMPIXELS, LEDPIN); // sets the max number of LED's and pin to acquire data from

void setup() {
  Serial.begin(9600); //start serial connection
  pixels.begin(); // start LED strip

  pinMode(DHTPIN, INPUT); //set the DHTPIN to receieve sensor information
  dht.begin(); // start the DHT sensor

}

void loop() {

  pixels.clear(); // clears the LED strip (turns everything off)
  temperature = dht.readTemperature(); // gets the temperature value
  delayMicroseconds(2);

  Serial.print("Temperature: ");
  Serial.println(temperature);

  float lights = map(round(temperature), 0, 40, 0, 8);

  for(int i=1; i<=lights; i++) { // create a for loop to iterate through each LED
    pixels.setPixelColor(i, 30, 20, 20); // sets the LED colour
    // how to set LEDs different colours?
    // 1,2 Black???
    // 3,4 Blue
    // 5,6 Purple
    // 7,8 Red
    pixels.show(); // turns on each LED in sequence
   }
   delay(500);
 }
