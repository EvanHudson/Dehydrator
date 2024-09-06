Dehydrator Control Program
Author
Test Footage https://www.youtube.com/watch?v=tTGO0I-jBCs&authuser=0
    Author: Evan Hudson
    Version: Json 1.0

Overview

This C++ program is designed to control a Raspberry Pi Pico-based homemade dehydrator. The primary functions include regulating the temperature inside the dehydrator using a servo-controlled heated lamp and introducing humidity for a specified portion of the total cooking time with a servo-controlled water spray bottle.
Components Used

    Temperature Control Servo: A servo motor is connected to a potentiometer to control the intensity of a heated lamp, regulating the temperature inside the dehydrator.
    Humidity Control Servo: Another servo motor is connected to a water spray bottle for introducing humidity into the dehydrator.
    DHT22 Temperature and Humidity Sensor: This sensor measures the current temperature and humidity inside the dehydrator.

Program Logic

    The program initializes the positions of both servos: the temperature control servo is set to the maximum position (360 degrees), and the humidity control servo is set to the minimum position (0 degrees).
    A timer is set for the total cooking time in hours, and a fraction of this time is allocated for maintaining humidity.
    The loop continuously monitors the temperature and humidity inside the dehydrator.
    It handles the initial heating phase, gradually decreasing the temperature after a preheat time.
    During the specified fraction of the total cooking time, if the current humidity is below 90%, it activates the water spray to introduce humidity.

Functions

    getTimeHumid(unsigned long interval): Calculates the time period for maintaining humidity based on the specified fraction.
    getTemperature(): Reads and returns the current temperature from the DHT22 sensor.
    getHumidity(): Reads and returns the current humidity from the DHT22 sensor.
    spray(): Activates the water spray by moving the humidity control servo.
    setTemperature(int temp): A placeholder for setting the desired temperature (not implemented in the provided code).

Usage

    The program outputs temperature and humidity readings to the serial monitor for monitoring and debugging purposes.

Notes

    The code currently uses a simple delay mechanism for the initial preheat and gradual decrease in temperature. More sophisticated control algorithms can be implemented for improved temperature regulation.
    Consider implementing error handling and recovery mechanisms for potential sensor failures.

Future Improvements

    Implement a more sophisticated temperature control algorithm.
    Add user input support for setting desired temperature and humidity levels.
    Enhance the program's robustness and error-handling capabilities.
