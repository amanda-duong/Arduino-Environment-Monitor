struct SensorData
{
    int light;
    int sound;
};

const int LDR = A0;
const int MIC = A1;
const int VOL_BASELINE = 505;

void setup()
{
    Serial.begin(9600);
}

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



void loop()
{
    SensorData data = readSensors();

    Serial.print("Light: ");
    Serial.println(data.light);

    Serial.print("Sound: ");
    Serial.println(data.sound);

    delay(1000);
}




