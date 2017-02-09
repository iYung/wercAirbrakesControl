#ifndef AIR_D
#define AIR_D

#include <Arduino.h> //needed for Serial.println
#include <string.h> //needed for memcpy

double getAirDensity(double groundTemp, double groundPressure, double currHeight);

#endif
