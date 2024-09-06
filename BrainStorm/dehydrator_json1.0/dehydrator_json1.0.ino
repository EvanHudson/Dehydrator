//@author Evan Hudson
//version Json 1.0
// a simple program for controlling a rpi pico that both regulates the temp of a homemade dehydrator and also introduces humidy for a certain amount of the total cooking time




#include <Servo.h>  // Library for servo
#include "DHT.h"    // Library for DHT22 (or DHT11) temperature and humidity sensor

#define DHTPIN 2
#define DHTTYPE DHT22    // Replace with DHT22 if you are using that sensor
DHT dht(DHTPIN, DHTTYPE);

Servo temp_Knob;  // Servo attached to potentiometer for light control of heated lamp
Servo water;      // Servo attached to spray water bottle for adding humidity

int temp_Knob_Pos=360;
int water_Pos=0;

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

  //initialize servos water not spraying and temp all the way up;
  temp_Knob.write(temp_Knob_Pos);
  water.write(water_Pos);
}

// Functions

//set time period
int getTimeHumid( unsigned long interval )
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
    Serial.println(" Degrees Farenheight");
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

  water.write(0);
  delay(200);
  water.write(180);
  delay(200);
}

//set temperature
void setTemperature( int temp)
{
  
}

//set humidity
/*****     HANDLE IN MAIN LOOP
void setHumidity(int level)
{
  while(humidity>
  
  
}
*///////

void loop() {
  unsigned long currentMillis = millis();
  int preHeatTime= 360* 1000;                 //3 min  // move some of these variable intializations outside the loop so more efficient
  int decreaseRate= (interval- preHeatTime)/temp_Knob_Pos;
  float currentTemp=getTemperature();
  float currentHumid= getHumidity();
  
  int timeHumid= getTimeHumid(interval);
  
  if (currentMillis - previousMillis >= interval) {
    Serial.println("Timer expired! Power Off");

    temp_Knob.write(0);
    delay(200);

    // Reset the timer
    //previousMillis = currentMillis;
    }

    // Add some delay if necessary to prevent the loop from running too frequently
    delay(100);


    //handles initial heat
     if (currentTemp<160 && currentTemp!=-1 && currentMillis - previousMillis<preHeatTime)
     {
        if(temp_Knob_Pos!=360)
        {
        temp_Knob_Pos=360;
        temp_Knob.write(temp_Knob_Pos);
        }

      
     }
     //handles slow decrease of heat after that
     if((currentMillis - previousMillis)%decreaseRate==0)
     {
        temp_Knob_Pos+=-1;
        temp_Knob.write(temp_Knob_Pos);
     }
     

     if ((currentMillis - previousMillis < timeHumid)&& (currentHumid<90) && (currentHumid!=-1)) {
      spray();
     }



  
}
