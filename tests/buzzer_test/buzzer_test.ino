// Define the pin where the buzzer is connected
const int buzzerPin = 5; // Change this if your buzzer is connected to a different pin

// Define the delay times (in milliseconds)
const unsigned long beepDuration = 1000; // Duration of the beep in milliseconds
const unsigned long pauseDuration = 1000; // Duration of the pause between beeps

void setup() {
  // Set the buzzer pin as an OUTPUT
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Turn the buzzer on
  digitalWrite(buzzerPin, HIGH);
  delay(beepDuration); // Wait for the duration of the beep
  
  // Turn the buzzer off
  digitalWrite(buzzerPin, LOW);
  delay(pauseDuration); // Wait for the duration of the pause
}
