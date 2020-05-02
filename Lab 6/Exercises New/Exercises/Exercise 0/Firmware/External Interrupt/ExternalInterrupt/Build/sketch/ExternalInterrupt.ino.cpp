#include <Arduino.h>
#line 1 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 0\\Firmware\\External Interrupt\\ExternalInterrupt\\ExternalInterrupt.ino"
/******************************************************************
 Created with PROGRAMINO IDE for Arduino - 22.04.2020 22:57:31
 Project     :Using External Interrupt
 Libraries   :Built In Interrupt
 Author      :Waleed El-Badry
 Description :Using Interrupt to check if button is clicked
******************************************************************/

int interruptPin = 2;
unsigned long counter = 0;
#line 11 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 0\\Firmware\\External Interrupt\\ExternalInterrupt\\ExternalInterrupt.ino"
void printing();
#line 17 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 0\\Firmware\\External Interrupt\\ExternalInterrupt\\ExternalInterrupt.ino"
void setup();
#line 24 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 0\\Firmware\\External Interrupt\\ExternalInterrupt\\ExternalInterrupt.ino"
void loop();
#line 11 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 0\\Firmware\\External Interrupt\\ExternalInterrupt\\ExternalInterrupt.ino"
void printing()
{
  counter ++;
  Serial.println(counter);
}

void setup()
{
   Serial.begin(9600); 
   pinMode(LED_BUILTIN,OUTPUT);
   attachInterrupt(digitalPinToInterrupt(interruptPin), printing, RISING);
}

void loop()
{

    digitalWrite(LED_BUILTIN,HIGH);
    delay(3000);
    digitalWrite(LED_BUILTIN,LOW);
    delay(3000);
}
