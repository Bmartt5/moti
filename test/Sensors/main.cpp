#include <Arduino.h>
#include <Wire.h>

// #include "Sensors.h"
// #include "DriveSystem.h"
#include "ChibiOS_AVR.h"
#include "ADXL345.h"

#define Serio Serial

#define FIMU_ACC_ADDR ADXL345_ADDR_ALT_LOW

ADXL345 acc;

// int DTC;
// byte range;

// void detect(uint16_t timeS){
// 	for (uint16_t i=0; i<timeS; ++i){

// 		Serio.print(millis());
// 		Serio.print(", ");

// 		Serio.print(DTC);
// 		Serio.print(", ");

// 		Serio.print(Sensors::getAccX());
// 		Serio.print(", ");
// 		//Serio.print(F("  Y: "));
// 		Serio.print(Sensors::getAccY());
// 		Serio.print(", ");
// 		//Serio.print(F("  Z: "));
// 		Serio.print(Sensors::getAccZ());
// 		Serio.print(", ");

// 		//Serio.print(F("  Yaw: "));
// 		Serio.print(Sensors::getGyrY());
// 		Serio.print(", ");
// 		//Serio.print(F("  Pitch: "));
// 		Serio.print(Sensors::getGyrP());
// 		Serio.print(", ");
// 		//Serio.print(F("  Roll: "));
// 		Serio.print(Sensors::getGyrR());
// 		Serio.print(", ");

// 		//Serio.print(F("  Yaw deg: "));
// 		Serio.print(Sensors::getGyrYDeg());
// 		Serio.print(", ");
// 		//Serio.print(F("  Pitch deg: "));
// 		Serio.print(Sensors::getGyrPDeg());
// 		Serio.print(", ");
// 		//Serio.print(F("  Roll deg: "));
// 		Serio.print(Sensors::getGyrRDeg());
// 		Serio.print(", ");

// 		//Serio.print(F("  Phi: "));
// 		Serio.print(Sensors::getEulerPhi());
// 		Serio.print(", ");
// 		//Serio.print(F("  Theta: "));
// 		Serio.print(Sensors::getEulerTheta());
// 		Serio.print(", ");
// 		//Serio.print(F("  Psi: "));
// 		Serio.print(Sensors::getEulerPsi());

// 		Serio.println();
// 	}
// }

void chSetup() {

	// Sensors::init();
	// Sensors::start();
	acc.init(FIMU_ACC_ADDR);
	// int setRange = 4;
	// Serio.print("Sensor range: ");
	// acc.setRangeSetting(setRange);
	delay(500);
	// acc.getRangeSetting(&range);
	// byte rangeDisplay = range;
	// Serio.print(range);

	int xyz[3];

	while (1) {

		acc.readAccel(&xyz[0], &xyz[1], &xyz[2]);
		Serio.println(xyz[2]);

		delay(100);
	}
}


void setup() {
	Serio.begin(115200);
	while (!Serio);

	Wire.begin();
	delay(500);

	chBegin(chSetup);

	while (1);
}

void loop() { }
