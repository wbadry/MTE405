//  ___  ________ _____     ___ _____ _____ 
//  |  \/  |_   _|  ___|   /   |  _  |  ___|
//  | .  . | | | | |__    / /| | |/' |___ \ 
//  | |\/| | | | |  __|  / /_| |  /| |   \ \
//  | |  | | | | | |___  \___  \ |_/ /\__/ /
//  \_|  |_/ \_/ \____/      |_/\___/\____/ 
//                                          
//                                          
//   _       ___  ______   ______           
//  | |     / _ \ | ___ \ |___  /           
//  | |    / /_\ \| |_/ /    / /            
//  | |    |  _  || ___ \   / /             
//  | |____| | | || |_/ / ./ /              
//  \_____/\_| |_/\____/  \_/               
//                                                                                
//  Code created by : Waleed El-Badry
//  DATE : 29/04/2019
//  Interfacing SPI digital potentiometer (DigiPot)

// Included libraries
#include <SPI.h>

// Serial port
#define PORT Serial

//Hardware pins
byte ChipSelectPin = 10;                // CS pin

// AD5204 channels
byte Ch1Address = 0x00;                 // AD5204 channel 1 address
byte Ch2Address = 0x01;                 // AD5204 channel 2 address
byte Ch3Address = 0x02;                 // AD5204 channel 3 address
byte Ch4Address = 0x03;                 // AD5204 channel 4 address

int   PotValue = 0;                     // Pot value (0-255)

// Set AD5204 digipot resistance
void setAD5204 (const byte Address, const byte Value)
{
  // Select Chip
  digitalWrite(ChipSelectPin, LOW);
  // Send Address
  SPI.transfer(Address);
  // Send value (0-255)
  SPI.transfer(Value);
  // Deselect Chip
  digitalWrite(ChipSelectPin, HIGH);
}

void setup() {
  pinMode(ChipSelectPin, OUTPUT);       // Set CS pin as output
  digitalWrite(ChipSelectPin, HIGH);    // Deselect Chip
  PORT.begin(115200);                   // Initialize UART module
  SPI.begin();                          // Initialize SPI  module
}

void loop() {}

// Serial Interrupt Serial Routine
void serialEvent()
{
  // Read command characters until \n is received
  auto IncomingCommand = PORT.readStringUntil('\n');
  const auto Command = IncomingCommand.substring(0, IncomingCommand.indexOf(','));
  auto StringData = IncomingCommand.substring(IncomingCommand.indexOf(',') + 1, IncomingCommand.length());
  PORT.flush();

  // Receive Digipot CH2 command
  if (Command == "pot1")
  {
    // Set AD5204 (channel 3) 
    PotValue = StringData.toInt();
    setAD5204(Ch1Address, PotValue); 
  }

  // Receive Digipot CH2 command
  if (Command == "pot2")
  {
    // Set AD5204 (channel 3) 
    PotValue = StringData.toInt();
    setAD5204(Ch2Address, PotValue); 
  }

  // Receive Digipot CH3 command
  if (Command == "pot3")
  {
    // Set AD5204 (channel 3) 
    PotValue = StringData.toInt();
    setAD5204(Ch3Address, PotValue); 
  }
	
  // Receive Digipot CH2 command
  if (Command == "pot4")
  {
    // Set AD5204 (channel 3) 
    PotValue = StringData.toInt();
    setAD5204(Ch4Address, PotValue); 
  }
}
