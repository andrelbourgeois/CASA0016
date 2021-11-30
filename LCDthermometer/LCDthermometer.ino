#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 7 // set the digital pin for the DHT sensor as 7
#define DHTTYPE DHT22 // set the sensor type
#define DELAYVAL 2000 // define a delay (defining here makes it easier to make changes in larger code files)

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // declare pins LCD will use

float temperature; // declare temperature as a float variable

DHT dht(DHTPIN, DHTTYPE); //initialize the DHT sensor

void setup() {
  Serial.begin(9600); //start serial connection

  pinMode(DHTPIN, INPUT); //set the DHTPIN to receieve sensor information
  dht.begin(); // start the DHT sensor

  lcd.begin(16, 2); // start LED strip
  lcd.print("Here is the");
  lcd.setCursor(0,1);
  lcd.print("temperature!");
}

void loop() {

  lcd.clear(); // clears the LCD screen
  temperature = dht.readTemperature(); // gets the temperature value
  delayMicroseconds(2);

  lcd.print("Temperature ");
  lcd.setCursor(0,1);
  lcd.print(temperature);
  lcd.print("C");

  Serial.print("Temperature: ");
  Serial.println(temperature);

   delay(DELAYVAL);
 }
