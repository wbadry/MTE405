//  ___  ________ _____     ___ _____ _____ 
//  |  \/  |_   _|  ___|   /   |  _  |  ___|
//  | .  . | | | | |__    / /| | |/' |___ \ 
//  | |\/| | | | |  __|  / /_| |  /| |   \ \
//  | |  | | | | | |___  \___  \ |_/ /\__/ /
//  \_|  |_/ \_/ \____/      |_/\___/\____/ 
//                                          
//                                          
//   _       ___  ______    ____            
//  | |     / _ \ | ___ \  / ___|           
//  | |    / /_\ \| |_/ / / /___            
//  | |    |  _  || ___ \ | ___ \           
//  | |____| | | || |_/ / | \_/ |           
//  \_____/\_| |_/\____/  \_____/           
//                                          
//                                                                                         
//  Code created by : Waleed El-Badry
//  DATE : 22/04/2019
//  Reading Motor Speed in RPM

////// Libraries Imported //////
#include <Encoder.h>
#include <TimerOne.h>


// port to be used
#define PORT Serial

// Variables section
volatile byte PwmValue = 0;
byte PwmPin = 5;		// ? Hz
byte DirectionPin = 8;  // Motor Direction
volatile byte Direction = 10; // CCW

// New Variables //
byte EncoderPin = 2; // Pin connected to XOR output
const byte EncoderPulsesPerRevolution =12.0; // 12 pulse per revolution
const float TimerInterval = 1.0; // 100 ms timer interval
volatile float CurrentPulseCount=0.0; // current pulse count

volatile float SpeedRpm = 0.0; // Motor speed in RPM


// Timer Interrupt Service Routine
void timerOneIsr()
{
	if (CurrentPulseCount > 0)
	{
		SpeedRpm = ((CurrentPulseCount/TimerInterval)/EncoderPulsesPerRevolution) * 60.0;
		Serial.println(SpeedRpm);
		CurrentPulseCount=0;
	}
}

// External Interrupt
void countPulses()
{
	CurrentPulseCount++; 
}

void setup()
{
	// Start serial port with 115200 bps
	PORT.begin(115200);
	pinMode(PwmPin,OUTPUT); // Set pin to output
	pinMode(DirectionPin,OUTPUT); // Set pin to output
	digitalWrite(DirectionPin,LOW); // CCW
	digitalWrite(PwmPin,LOW); // Motor is idle

	// New Section
	pinMode(EncoderPin,INPUT); // Set encoder pin as input to receive pulse train

	
}

void loop()
{
}

// Serial Interrupt Serial Routine
void serialEvent()
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
		Timer1.initialize(TimerInterval*1000000.0); // every 100 ms
		//Attach ISR
		Timer1.attachInterrupt(timerOneIsr);

		// New Section
		//Enable external interrupt (Rising Edge)
		attachInterrupt(digitalPinToInterrupt(EncoderPin), countPulses, RISING);
	}
	if (Command == "stop")
	{
		// Stop stream
		//Detach ISR
		Timer1.detachInterrupt();
		detachInterrupt(digitalPinToInterrupt(EncoderPin));
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
