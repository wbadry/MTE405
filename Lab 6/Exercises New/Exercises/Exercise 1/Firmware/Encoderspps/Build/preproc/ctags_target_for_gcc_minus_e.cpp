# 1 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 1\\Firmware\\Encoderspps\\Encoderspps.ino"
# 2 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 1\\Firmware\\Encoderspps\\Encoderspps.ino" 2

/******************************************************************

 Created with PROGRAMINO IDE for Arduino - 22.04.2020 22:57:31

 Project     :Get Encoder Speed (PPS)

 Libraries   :Timer One - Built In Interrupt

 Author      :Waleed El-Badry

 Description :Calculating Encoder Speed in PPS

******************************************************************/
# 10 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 1\\Firmware\\Encoderspps\\Encoderspps.ino"
# 11 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 1\\Firmware\\Encoderspps\\Encoderspps.ino" 2


int interruptPin = 2;
volatile unsigned long counter = 0;
int pps = 0;
void countingPulses()
{
  counter ++;
}

void calculateSpeedPPS()
{
    
# 23 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 1\\Firmware\\Encoderspps\\Encoderspps.ino" 3
   __asm__ __volatile__ ("cli" ::: "memory")
# 23 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 1\\Firmware\\Encoderspps\\Encoderspps.ino"
                 ;
    pps = counter;
    Serial.print("Speed (PPS): ");
    Serial.println(pps);
    counter = 0;
    
# 28 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 1\\Firmware\\Encoderspps\\Encoderspps.ino" 3
   __asm__ __volatile__ ("sei" ::: "memory")
# 28 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 1\\Firmware\\Encoderspps\\Encoderspps.ino"
               ;
}

void setup()
{
   Serial.begin(9600);
   attachInterrupt(((interruptPin) == 2 ? 0 : ((interruptPin) == 3 ? 1 : -1)), countingPulses, 3);
   Timer1.initialize(1000000);
   Timer1.attachInterrupt(calculateSpeedPPS);
}

void loop()
{
}
