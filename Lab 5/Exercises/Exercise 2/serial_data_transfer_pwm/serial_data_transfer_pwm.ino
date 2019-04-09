//  ___  ________ _____     ___ _____ _____ 
//  |  \/  |_   _|  ___|   /   |  _  |  ___|
//  | .  . | | | | |__    / /| | |/' |___ \ 
//  | |\/| | | | |  __|  / /_| |  /| |   \ \
//  | |  | | | | | |___  \___  \ |_/ /\__/ /
//  \_|  |_/ \_/ \____/      |_/\___/\____/ 
//                                          
//                                          
//   _       ___  ______	 _____            
//  | |     / _ \ | ___ \	|  ___|           
//  | |    / /_\ \| |_/ /	|___ \            
//  | |    |  _  || ___ \		\ \           
//  | |____| | | || |_/ /	/\__/ /           
//  \_____/\_| |_/\____/	\____/            
//                                                                                           
//  Code created by : Waleed El-Badry
//  DATE : 09/04/2019
//  Change DC motor speed using PWM

////// Libraries Imported //////
#include <TimerOne.h>

// port to be used
#define PORT Serial1

// Variables section
volatile byte PwmValue = 0;
byte PwmPin = 9;		// 488 Hz
byte DirectionPin = 8;  // Motor Direction
volatile byte Direction = 10;

// Timer Interrupt Service Routine
void timerOneIsr()
{
	PORT.print(PwmValue);
	PORT.print(",");
	PORT.println(Direction);
}

void setup()
{
	// Start serial port with 115200 bps
	PORT.begin(115200);
	pinMode(PwmPin,OUTPUT); // Set pin to output
	pinMode(DirectionPin,OUTPUT); // Set pin to output
	digitalWrite(DirectionPin,LOW);
	digitalWrite(PwmPin,LOW);
}

void loop()
{
}

// Serial Interrupt Serial Routine
void serialEvent1()
{
	// Read command characters until \n is received
	auto IncomingCommand = PORT.readStringUntil('\n');
	const auto Command = IncomingCommand.substring(0, IncomingCommand.indexOf(','));
	auto StringData = IncomingCommand.substring(IncomingCommand.indexOf(',') + 1, IncomingCommand.length());
	PORT.flush();
	// Parsing command
	if (Command == "start")
	{
		// Start streaming data
		Timer1.initialize(100000); // every 100 ms
		//Attach ISR
		Timer1.attachInterrupt(timerOneIsr);
	}
	if (Command == "stop")
	{
		// Stop stream
		//Detach ISR
		Timer1.detachInterrupt();
	}

	// New command for PWM
	if (Command == "pwm")
	{
		// Send PWM value 
		PwmValue = StringData.toInt();
		analogWrite(PwmPin, PwmValue);
	}

	// New command for direction
	if (Command == "dir")
	{
		// Set Motor Direction
		Direction = StringData.toInt();
		if (Direction == 10)
		{
			digitalWrite(DirectionPin,1);
		}
		if (Direction == 20)
		{
			digitalWrite(DirectionPin,0);
		}
	}
}
