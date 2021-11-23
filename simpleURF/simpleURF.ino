/*
 *  Based on:
 *  https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/
 *
 */

#define trigPin 2
#define echoPin 3

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
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

  delay(2000);
}
