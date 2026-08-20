import serial
import time
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

arduino = serial.Serial("COM7", 9600)

startTime = time.time()

times = []
lightData = []
soundData = []

fig, (graph1, graph2) = plt.subplots(2, 1)

def update(frame):
    line = arduino.readline().decode().strip()

    if line.startswith("DATA"):
        parts = line.split(",")
        light = int(parts[1])
        sound = int(parts[2])

        currentTime = time.time() - startTime
        times.append(currentTime)
        lightData.append(light)
        soundData.append(sound)

        graph1.clear()
        graph1.plot(times, soundData)
        graph1.set_ylim(0,300)
        graph1.set_xlabel("Time (seconds)")
        graph1.set_ylabel("Sound Level")
        graph1.set_title("Live Sound Level")

        graph2.clear()
        graph2.plot(times, lightData)
        graph2.set_ylim(0,800)
        graph2.set_xlabel("Time (seconds)")
        graph2.set_ylabel("Light Level (ADC)")
        graph2.set_title("Live Light Level")


        print("Time:", round(currentTime, 2))
        print("Light:", light)
        print("Sound:", sound)

ani = FuncAnimation(fig, update, interval=100)
plt.tight_layout()
plt.show()

