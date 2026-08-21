// This file contains the implemntations of sensor-reading, data-processing, and LED-output functions used throughout the Arduino files

#include <Arduino.h>
#include "SensorData.h"

// Define sensor and LED pins
const int LDR = A0;
const int MIC = A1;
const int greenLED = 5;
const int yellowLED = 4;
const int redLED = 3;

// Define volume baseline value from microphone
const int VOL_BASELINE = 505;

// This function calculates and returns the relative sound level based on the volume baseline
int getSoundLevel()
{
    int value = analogRead(MIC);
    int deviation = abs(value - VOL_BASELINE);
    return deviation;
}

// This function collects sensor readings and averages them to return desired relative sound and light levels
SensorData readSensors()
{
    SensorData data;

    int totalLightVal = 0;
    for (int i = 0; i < 10; i++)
    {
        totalLightVal += analogRead(LDR);
    }
    data.light = totalLightVal/10;

    long totalSoundDev = 0;
    for (int i = 0; i < 100; i++)
    {
        totalSoundDev += getSoundLevel();
    }
    data.sound = totalSoundDev/100;

    return data;
}

// This function returns a description (in words) of the sound level given sound level data
// Based on empirical threshold values
String getSoundDescriptor(int soundLevel)
{
    if (soundLevel < 50)
    {
        return "quiet";
    }
    else if (soundLevel < 180)
    {
        return "moderately loud";
    }
    else
    {
        return "loud";
    }
}

// This function returns a description (in words) of the light level given light level data
// Based on empirical threshold values
String getLightDescriptor(int lightLevel)
{
    if (lightLevel < 200)
    {
        return "dark";
    }
    else if (lightLevel < 700)
    {
        return "moderately bright";
    }
    else
    {
        return "bright";
    }
}

// This function activates an LED and returns LED status in words given sound and light level data
// Based on empirical threshold values
String ledOutput(int soundLevel, int lightLevel)
{
    if (lightLevel < 700 && soundLevel < 50)
    {
        digitalWrite(greenLED, HIGH);
        digitalWrite(yellowLED, LOW);
        digitalWrite(redLED, LOW);
        return "Green";
    }
    else if(lightLevel < 700 && soundLevel < 180)
    {
        digitalWrite(greenLED, LOW);
        digitalWrite(yellowLED, HIGH);
        digitalWrite(redLED, LOW);
        return "Yellow";
    }
    else
    {
        digitalWrite(greenLED, LOW);
        digitalWrite(yellowLED, LOW);
        digitalWrite(redLED, HIGH);
        return "Red";
    }
}