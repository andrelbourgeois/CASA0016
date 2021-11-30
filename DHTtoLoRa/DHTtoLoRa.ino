#include <TheThingsNetwork.h>
#include <DHT.h>
// Set your AppEUI and AppKey
const char *appEui = "70B3D57ED001D6E5";
const char *appKey = "81C62DE7F88226826D094419A0B24ADE";

#define debugSerial Serial
#define loraSerial Serial1
#define freqPlan TTN_FP_EU868
#define DHTPIN 2 // digital pin 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
TheThingsNetwork ttn(loraSerial, debugSerial, freqPlan);

void setup() {
  debugSerial.begin(9600);
  loraSerial.begin(57600);

  // wait a maximum of 10s for Serial Monitor
  while (!debugSerial && millis() < 10000);

  // initialize DHT sensor
  dht.begin();
  ttn.showStatus();
  debugSerial.println("-- JOIN");
  ttn.join(appEui, appKey);
}

void loop() {
  debugSerial.println("-- LOOP");

  uint16_t humidity = 100*dht.readHumidity(false);


  // false: Celsius (default)
  // true: Farenheit
  uint16_t temperature = 100*dht.readTemperature(false);

  // Split both words (16 bits) into 2 bytes of 8
  byte payload[4];
  payload[0] = highByte(temperature);
  payload[1] = lowByte(temperature);
  payload[2] = highByte(humidity);
  payload[3] = lowByte(humidity);
  ttn.sendBytes(payload, sizeof(payload));

  debugSerial.print("Temperature: ");
  debugSerial.println(temperature);
  debugSerial.print("Humidity: ");
  debugSerial.println(humidity);

  delay(30000); // delaying 30sec will make sure
  // the LoRa gateway doesn't block us
}
