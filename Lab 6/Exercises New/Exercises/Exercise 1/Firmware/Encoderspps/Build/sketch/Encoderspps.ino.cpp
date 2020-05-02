#include <Arduino.h>
#line 1 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 1\\Firmware\\Encoderspps\\Encoderspps.ino"
#include "TimerOne.h"

/******************************************************************
 Created with PROGRAMINO IDE for Arduino - 22.04.2020 22:57:31
 Project     :Get Encoder Speed (PPS)
 Libraries   :Timer One - Built In Interrupt
 Author      :Waleed El-Badry
 Description :Calculating Encoder Speed in PPS
******************************************************************/
#include<TimerOne.h>


int interruptPin = 2;
volatile unsigned long counter = 0;
int pps = 0;
#line 16 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 1\\Firmware\\Encoderspps\\Encoderspps.ino"
void countingPulses();
#line 21 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 1\\Firmware\\Encoderspps\\Encoderspps.ino"
void calculateSpeedPPS();
#line 31 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 1\\Firmware\\Encoderspps\\Encoderspps.ino"
void setup();
#line 39 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 1\\Firmware\\Encoderspps\\Encoderspps.ino"
void loop();
#line 16 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 1\\Firmware\\Encoderspps\\Encoderspps.ino"
void countingPulses()
{
  counter ++;
}

void calculateSpeedPPS()
{
    noInterrupts();
    pps = counter;
    Serial.print("Speed (PPS): ");
    Serial.println(pps);
    counter = 0;
    interrupts();
}

void setup()
{
   Serial.begin(9600); 
   attachInterrupt(digitalPinToInterrupt(interruptPin), countingPulses, RISING);
   Timer1.initialize(1000000);
   Timer1.attachInterrupt(calculateSpeedPPS);
}

void loop()
{
}

