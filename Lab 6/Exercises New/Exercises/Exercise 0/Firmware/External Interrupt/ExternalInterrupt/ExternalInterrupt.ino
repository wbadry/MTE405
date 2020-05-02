/******************************************************************
 Created with PROGRAMINO IDE for Arduino - 22.04.2020 22:57:31
 Project     :Using External Interrupt
 Libraries   :Built In Interrupt
 Author      :Waleed El-Badry
 Description :Using Interrupt to check if button is clicked
******************************************************************/

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