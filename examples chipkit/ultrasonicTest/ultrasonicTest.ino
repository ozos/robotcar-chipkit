

#include <SoftwareSerial.h>
#include <rbaUltrasonicSensor.h>

//Connect the Ultrasonic Sensor Trigger to A4 Echo to A5
rbaUltrasonicSensor myUltrasonicSensor(A4, A5);

void setup()
{
	myUltrasonicSensor.begin();
	Serial.begin(9600);
}

void loop()
{
	int distance = myUltrasonicSensor.distance();
	Serial.print("Distance cm:");
	Serial.println(distance);
	delay(1000);
}
