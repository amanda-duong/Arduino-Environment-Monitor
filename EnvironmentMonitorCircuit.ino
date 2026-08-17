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

void loop() {
    int totalVal = 0;
    for (int i = 0; i < 10; i++)
    {
        totalVal += analogRead(LDR);
    }
    delay(200);
    Serial.print("Light: ");
    Serial.println(totalVal/10);

    int totalDev = 0;
    for (int i = 0; i < 100; i++)
    {
        totalDev += getSoundLevel();
    }
    Serial.print("Sound: ");
    Serial.println(totalDev/100);
    delay(1000);
}








