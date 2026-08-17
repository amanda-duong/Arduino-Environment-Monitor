struct SensorData
{
    int light;
    int sound;
};

SensorData readSensors();

String getSoundDescriptor(int soundLevel);

String getLightDescriptor(int lightLevel);