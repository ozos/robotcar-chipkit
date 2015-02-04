
#include <SoftwareSerial.h>
#include <rbaMotorDriver.h>

//M1_EN,M1_IN2,M1_IN1, M2_EN,M2_IN2,M2_IN1
rbaMotorDriver myMotorDriver( A1,10,9,A0,6,5);

int speed = 250;

void setup()
{
	myMotorDriver.begin();
}

void loop()
{
	myMotorDriver.run(speed, speed);
	delay(2000);
	myMotorDriver.run(-speed, -speed);
	delay(2000);
	myMotorDriver.run(speed, -speed);
	delay(2000);
	myMotorDriver.run(-speed, speed);
	delay(2000);
	myMotorDriver.brake();
	delay(2000);
}
