# RGBLighting
This repository contains lighting functionality in a room through the use of Individually addresible RGB Leds

## How to Install
Clone this repository. Load the files into the microcontroller

## Hardware
- Arduino
- Adafruit Circuit Playground
- Adafruit Gemma M0
- Individually addressible RGB Led lights

## Project Idea
The goal of this project is be able to control multi-funcitonal RGB Led lights quickly and easily. The entire setup process should take under 15 minutes.
The lights should have multiple interfaces. One based on physical buttons that control the color, brightness, and mode of the lights. Another interface is Web-Based such as to allow remote  control. This can be achieved with an actual remote control or via a Web interface

### Physical Interface
- 3 buttons
  - 1 Button that changes mode
    - When this button is held down, the mode will change continously in intervals of 1-2 secconds. When the button is released, the mode is set. A single press would therefore have to hold down the button for 1-2 seconds. One of the light modes is with all the lights off.
  - 1 button that changes brightness
    - This button should behave in a similar way to the mode select button. The light will go from minimum brightness to maximum brightness in steps. The button must be continously held down to cycle through the modes.
  - 1 button for extra functionality
    - This button could enable "special" modes. For example, when pressed and held at the same time as the first button is pressed, the colors will shift in hue
- 1 switch for power
- 1 state indicator LED 

### Web Interface
- buttons
- data graphs

### Light Modes and Functionality
- RGB Rainbow
- RGB Pallettes (many)
- Twinkle
- Fire
- Night Light
- Party Light
- Mood Light
