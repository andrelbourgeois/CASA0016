#define analogPin A0
#define Vcc 5.0 //Board voltage
#define ledPin 3

void setup() {
//put your setup code here, to run once
Serial.begin(9600);
}

void loop() {
//put your main code here, to run repeatedly
float voltage = Vcc*analogRead(analogPin)/1024;
Serial.print("Voltage is: ");
Serial.println(voltage);
int dutyCycle = voltage*50; //or this >> analogRead(analogPin);
analogWrite(ledPin, dutyCycle);
delay(10);
}
