class Timer {
public:
  // Constructor
  Timer() : startTime(0), duration(0), active(false) {}

  // Sets the timer with the specified duration (in hours)
  void setTimer(float durationHours) {
    startTime = millis(); // Record the start time
    duration = durationHours * 3600000; // Convert hours to milliseconds
    active = true; // Mark the timer as active
  }

  // Cancels the timer
  void cancelTimer() {
    active = false; // Mark the timer as inactive
  }

  // Returns the remaining time in hours
  float timeLeft() {
    if (active) {
      unsigned long elapsed = millis() - startTime;
      if (elapsed >= duration) {
        active = false; // Timer has expired
        return 0.0; // No time left
      } else {
        return (duration - elapsed) / 3600000.0; // Convert milliseconds to hours
      }
    }
    return 0.0; // Timer is not active
  }

  // Returns true if the timer is active, false otherwise
  bool isActive() {
    return active;
  }

private:
  unsigned long startTime; // When the timer started
  unsigned long duration;  // Duration of the timer in milliseconds
  bool active;             // Whether the timer is active or not
};

// Create a Timer object
Timer myTimer;
#include "DHT.h"
#define DHTPIN 2      // Pin where the DHT22 sensor is connected
#define DHTTYPE DHT22 // Type of the sensor, DHT22 for the DHT22 sensor
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
DHT dht(DHTPIN, DHTTYPE);
int pos = 0;    // variable to store the servo position
void setup() {
  Serial.begin(9600);
  dht.begin();
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(pos);
  // Set a timer for 1 hour
  myTimer.setTimer(.01); // 1 hour
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(true);  // Read temperature in Fahrenheit
  pos=180;
  // Check if the timer is still active
  if (myTimer.isActive()) {
    if (!isnan(humidity) && !isnan(temperature)) {
      Serial.print("Humidity: ");
      Serial.print(humidity);
      Serial.print("%, Temperature: ");
      Serial.print(temperature);
      Serial.println("°F");
    } else {
      Serial.println("Failed to read from DHT sensor!");
    }
    myservo.write(pos);
    
    // Print the remaining time every minute
    float remainingHours = myTimer.timeLeft();
    if (remainingHours > 0) {
      Serial.print("Time left: ");
      Serial.print(remainingHours, 2); // Print with 2 decimal places
      Serial.println(" hours");
    } else {
      Serial.println("Timer has expired.");
    }
  } else {
    myservo.write(0);
    Serial.println("Timer is not active.");
  }
/*
  // Simulate user interaction (e.g., cancel the timer after 10 minutes)
  static unsigned long previousMillis = 0;
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= 600000) { // 10 minutes = 600000 milliseconds
    previousMillis = currentMillis;
    myTimer.cancelTimer(); // Cancel the timer after 10 minutes
  }
*/
  //delay(60000); // Wait for 1 minute before the next loop iteration
}
