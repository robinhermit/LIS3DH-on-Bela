# LIS3DH-on-Bela
## Basic Adafruit LIS3DH accelerometer readings on Bela
Drag all these files in a fresh Bela project.
render.cpp prints out accelerometers reading in the Bela console.

## NOTE: you need to have flashed Bela with the better-i2c-rebased-2022 image:
https://github.com/robinhermit/Bela/tree/better-i2c-rebased-2022

## TO DO:
- Test receiving x, y and z data stored on variables on Pure Data or Supercollider
- create Supercollider UGen to handel the LIS3DH registers instead of using a render.cpp file
- troubleshoot & add LIS3DH gyroscope readings as well
