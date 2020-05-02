# 1 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 0\\Firmware\\External Interrupt\\ExternalInterrupt\\ExternalInterrupt.ino"
/******************************************************************

 Created with PROGRAMINO IDE for Arduino - 22.04.2020 22:57:31

 Project     :Using External Interrupt

 Libraries   :Built In Interrupt

 Author      :Waleed El-Badry

 Description :Using Interrupt to check if button is clicked

******************************************************************/
# 9 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 0\\Firmware\\External Interrupt\\ExternalInterrupt\\ExternalInterrupt.ino"
int interruptPin = 2;
unsigned long counter = 0;
void printing()
{
  counter ++;
  Serial.println(counter);
}

void setup()
{
   Serial.begin(9600);
   pinMode(13,0x1);
   attachInterrupt(((interruptPin) == 2 ? 0 : ((interruptPin) == 3 ? 1 : -1)), printing, 3);
}

void loop()
{

    digitalWrite(13,0x1);
    delay(3000);
    digitalWrite(13,0x0);
    delay(3000);
}
