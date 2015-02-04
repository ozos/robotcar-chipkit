#include <SoftwareSerial.h>
#include <rbaMotorDriver.h>
#include <rbaBluetoothChipKit.h>
#include "arduinoCar.h"

arduinoCar myCar;
void setup()
{
	Serial.begin(9600);
	myCar.begin();

}

void loop()
{
	myCar.readKey();
	myCar.processKey();
}
