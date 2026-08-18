#ifndef SENSORDATA_H
#define SENSORDATA_H

struct SensorData
{
    int light;
    int sound;
};

extern const int greenLED;
extern const int yellowLED;
extern const int redLED;

SensorData readSensors();
int getSoundLevel();
String getSoundDescriptor(int soundLevel);
String getLightDescriptor(int lightLevel);
String ledOutput(int soundLevel, int lightLevel);

#endif