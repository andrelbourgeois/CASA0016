#define redLED 2
#define yellowLED 3
#define greenLED 4
#define buttonPin 6

boolean buttonPressed = false;

void setup() {
  // set digital pin 2 to act as an output
   pinMode(redLED, OUTPUT);
   pinMode(yellowLED, OUTPUT);
   pinMode(greenLED, OUTPUT);
   pinMode(buttonPin, INPUT);
}

void loop() {
  boolean buttonPressed = false;
  long lastGreenTime = millis();
  while(buttonPressed == false && ( millis() - lastGreenTime < 10000) ){
    digitalWrite(greenLED, HIGH);   // turn the LED on (HIGH is the voltage level)
    buttonPressed = digitalRead(buttonPin);
  }
  
  digitalWrite(greenLED, LOW);    // turn the LED off by making the voltage LOW
  
  digitalWrite(yellowLED, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(2000);                    // wait for a second
  digitalWrite(yellowLED, LOW);   // turn the LED off by making the voltage LOW
  
  digitalWrite(redLED, HIGH);     // turn the LED on (HIGH is the voltage level)
  delay(5000);                    // wait for two seconds
  digitalWrite(yellowLED, HIGH);
  delay(2000);                    // wait for a second
  digitalWrite(redLED, LOW);      // turn the LED off by making the voltage LOW
  digitalWrite(yellowLED, LOW);
   
}
