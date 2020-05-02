#include "TimerOne.h"

/******************************************************************
 Created with PROGRAMINO IDE for Arduino - 22.04.2020 22:57:31
 Project     :Get Encoder Speed (PPS)
 Libraries   :Timer One - Built In Interrupt
 Author      :Waleed El-Badry
 Description :Calculating Encoder Speed in PPS
******************************************************************/
#include<TimerOne.h>


int interruptPin1 = 2, interruptPin2 = 3;
volatile unsigned long counter1 = 0, counter2 =0;
int pps1 = 0, pps2 = 0;
long intervalInUS = 1000000; 

void countingPulses1()
{
  counter1 ++;
}

void countingPulses2()
{
  counter2 ++;
}


void calculateSpeedPPS()
{
    noInterrupts();
    pps1 = ((counter1 * 1.0)/(intervalInUS))*(1000000.0);
    pps2 = ((counter2 * 1.0)/(intervalInUS))*(1000000.0);
    Serial.print("Encoder 1 Speed (PPS): ");
    Serial.println(pps1);
    Serial.print("Encoder 2 Speed (PPS): ");
    Serial.println(pps2);
    Serial.println();
    counter1 = 0;
    counter2 = 0;
    interrupts();
}

void setup()
{
   Serial.begin(9600); 
   attachInterrupt(digitalPinToInterrupt(interruptPin1), countingPulses1, RISING);
   attachInterrupt(digitalPinToInterrupt(interruptPin2), countingPulses2, RISING);
   Timer1.initialize(intervalInUS);
   Timer1.attachInterrupt(calculateSpeedPPS);
}

void loop()
{
}
