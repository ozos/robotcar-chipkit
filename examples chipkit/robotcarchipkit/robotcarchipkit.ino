#include <SoftwareSerial.h>
#include <rbaMotorDriver.h>
#include <rbaBluetoothChipKit.h>
#include "arduinoCarchipkit.h"

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
