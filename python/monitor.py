import serial
import time

arduino = serial.Serial("COM7", 9600)

startTime = time.time()

times = []
lightData = []
soundData = []

while True:
    line = arduino.readline().decode().strip()
    if line.startswith("DATA"):
        parts = line.split(",")

        light = int(parts[1])
        sound = int(parts[2])

        times.append(time.time() - startTime)
        lightData.append(light)
        soundData.append(sound)

        print("Time: ")
        print(time.time() - startTime)
        print("Light:", light)
        print("Sound:", sound)


