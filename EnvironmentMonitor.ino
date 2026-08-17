#include "SensorData.h"

void setup()
{
    Serial.begin(9600);
}


void loop()
{
    SensorData data = readSensors();

    Serial.print("Light: ");
    Serial.println(data.light);

    Serial.print("Sound: ");
    Serial.println(data.sound);

    Serial.print("The environment is ");
    Serial.print(getLightDescriptor(data.light));
    Serial.print(" and ");
    Serial.println(getSoundDescriptor(data.sound));

    delay(1000);
}




