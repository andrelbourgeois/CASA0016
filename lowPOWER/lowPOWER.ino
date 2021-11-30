#include <LowPower.h>
#include <TheThingsNetwork.h>
#include <DHT.h>
#include <math.h>

// Set your AppEUI and AppKey
const char *appEui = "70B3D57ED001D6E5";
const char *appKey = "81C62DE7F88226826D094419A0B24ADE";

#define debug false
#define debugSerial Serial
#define loraSerial Serial1

// Replace REPLACE_ME with TTN_FP_EU868 or TTN_FP_US915
#define freqPlan TTN_FP_EU868

#define DHTPIN 2  //Digital Pin 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

//Calls the constructor for the TheThingsNetwork class from the TheThingsNetwork library
TheThingsNetwork ttn(loraSerial, debugSerial, freqPlan);

void setup(){
  debugSerial.begin(9600);
  loraSerial.begin(57600);

  // Wait a maximum of 10s for Serial Monitor
  while (!debugSerial && millis() < 10000)
    ;

  //Initialise the DHT sensor
  dht.begin();

  ttn.showStatus();
  debugSerial.println("-- JOIN");
  ttn.join(appEui, appKey);
}

void loop(){
  if(debug)
    debugSerial.println("-- LOOP");

  uint16_t humidity = 100*dht.readHumidity(false);

  // false: Celsius (default)
  // true: Farenheit
  uint16_t temperature = 100*dht.readTemperature(false);

  // Split both words (16 bits) into 2 bytes of 8
  byte payload[6];
  payload[0] = highByte(temperature);
  payload[1] = lowByte(temperature);
  payload[2] = highByte(humidity);
  payload[3] = lowByte(humidity);

  if(debug){
    debugSerial.print("Temperature: ");
    debugSerial.println(temperature);
    debugSerial.print("Humidity: ");
    debugSerial.println(humidity);
  }

  ttn.sendBytes(payload, sizeof(payload));
  prepareToSleep();
  ttn.sleep(85000);
  for(int i = 0; i < 10; i++){
    //sleep for  80 seconds
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  }

  wakeUp();
}

void wakeUp(){
  ttn.wake();
  loraSerial.begin(57600);

  if(debug)
    debugSerial.begin(9600);

  if(debug)
    debugSerial.println("-- STATUS");

  ttn.showStatus();
}


void prepareToSleep(){
  loraSerial.end();
  if(debug)
    debugSerial.end();
}
