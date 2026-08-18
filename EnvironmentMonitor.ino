#include "SensorData.h"

void setup()
{
    Serial.begin(9600);
    pinMode(greenLED, OUTPUT);
    pinMode(yellowLED, OUTPUT);
    pinMode(redLED, OUTPUT);
}

void loop()
{
    SensorData data = readSensors();

    Serial.println("================================");
    Serial.println("       ENVIRONMENT MONITOR");
    Serial.println("================================");

    Serial.print("Light Level: ");
    Serial.println(data.light);

    Serial.print("Sound Level: ");
    Serial.println(data.sound);

    Serial.print("LED Status: ");
    Serial.println(ledOutput(data.sound, data.light));

    Serial.println("================================");

    delay(1000);
}