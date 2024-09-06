// Define the pin where the LED is connected
const int ledRedPin = 3; // You can change this to any other digital pin if needed
const int ledGreenPin = 4;
// Define the delay times (in milliseconds)
const unsigned long onTime = 1000;  // LED on for 1 second
const unsigned long offTime = 1000; // LED off for 1 second

void setup() {
  // Set the LED pin as an OUTPUT
  pinMode(ledGreenPin, OUTPUT);
  pinMode(ledRedPin, OUTPUT);
}

void loop() {
  // Turn the LED on
  digitalWrite(ledGreenPin, HIGH);
  delay(15);
  digitalWrite(ledRedPin, HIGH);
  delay(onTime); // Wait for the specified onTime
  
  // Turn the LED off
  digitalWrite(ledGreenPin, LOW);
  delay(15);
  digitalWrite(ledRedPin, LOW);
  delay(offTime); // Wait for the specified offTime
}
