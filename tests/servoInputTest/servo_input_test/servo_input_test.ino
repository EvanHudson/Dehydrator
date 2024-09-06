#include <Servo.h>  // Include the Servo library

// Create a Servo object
Servo myServo;

// Define the pin where the servo is connected
const int servoPin = 12;

// Initialize the servo and set the pin
void setup() {
  Serial.begin(9600);      // Start serial communication at 9600 baud
  myServo.attach(servoPin); // Attach the servo to the defined pin
  Serial.println("Enter a value between 0 and 180 to set the servo position:");
}

void loop() {
  // Check if data is available in the serial buffer
  if (Serial.available() > 0) {
    int angle = Serial.parseInt(); // Read the incoming value as an integer

    // Check if the angle is within the valid range
    if (angle >= 0 && angle <= 180) {
      myServo.write(angle); // Set the servo position to the received angle
      Serial.print("Servo position set to: ");
      Serial.println(angle);
    } else {
      Serial.println("Please enter a value between 0 and 180.");
    }
  }
}
