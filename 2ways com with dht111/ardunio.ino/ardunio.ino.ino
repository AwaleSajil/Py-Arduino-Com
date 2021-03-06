#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN            2         // Pin which is connected to the DHT sensor.

#define DHTTYPE           DHT11 


DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  dht.begin();
  sensor_t sensor;
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;

}

void loop() {
  // put your main code here, to run repeatedly:
  // Delay between measurements.
  delay(delayMS);
  // Get temperature event and print its value.
  sensors_event_t event;  
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println("Error reading temperature!");
  }
  else {
    Serial.print("Temperature: ");
    Serial.print(event.temperature);
    Serial.println(" *C");
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println("Error reading humidity!");
  }
  else {
    Serial.print("Humidity: ");
    Serial.print(event.relative_humidity);
    Serial.println("%");
  }
}
