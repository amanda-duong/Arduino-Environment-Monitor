// This file includes code that dictates the program/project flow (sensor reading, data output, and data transmission)

#include "SensorData.h"

// Initialize serial communication and LEDs as outputs
void setup()
{
    Serial.begin(9600);
    pinMode(greenLED, OUTPUT);
    pinMode(yellowLED, OUTPUT);
    pinMode(redLED, OUTPUT);
}

void loop()
{
    // Read sensor data
    SensorData data = readSensors();

    // Serial dashboard that includes digital/numerical sensor readings, LED status, written 
    // description of environment, and data to be passed to Python program
    Serial.println("=====================================================");
    Serial.println("                ENVIRONMENT MONITOR");
    Serial.println("=====================================================");

    Serial.print("Light Level: ");
    Serial.println(data.light);

    Serial.print("Sound Level: ");
    Serial.println(data.sound);

    Serial.print("LED Status: ");
    Serial.println(ledOutput(data.sound, data.light));

    Serial.print("The environment is ");
    Serial.print(getSoundDescriptor(data.sound));
    Serial.print(" and ");
    Serial.println(getLightDescriptor(data.light));

    Serial.print("DATA,");
    Serial.print(data.light);
    Serial.print(",");
    Serial.println(data.sound);

    Serial.println("=====================================================");

    delay(1000);
}