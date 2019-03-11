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
//  DATE : 11/03/2019
//  Transfer noisy sensor data from Arduino / Proteus to SerialPlot

////// Libraries Imported //////
#include <TimerOne.h>

// port to be used
#define PORT Serial

// Simulation or real time acquisition
# define IS_SIMULATION true

// Variables section
float lm35_temperature = 0;
byte lm35_pin = A0;

// Timer Interrupt Service Routine
void timer_one_isr()
{
	//Check if simulation mode or real time mode
	if (IS_SIMULATION == true)
	{
		// Proteus Simulation with noise
		// Convert acquired LM35 voltage into temperature
		lm35_temperature = (analogRead(lm35_pin) * (5.0 / 1023.0)) * (1000 / 10.0);
		lm35_temperature = lm35_temperature + random(-2, 2);
		PORT.println(lm35_temperature);
	}
	else
	{
		// Realtime acquisition from physical sensor
		// Convert acquired LM35 voltage into temperature
		lm35_temperature = (analogRead(lm35_pin) * (5.0 / 1023.0)) * (1000.0 / 10.0);
		PORT.println(lm35_temperature);
	}
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
	// Read command characters until \n is received
	auto command = PORT.readStringUntil('\n');
	command = command.substring(0, command.indexOf(','));
	PORT.flush();
	// Parsing command
	if (command == "start")
	{
		// Start streaming data
		Timer1.initialize(100000); // every 100 ms
		//Attach ISR
		Timer1.attachInterrupt(timer_one_isr);
	}
	if (command == "stop")
	{
		// Stop stream
		//Attach ISR
		Timer1.detachInterrupt();
	}
}
