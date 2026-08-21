// This file includes declarations of methods, function, and variables that may or may not be used across all Arduino files

#ifndef SENSORDATA_H
#define SENSORDATA_H

// Store measured light and sound value
struct SensorData
{
    int light;
    int sound;
};

// Define LED pins
extern const int greenLED;
extern const int yellowLED;
extern const int redLED;

// Define important methods. Method functions/descriptions can be found in .cpp file
SensorData readSensors();
int getSoundLevel();
String getSoundDescriptor(int soundLevel);
String getLightDescriptor(int lightLevel);
String ledOutput(int soundLevel, int lightLevel);

#endif