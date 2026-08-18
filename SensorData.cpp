#include <Arduino.h>
#include "SensorData.h"

const int LDR = A0;
const int MIC = A1;
const int VOL_BASELINE = 505;
const int greenLED = 5;
const int yellowLED = 4;
const int redLED = 3;

int getSoundLevel()
{
    int value = analogRead(MIC);
    int deviation = abs(value - VOL_BASELINE);
    return deviation;
}

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