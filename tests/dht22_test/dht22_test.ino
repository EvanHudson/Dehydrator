#include "DHT.h"

#define DHTPIN 2      // Pin where the DHT11 sensor is connected
#define DHTTYPE DHT11  // Type of the sensor, DHT11 for the DHT11 sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 Test");

  dht.begin();
}

void loop() {
  delay(2000);  // Wait for 2 seconds between readings

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(true);  // Read temperature in Fahrenheit

  // Check if readings are valid (not NaN)
  if (!isnan(humidity) && !isnan(temperature)) {
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print("%, Temperature: ");
    Serial.print(temperature);
    Serial.println("°F");
  } else {
    Serial.println("Failed to read from DHT sensor!");
  }
}