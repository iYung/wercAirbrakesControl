#ifndef FOOP_H
#define FOOP_H

#include <Arduino.h> //needed for Serial.println
#include <string.h> //needed for memcpy

double getAirDensity(double groundTemp, double groundPressure, double currHeight);

#endif
