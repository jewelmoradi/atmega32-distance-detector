# ATmega32 Distance Detector

An ATmega32-based ultrasonic distance detector developed as a university embedded systems project.

## Overview

This project uses an ultrasonic distance sensor with an ATmega32 microcontroller to measure distance and display the result on a 16×2 LCD.

The measured distance is also used to control an LED with different timing patterns depending on the detected distance.

The project was developed and tested through both hardware implementation and Proteus simulation.

## Main Components

- ATmega32 microcontroller
- HC-SR04 ultrasonic distance sensor
- 16×2 LCD
- LED indicator
- CodeVisionAVR
- Embedded C
- Proteus

## How It Works

The microcontroller sends a trigger pulse to the ultrasonic sensor and measures the duration of the returning echo signal.

The measured distance is displayed on the LCD in centimeters.

The LED behavior changes according to the measured distance:

- Distance greater than 20 cm
- Distance between 10 and 20 cm
- Distance below 10 cm

## Simulation

A Proteus simulation of the circuit is included in the `simulation/` directory.

## Project Structure

<pre>src/
└── project.c

project/
└── project.prj

simulation/
└── distance-detector.pdsprj
</pre>

## Project Context

This project was developed as part of the undergraduate Computer Engineering coursework at Shiraz University of Technology.

The project included embedded C development, circuit simulation, and physical hardware implementation.

## Contributors

- [Arezoo Abbakhsh](https://github.com/ZahraAbbakhsh99)
- [Negin Moradi](https://github.com/jewelmoradi)
- [Nika Shahbeyk](https://github.com/NikaShahbeyk)

## Status

Completed university project.
