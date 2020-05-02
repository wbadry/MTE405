# 1 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 2\\Encodersppsms\\Encodersppsms.ino"
# 2 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 2\\Encodersppsms\\Encodersppsms.ino" 2

/******************************************************************

 Created with PROGRAMINO IDE for Arduino - 22.04.2020 22:57:31

 Project     :Get Encoder Speed (PPS)

 Libraries   :Timer One - Built In Interrupt

 Author      :Waleed El-Badry

 Description :Calculating Encoder Speed in PPS

******************************************************************/
# 10 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 2\\Encodersppsms\\Encodersppsms.ino"
# 11 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 2\\Encodersppsms\\Encodersppsms.ino" 2


int interruptPin = 2;
volatile unsigned long counter = 0;
int pps = 0;
long intervalInUS = 500000;
void countingPulses()
{
  counter ++;
}

void calculateSpeedPPS()
{
    
# 24 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 2\\Encodersppsms\\Encodersppsms.ino" 3
   __asm__ __volatile__ ("cli" ::: "memory")
# 24 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 2\\Encodersppsms\\Encodersppsms.ino"
                 ;
    pps = ((counter * 1.0)/(intervalInUS))*(1000000.0);
    Serial.print("Speed (PPS): ");
    Serial.println(pps);
    counter = 0;
    
# 29 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 2\\Encodersppsms\\Encodersppsms.ino" 3
   __asm__ __volatile__ ("sei" ::: "memory")
# 29 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 2\\Encodersppsms\\Encodersppsms.ino"
               ;
}

void setup()
{
   Serial.begin(9600);
   attachInterrupt(((interruptPin) == 2 ? 0 : ((interruptPin) == 3 ? 1 : -1)), countingPulses, 3);
   Timer1.initialize(intervalInUS);
   Timer1.attachInterrupt(calculateSpeedPPS);
}

void loop()
{
}
