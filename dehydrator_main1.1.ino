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
Servo spray;  //servo for spray bottle
DHT dht(DHTPIN, DHTTYPE);
// Define the pin where the buzzer is connected
const int buzzerPin = 5; // Change this if your buzzer is connected to a different pin
const int ledRedPin = 3; 
const int ledGreenPin = 4;
// Define the delay times (in milliseconds)
const unsigned long beepDuration = 1000; // Duration of the beep in milliseconds
const unsigned long pauseDuration = 1000; // Duration of the pause between beeps
float timer = 5.00;
int pos = 0;    // variable to store the servo position
//bool spray = false;
/*
 * 
 * 
 * 
 * 
 * 
 * functions
 */


void buzzerSound()
{
      // Turn the buzzer on
      digitalWrite(buzzerPin, HIGH);
      delay(beepDuration); // Wait for the duration of the beep
      
      // Turn the buzzer off
      digitalWrite(buzzerPin, LOW);
      delay(pauseDuration); // Wait for the duration of the pause



  
}
void playSong()
{
    
  #define NOTE_B0  31
  #define NOTE_C1  33
  #define NOTE_CS1 35
  #define NOTE_D1  37
  #define NOTE_DS1 39
  #define NOTE_E1  41
  #define NOTE_F1  44
  #define NOTE_FS1 46
  #define NOTE_G1  49
  #define NOTE_GS1 52
  #define NOTE_A1  55
  #define NOTE_AS1 58
  #define NOTE_B1  62
  #define NOTE_C2  65
  #define NOTE_CS2 69
  #define NOTE_D2  73
  #define NOTE_DS2 78
  #define NOTE_E2  82
  #define NOTE_F2  87
  #define NOTE_FS2 93
  #define NOTE_G2  98
  #define NOTE_GS2 104
  #define NOTE_A2  110
  #define NOTE_AS2 117
  #define NOTE_B2  123
  #define NOTE_C3  131
  #define NOTE_CS3 139
  #define NOTE_D3  147
  #define NOTE_DS3 156
  #define NOTE_E3  165
  #define NOTE_F3  175
  #define NOTE_FS3 185
  #define NOTE_G3  196
  #define NOTE_GS3 208
  #define NOTE_A3  220
  #define NOTE_AS3 233
  #define NOTE_B3  247
  #define NOTE_C4  262
  #define NOTE_CS4 277
  #define NOTE_D4  294
  #define NOTE_DS4 311
  #define NOTE_E4  330
  #define NOTE_F4  349
  #define NOTE_FS4 370
  #define NOTE_G4  392
  #define NOTE_GS4 415
  #define NOTE_A4  440
  #define NOTE_AS4 466
  #define NOTE_B4  494
  #define NOTE_C5  523
  #define NOTE_CS5 554
  #define NOTE_D5  587
  #define NOTE_DS5 622
  #define NOTE_E5  659
  #define NOTE_F5  698
  #define NOTE_FS5 740
  #define NOTE_G5  784
  #define NOTE_GS5 831
  #define NOTE_A5  880
  #define NOTE_AS5 932
  #define NOTE_B5  988
  #define NOTE_C6  1047
  #define NOTE_CS6 1109
  #define NOTE_D6  1175
  #define NOTE_DS6 1245
  #define NOTE_E6  1319
  #define NOTE_F6  1397
  #define NOTE_FS6 1480
  #define NOTE_G6  1568
  #define NOTE_GS6 1661
  #define NOTE_A6  1760
  #define NOTE_AS6 1865
  #define NOTE_B6  1976
  #define NOTE_C7  2093
  #define NOTE_CS7 2217
  #define NOTE_D7  2349
  #define NOTE_DS7 2489
  #define NOTE_E7  2637
  #define NOTE_F7  2794
  #define NOTE_FS7 2960
  #define NOTE_G7  3136
  #define NOTE_GS7 3322
  #define NOTE_A7  3520
  #define NOTE_AS7 3729
  #define NOTE_B7  3951
  #define NOTE_C8  4186
  #define NOTE_CS8 4435
  #define NOTE_D8  4699
  #define NOTE_DS8 4978
  #define REST 0
  
  // change this to make the song slower or faster
  int tempo=114; 
  
  // change this to whichever pin you want to use
  int buzzer = 5;
  
  // notes of the moledy followed by the duration.
  // a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
  // !!negative numbers are used to represent dotted notes,
  // so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
  int melody[] = {
  
    
    NOTE_E4,4,  NOTE_E4,4,  NOTE_F4,4,  NOTE_G4,4,//1
    NOTE_G4,4,  NOTE_F4,4,  NOTE_E4,4,  NOTE_D4,4,
    NOTE_C4,4,  NOTE_C4,4,  NOTE_D4,4,  NOTE_E4,4,
    NOTE_E4,-4, NOTE_D4,8,  NOTE_D4,2,
  
    NOTE_E4,4,  NOTE_E4,4,  NOTE_F4,4,  NOTE_G4,4,//4
    NOTE_G4,4,  NOTE_F4,4,  NOTE_E4,4,  NOTE_D4,4,
    NOTE_C4,4,  NOTE_C4,4,  NOTE_D4,4,  NOTE_E4,4,
    NOTE_D4,-4,  NOTE_C4,8,  NOTE_C4,2,
  
    NOTE_D4,4,  NOTE_D4,4,  NOTE_E4,4,  NOTE_C4,4,//8
    NOTE_D4,4,  NOTE_E4,8,  NOTE_F4,8,  NOTE_E4,4, NOTE_C4,4,
    NOTE_D4,4,  NOTE_E4,8,  NOTE_F4,8,  NOTE_E4,4, NOTE_D4,4,
    NOTE_C4,4,  NOTE_D4,4,  NOTE_G3,2,
  
    NOTE_E4,4,  NOTE_E4,4,  NOTE_F4,4,  NOTE_G4,4,//12
    NOTE_G4,4,  NOTE_F4,4,  NOTE_E4,4,  NOTE_D4,4,
    NOTE_C4,4,  NOTE_C4,4,  NOTE_D4,4,  NOTE_E4,4,
    NOTE_D4,-4,  NOTE_C4,8,  NOTE_C4,2
    
  };
  
  // sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
  // there are two values per note (pitch and duration), so for each note there are four bytes
  int notes=sizeof(melody)/sizeof(melody[0])/2; 
  
  // this calculates the duration of a whole note in ms (60s/tempo)*4 beats
  int wholenote = (60000 * 4) / tempo;
  
  int divider = 0, noteDuration = 0;
   // iterate over the notes of the melody. 
    // Remember, the array is twice the number of notes (notes + durations)
    for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
  
      // calculates the duration of each note
      divider = melody[thisNote + 1];
      if (divider > 0) {
        // regular note, just proceed
        noteDuration = (wholenote) / divider;
      } else if (divider < 0) {
        // dotted notes are represented with negative durations!!
        noteDuration = (wholenote) / abs(divider);
        noteDuration *= 1.5; // increases the duration in half for dotted notes
      }
  
      // we only play the note for 90% of the duration, leaving 10% as a pause
      tone(buzzer, melody[thisNote], noteDuration*0.9);
  
      // Wait for the specief duration before playing the next note.
      delay(noteDuration);
      
      // stop the waveform generation before the next note.
      noTone(buzzer);
    }
    digitalWrite(buzzerPin, LOW);
}

void lightMode(int color=0)
{

    if ( color == 0)
    {
        digitalWrite(ledGreenPin, LOW);
        delay(15);
        digitalWrite(ledRedPin, HIGH);
        delay(15);
    }
    else if( color == 2)
    {
        digitalWrite(ledGreenPin, LOW);
        delay(15);
        digitalWrite(ledRedPin, HIGH);
        delay(15);
        digitalWrite(ledGreenPin, HIGH);
        delay(15);
        digitalWrite(ledRedPin, LOW);
        delay(15);
        digitalWrite(ledGreenPin, LOW);
        delay(15);
        digitalWrite(ledRedPin, HIGH);
        delay(15);

    }
    else
    {
      
        digitalWrite(ledGreenPin, HIGH);
        delay(15);
        digitalWrite(ledRedPin, LOW);
        delay(15);
    }

  
}





/*
 * 
 * 
 * 
 * Main
 */
void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(buzzerPin, OUTPUT);
  myservo.attach(11);  // attaches the servo on pin 9 to the servo object
  spray.attach(13);
  spray.write(0);
  myservo.write(pos);
  pinMode(ledGreenPin, OUTPUT);
  pinMode(ledRedPin, OUTPUT);
  // Set a timer for 1 hour
  myTimer.setTimer(timer); // 1 hour
  lightMode(2);
  buzzerSound();
  
}
void sprayBottle()    //function for spraying in dehydrator
{
  spray.write(180);
  delay(15);
  spray.write(0);
  delay(15);
  Serial.println("Spraying Bottle");

  
}
int timeBetweenCycles=1;
void loop() {
  float humidity = dht.readHumidity();            // Read humidity percent from dht22 sensor
  float temperature = dht.readTemperature(true);  // Read temperature in Fahrenheit from dht22 sensor

  //temperature = 170;// test
  //temperature = 160;//test
  // Check if the timer is still active+
  if (myTimer.timeLeft()>(timer-0.009))   //warm up time
  {
    pos=180;     // initial dimmer switch set to max power
    
  }
  if (myTimer.isActive()) {
    lightMode(0);
    if (!isnan(humidity) && !isnan(temperature)) {
      Serial.print("Humidity: ");
      Serial.print(humidity);
      Serial.print("%, Temperature: ");
      Serial.print(temperature);
      Serial.println("°F");
    } else {
      Serial.println("Failed to read from DHT sensor!");
    }
    if (temperature<165 && pos<180 && timeBetweenCycles==50)  //ever fifty cycles change temp so not too sudden of a change
    {
      Serial.println("pos +1 ");
      pos+=1;
      Serial.print("Position:  ");
      Serial.println(pos);
      if(humidity<40)
      {
        sprayBottle();
      }
    }
    if (temperature>165 && pos<=180 && timeBetweenCycles==50)
    {
      Serial.println("pos -1 ");
      pos-=1;
      Serial.print("Position:  ");
      Serial.println(pos);
      if(humidity<40)
      {
        sprayBottle();
      }
    }
    if(timeBetweenCycles==50)
    {
      timeBetweenCycles=0;  //reset delay between temp checks and adjustments after 50 cycles
    }
    timeBetweenCycles+=1;
    myservo.write(pos);
    
    // Print the remaining time every minute
    float remainingHours = myTimer.timeLeft();
    if (remainingHours > 0) {
      Serial.print("Time left: ");
      Serial.print(remainingHours, 2); // Print with 2 decimal places
      Serial.println(" hours");
    } else {
      Serial.println("Timer has expired.");
      //buzzerSound();
      lightMode(1);
      delay(15);
      playSong();
    }
  } else {
      myservo.write(0);
      Serial.println("Timer is not active.");
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
/*
  // Simulate user interaction (e.g., cancel the timer after 10 minutes)
  static unsigned long previousMillis = 0;
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= 600000) { // 10 minutes = 600000 milliseconds
    previousMillis = currentMillis;
    myTimer.cancelTimer(); // Cancel the timer after 10 minutes
  }
*/
  //delay(30000); // Wait for 1 minute before the next loop iteration time between degree change
}
