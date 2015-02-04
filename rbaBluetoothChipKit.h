/*
This class has been modified to avoid use old SoftwareSerial library from chipkit mpide. 
This class uses Serial conection to communicate arduino board with other devices over bluetooth.
*/

#ifndef _RBABLUETOOTHCHIPKIT_H
#define _RBABLUETOOTHCHIPKIT_H

#include <Arduino.h>
#include <WString.h>

class rbaBluetooth
{
public:
	rbaBluetooth(); // There is no need to set reception pin and transmission pin. Serial1 port has been used.
	rbaBluetooth(uint8_t rba_state); // Set an extra pin to check bluetooth state.
	~rbaBluetooth();

	void begin();
	
	int atCommand(String at_command,String bt_data);
	void print(uint8_t byte);
	uint8_t read();
	int available();
	int connected();


private:

	uint8_t rba_btStatePin;
	int bt_state;
	int noState;
	
};

#endif