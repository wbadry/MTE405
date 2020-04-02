//  .___  ___. .___________. _______     _  _      ___    _____  
//  |   \/   | |           ||   ____|   | || |    / _ \  | ____| 
//  |  \  /  | `---|  |----`|  |__      | || |_  | | | | | |__   
//  |  |\/|  |     |  |     |   __|     |__   _| | | | | |___ \  
//  |  |  |  |     |  |     |  |____       | |   | |_| |  ___) | 
//  |__|  |__|     |__|     |_______|      |_|    \___/  |____/  
//                                                               
//   __          ___      .______       ____                     
//  |  |        /   \     |   _  \     |___ \                    
//  |  |       /  ^  \    |  |_)  |      __) |                   
//  |  |      /  /_\  \   |   _  <      |__ <                    
//  |  `----./  _____  \  |  |_)  |     ___) |                   
//  |_______/__/     \__\ |______/     |____/                    
//                                                      
//  Code created by : Waleed El-Badry
//  DATE : 02/04/2020
//  Read LM35 Voltage, convert it to Temperature and Display it on Terminal

////// Libraries Imported //////
#include <TimerOne.h>

// port to be used
#define PORT Serial

// Variables section
float lm35_temperature = 0;
byte lm35_pin = A0;

// Timer Interrupt Service Routine
void timer_one_isr()
{
	
}

void setup()
{
	// Start serial port with 115200 bps
	PORT.begin(115200);
}

void loop()
{
  
}

// Serial Interrupt Serial Routine
void serialEvent()
{ 
	
}
