# 1 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 2\\MultiEncodersppsms\\MultiEncodersppsms.ino"
# 2 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 2\\MultiEncodersppsms\\MultiEncodersppsms.ino" 2

/******************************************************************

 Created with PROGRAMINO IDE for Arduino - 22.04.2020 22:57:31

 Project     :Get Encoder Speed (PPS)

 Libraries   :Timer One - Built In Interrupt

 Author      :Waleed El-Badry

 Description :Calculating Encoder Speed in PPS

******************************************************************/
# 10 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 2\\MultiEncodersppsms\\MultiEncodersppsms.ino"
# 11 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 2\\MultiEncodersppsms\\MultiEncodersppsms.ino" 2


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
    
# 31 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 2\\MultiEncodersppsms\\MultiEncodersppsms.ino" 3
   __asm__ __volatile__ ("cli" ::: "memory")
# 31 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 2\\MultiEncodersppsms\\MultiEncodersppsms.ino"
                 ;
    pps1 = ((counter1 * 1.0)/(intervalInUS))*(1000000.0);
    pps2 = ((counter2 * 1.0)/(intervalInUS))*(1000000.0);
    Serial.print("Encoder 1 Speed (PPS): ");
    Serial.println(pps1);
    Serial.print("Encoder 2 Speed (PPS): ");
    Serial.println(pps2);
    Serial.println();
    counter1 = 0;
    counter2 = 0;
    
# 41 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 2\\MultiEncodersppsms\\MultiEncodersppsms.ino" 3
   __asm__ __volatile__ ("sei" ::: "memory")
# 41 "C:\\Data\\University\\MTE 405 Sensors and Measurements\\Lab 6\\Exercises New\\Exercises\\Exercise 2\\MultiEncodersppsms\\MultiEncodersppsms.ino"
               ;
}

void setup()
{
   Serial.begin(9600);
   attachInterrupt(((interruptPin1) == 2 ? 0 : ((interruptPin1) == 3 ? 1 : -1)), countingPulses1, 3);
   attachInterrupt(((interruptPin2) == 2 ? 0 : ((interruptPin2) == 3 ? 1 : -1)), countingPulses2, 3);
   Timer1.initialize(intervalInUS);
   Timer1.attachInterrupt(calculateSpeedPPS);
}

void loop()
{
}
