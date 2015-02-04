#include <SoftwareSerial.h>
#include <rbaLineFinder.h>


//Connect Line Finder Sensor1 A2, Sensor2 to A3
rbaLineFinder myLineFinder(A2, A3);

void setup()
{
	myLineFinder.begin();
	Serial.begin(9600);
}

void loop()
{
	Serial.print("Sensor1:");
	Serial.println(myLineFinder.lsensor1());
	Serial.print("Sensor2:");
	Serial.println(myLineFinder.lsensor2());
	Serial.println();

	delay(1000);
}
