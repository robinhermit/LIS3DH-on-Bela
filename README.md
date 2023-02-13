# LIS3DH-on-Bela
## Basic Adafruit LIS3DH accelerometer readings on Bela
Realised in summer 2022 mostly with knowledge & work by Tomáš Kiblik:
https://github.com/kiblik

## Instructions:
Drag all these files in a fresh Bela project.
render.cpp prints out accelerometers reading in the Bela console.
## NOTE:
You need to have flashed Bela with the better-i2c-rebased-2022 image:
https://github.com/robinhermit/Bela/tree/better-i2c-rebased-2022

## TO DO:
- Test receiving x, y and z data stored on variables on Pure Data or Supercollider
- troubleshoot & add LIS3DH gyroscope readings as well
- create Supercollider UGen to handel the LIS3DH registers instead of using a render.cpp file
