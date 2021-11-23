/*

*/

#include <Servo.h>
#define tempPin A0 // declares analog pin A0 as the pin we will read
// temperate from

Servo myservo; // create servo object to control a servo

void setup() {
  Serial.begin(115200); //begin serial connetection, declare baud rate
  myservo.attach(9); // attaches the servo on pin 9 to the servo object
}

void loop() {
  float tempVolts = 5.0*analogRead(tempPin)/1024;
  float tempKelvin = tempVolts/0.01;
  float tempCelsius = tempKelvin - 273;
  int angle = map(round(tempCelsius), 0, 180, 15, 25);

  Serial.println();
  Serial.print("Temperature ");
  Serial.println(tempCelsius);

  for (int pos = 0; pos <= 180; pos++) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(angle); //tell servo to go to position in varialbe "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (int pos = 180; pos >= 0; pos--) { // goes from 180 degrees to 0 degrees
    myservo.write(angle); // tel servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
}
