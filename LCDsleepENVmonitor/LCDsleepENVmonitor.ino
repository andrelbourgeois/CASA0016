#include <LiquidCrystal.h>

#define lightPin A2 //set analog pin to recieve light level value
#define tempPin A0 // set analog pin to recieve temperature value#define Vcc 5.0 // board voltage

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // declare pins LCD will use

int tempInput; // declare temperature input integer variable
int lightInput; // declare light input integer variable
float temp; // declare temperature as a float variable
float light; // declare light level as a float variable
float voltage; // declare a float variable to store voltage
float Vcc = 5; // board voltage


void setup() {
  Serial.begin(9600); // start serial connection

  lcd.begin(16, 2); // start LCD screen
  lcd.print("How did");
  lcd.setCursor(0,1);
  lcd.print("you sleep?");
  delay(5000);
}

void loop() {

  tempInput = analogRead(tempPin);
  voltage = tempInput * Vcc; // multiply by board voltage
  voltage /= 1024; // divide by 1024 to get volts
  Serial.print(voltage);
  Serial.println(" volts");
  // print voltage in serial monitor for debugging
  temp = (voltage - 0.5) * 100; // subtract offset and multiply by
  // 100 to convert voltage to degrees celsius
  Serial.print(temp);
  Serial.println(" degrees celsius");
  // print voltage in serial monitor for debugging

  lcd.clear(); // clears the LCD screen
  lcd.print("Temperature ");
  lcd.setCursor(0,1);
  lcd.print(temp);
  lcd.print("C");
  delay(2000);


  lightInput = analogRead(lightPin);
  // lower light level = less resistance & higher value
  light = map(round(lightInput), 0, 1023, 1000, 0); // map the analog value to lux
  Serial.print(lightInput);
  Serial.println(" lightInput");
  Serial.print(light);
  Serial.println(" lux");

  lcd.clear();
  lcd.print("Ambient Light ");
  lcd.setCursor(0,1);
  lcd.print(light);
  lcd.print("Lx");
  delay(2000);
 }
