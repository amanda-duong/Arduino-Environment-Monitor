# This file includes Python code that receives data from the Arduino and produces a live graphical representation of it

import serial
import time
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# Connect to Arduino through serial port
arduino = serial.Serial("COM7", 9600)

# Store sensor and time data to be plotted
startTime = time.time()
times = []
lightData = []
soundData = []


# Plot light and sound data vs time
fig, (graph1, graph2) = plt.subplots(2, 1)

def update(frame):
    line = arduino.readline().decode().strip()

    # Extract light and sound data from serial output from Arduino
    if line.startswith("DATA"):
        parts = line.split(",")
        light = int(parts[1])
        sound = int(parts[2])

        # Record time of sensor readings
        currentTime = time.time() - startTime
        times.append(currentTime)
        lightData.append(light)
        soundData.append(sound)

        # Plot sound level vs time
        graph1.clear()
        graph1.plot(times, soundData)
        graph1.set_ylim(0,300)
        graph1.set_xlabel("Time (seconds)")
        graph1.set_ylabel("Sound Level")
        graph1.set_title("Live Sound Level")

        # Plot light level vs time
        graph2.clear()
        graph2.plot(times, lightData)
        graph2.set_ylim(0,1000)
        graph2.set_xlabel("Time (seconds)")
        graph2.set_ylabel("Light Level (ADC)")
        graph2.set_title("Live Light Level")

        # Print data values for monitoring and potential debugging
        print("Time:", round(currentTime, 2))
        print("Light:", light)
        print("Sound:", sound)

# Update plots every 100 milliseconds
ani = FuncAnimation(fig, update, interval=100)

# Adjust text spacing and display plots
plt.tight_layout()
plt.show()

