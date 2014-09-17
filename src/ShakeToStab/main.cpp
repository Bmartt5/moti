#include <Arduino.h>
#include <Wire.h>

#include "Motion.h"
#include "Moti.h"
#include "Light.h"

#include "Stabilization.h"

typedef enum {
	SLEEPING = 0x01,
	STABILIZING = 0x02,
} ArbitrerState;

Led heart = Led(11, 12, 13);

void mainThread() {

	bool hasBeenShaken = false;
	ArbitrerState _actionState = SLEEPING;

	Serial.println(F("Starting..."));

	Sensors::init();
	Moti::init();
	Stabilization::init();

	Moti::start();

	heart.shine(Color::GreenPure);

	while (TRUE) {

		while (Moti::isShaken()) {
			hasBeenShaken = true;
		}

		if (hasBeenShaken) {

			if (_actionState == SLEEPING) {
				_actionState = STABILIZING;
				// Stabilization::start();
				heart.shine(Color::GreenPure);
			}
			else {
				_actionState = SLEEPING;
				// Stabilization::stop();
				heart.shine(Color::RedPure);
			}

			hasBeenShaken = false;
		}
		waitMs(50);
	}
}

void loop() { }

int main(void) {
	init();

	// Serial.begin(115200);
	// while (!Serial);
	//
	// Serial1.begin(115200);
	// while (!Serial1);

	Wire.begin();
	delay(500);

	chBegin(mainThread);

	while(1);

	return 0;
}