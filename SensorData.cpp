#include <Arduino.h>
#include "SensorData.h"

const int LDR = A0;
const int MIC = A1;
const int VOL_BASELINE = 505;

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

    int totalSoundDev = 0;
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
