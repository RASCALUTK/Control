

#include <LiquidCrystal.h>
#include <stdio.h>
#include <String.h>
#include <Arduino.h>

#ifndef control_h
#define control_h


    void rotaryEncoder(int &aState, int &aLastState, int outputA, int outputB, int &counter, String axis);
    bool toggle(int onOff);

#endif
