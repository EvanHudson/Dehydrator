//@author Evan Hudson
//version stub 1.0
// a simple program for controlling a rpi pico that both regulates the temp of a homemade dehumidifier and also introduces humidy for a certain amount of the total cooking time




#include <Servo.h>  // Library for servo
#include "DHT.h"    // Library for DHT22 (or DHT11) temperature and humidity sensor

#define DHTPIN 2
#define DHTTYPE DHT11    // Replace with DHT22 if you are using that sensor
DHT dht(DHTPIN, DHTTYPE);

Servo temp_Knob;  // Servo attached to potentiometer for light control of heated lamp
Servo water;      // Servo attached to spray water bottle for adding humidity

// Timer for how long it should take
int hours = 12;
unsigned long interval = 1UL * 60 * 60 * 1000*hours;  //hours in milliseconds 
unsigned long previousMillis = 0;
//set fraction of time it should maintain humidity for
double fractionTimeHumid=1/4;   //reccomended quarter of time

void setup() {
  Serial.begin(9600);
  dht.begin();  // Initialize the sensor
  temp_Knob.attach(9);
  water.attach(10);
}

// Functions

//set time period
int getTimeHumid()
{
  //interval=interval*hour;
  int humidity_time = interval*fractionTimeHumid;
  return humidity_time;
}


// Return current Fahrenheit temperature from sensor
float getTemperature() {
    float temperature = dht.readTemperature(true);
  if (!isnan(temperature)) {
    // Readings are valid, print them
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" Degrees Farenheight");
    return temperature;

  } else {
    // Failed to read from DHT sensor
    Serial.println("Failed to read temp from DHT sensor!");
      return -1;

  }
}

// Return current humidity % from sensor
float getHumidity() {
  float humidity=dht.readHumidity();
  if (!isnan(humidity)) {
    // Readings are valid, print them
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print("%");
    return humidity;

  } else {
    // Failed to read from DHT sensor
    Serial.println("Failed to read humidity from DHT sensor!");
      return -1;

  }
}

// Spray water bottle
void spray() {
  // Add your code to control the water spray here
}

//set temperature
void setTemperature( int temp)
{
  
}

//set humidity
void setHumidity()
{
  
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // It's time to perform the action
    Serial.println("Timer expired! Perform your action here.");

    // Example: Spray water every hour
    spray();

    // Reset the timer
    previousMillis = currentMillis;
  }

  // Your other code goes here

  // Add some delay if necessary to prevent the loop from running too frequently
  delay(100);
}
