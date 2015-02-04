/*
This class has been modified to avoid use old SoftwareSerial library from chipkit mpide. It was tested with Chipkit Max32 board.
This class uses Serial conection to communicate arduino board with other devices over bluetooth. 
*/
#include "rbaBluetoothChipKit.h"

rbaBluetooth::rbaBluetooth() : noState(1) 
{                                                                                                 

}
rbaBluetooth::rbaBluetooth(uint8_t rba_state) : noState(0) 
{                                                                                                                    

	rba_btStatePin = rba_state;
}

//Pins initialization. Pins are cofigured as inputs or ouputs.
void rbaBluetooth::begin()
{
	if (noState == 0){ //If there is state pin.
		pinMode(rba_btStatePin, INPUT); // Arduino reads from bluetooth state(int) pin.
		bt_state = 0; //No connected state.
	}
	else{
		bt_state = 1; // To bypass connection checking when there is not state pin in bluetooth.
	}
	Serial1.begin(9600); //bluetooth is conected to serial1 port
	//Serial1.flush();

}

int rbaBluetooth::atCommand(String at_command, String bt_data = ""){ // Modify settings of bluetooth using AT Commands(baud rate, name, version, etc).
	int isSuccess = 0;
	String recvBuf;
	char recvChar='\0';


	String cmd("AT+"); //Concatenate strings to build AT Command;
	cmd += at_command;
	cmd += bt_data;
	//cmd += '\r';
	//cmd += '\n';
	
	int cmdLen = cmd.length()+1;
	char atcmd[cmdLen];
	cmd.toCharArray(atcmd, cmdLen);
	
	Serial1.print(atcmd); //Write data to the buffer.

	delay(2000);
	

	while (available() > 0){ // If there is data in the buffer. The data is read.
		recvChar = read();
		delay(200);
		Serial.print(recvChar);
	}
	if (recvChar !=  '\0' ){ //Check if there was answer to AT command.
		isSuccess = 1;
	}
	
	return isSuccess;
}

void rbaBluetooth::print(uint8_t byte) //Write to the bluetooth buffer (tx).
{
	Serial1.print(byte);
}

uint8_t rbaBluetooth::read() //Read from the bluetooth buffer (rx).
{
	return (Serial1.read());
}

int rbaBluetooth::available() //Get the number of bytes available for reading from buffer.
{
	return (Serial1.available());
}

int rbaBluetooth::connected() //Verify if bluetooth is connected to arduino using the state pin. Read the state from state pin.
{
	
	if (noState == 0){ //Check if there is state pin.
		int readState = digitalRead(rba_btStatePin);
		if (readState != bt_state){
			bt_state = readState;
			delay(1);
		}
	}
	return bt_state;
}

rbaBluetooth::~rbaBluetooth()
{

}
