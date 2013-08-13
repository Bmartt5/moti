//######################################################################//
//	MOTI SOFTWARE v2.0													//
//	COPYRIGHT WE ARE LEKA! - SOURCE CODE DISTRIBUTED UNDER MIT LICENCE	//
//######################################################################//

/**
 * @file figures.ino
 * @brief figures.ino is used for define the robot behaviours need to draw one figure.
 * @author Luan Ferrari
 * @version 1.0
 */

//###########//
// LIBRARIES //
//###########//

#include "Arduino.h"

#include "Moti.h"

#include "RGBLED.h"

#include <Wire.h>

#include <CommunicationUtils.h>
#include <DebugUtils.h>
#include <FIMU_ADXL345.h>
#include <FIMU_ITG3200.h>
#include <FreeSixIMU.h>


int initialAngle, deviationAngle, fullTurns, instantAngle;

MOTI Moti = MOTI();


/**
 * @class MOTORSPINRIGHTANGLE
 * @brief The MOTORSPINRIGHTANGLE class is used to say for the robot to turn one specific angle in the right direction.
 *
 * This class reads the initial angle and compare with the giroscope for turn the angle specified in the right direction.
 * It uses the algorithm of angle mesure correction to allow turn angles that are higher than one full turn.
 */

void MotorSpinRightAngle(int spin) { // Faire une fonction de spin avec un angle quelconque. 
	
	Moti.checkGyroscope();
	
	fullTurns = int(spin/360);   // Partie entier avec les quantités des tours complet. 
	spin = spin%360;          // Reste avec l'angle mineur que un tour. 

	
	for (int i = 0; i < fullTurns; i++) {    //Faire des tours complet

		initialAngle = Moti.getYPR(0);
		deviationAngle = 0;
		
		while (abs(deviationAngle - 360) > 5) { 	

		Moti.checkGyroscope();	

		if(deviationAngle < 360){ Moti.spinRight(); }
	
		else { Moti.spinLeft(); }

		instantAngle = Moti.getYPR(0);

		if (instantAngle < initialAngle){instantAngle = instantAngle + 360;}     //Compensation for the signal change of the sensor at -180 and 180.
		
		deviationAngle = abs(instantAngle - initialAngle);
	
		}

	
	}


	Moti.checkGyroscope();
	initialAngle = Moti.getYPR(0);
	deviationAngle = 0;
	

	while (abs(deviationAngle - spin) > 5) { 	

		Moti.checkGyroscope();	

		if(deviationAngle < spin){ Moti.spinRight(); }		// During this time it did not reach the value, it continues turning. 
	
		else { Moti.spinLeft(); }			// If for inercie it passes the exact value, it will return.

		instantAngle = Moti.getYPR(0);

		if (instantAngle < initialAngle){instantAngle = instantAngle + 360;}        //Compensation for the signal change of the sensor at -180 and 180.
		deviationAngle = abs(instantAngle - initialAngle);

	}

	Moti.stop();

	}


/**
 * @class MOTORSPINLEFTANGLE
 * @brief The MOTORSPINLEFTANGLE class is used to say for the robot to turn one specific angle in the left direction.
 *
 * This class reads the initial angle and compare with the giroscope for turn the angle specified in the left direction.
 * It uses the algorithm of angle mesure correction to allow turn angles that are higher than one full turn.
 */

void MotorSpinLeftAngle(int spin) {  // Any angle

	Moti.checkGyroscope();
	
	fullTurns = int(spin/360);
	spin = spin%360;

	
	for (int i = 0; i < fullTurns; i++) {

		initialAngle = Moti.getYPR(0);
		deviationAngle = 0;
		
		while (abs(deviationAngle - 360) > 5) { 	

		Moti.checkGyroscope();	

		if(deviationAngle < 360){ Moti.spinLeft(); }
	
		else { Moti.spinRight(); }

		instantAngle = Moti.getYPR(0);

		if (instantAngle > initialAngle){instantAngle = instantAngle - 360;}	//Compensation for the signal change of the sensor at -180 and 180.
		
		deviationAngle = abs(instantAngle - initialAngle);
	
		}

	
	}


	Moti.checkGyroscope();
	initialAngle = Moti.getYPR(0);
	deviationAngle = 0;

	
	while (abs(deviationAngle - spin) > 5) { 	

		Moti.checkGyroscope();	

		if(deviationAngle < spin){ Moti.spinLeft(); }		// During this time it did not reach the value, it continues turning. 
	
		else { Moti.spinRight(); }		// If for inercie it passes the exact value, it will return.

		instantAngle = Moti.getYPR(0);

		if (instantAngle > initialAngle){instantAngle = instantAngle - 360;}		//Compensation for the signal change of the sensor at -180 and 180.
		
		deviationAngle = abs(instantAngle - initialAngle);

	}

	Moti.stop();
	}

/**
 * @class SQUARE
 * @brief The SQUARE class is used to describe for the robot what is the sequence of moviments to draw one square.
 *
 * The square is formed by the sequence of four straight moviments (same distance) followed by one turn of 90 degrees.
 */

void Square(int distance) {			// Figure of one square according to the width.

	Moti.goForward();
	delay(100*distance); 			// The coefficient 100 depends of the linear speed of the motor according to the distance.
	Moti.stop();
	delay(500);
	
	MotorSpinRightAngle(90);	
	
	Moti.goForward();
	delay(100*distance); 			// The coefficient 100 depends of the linear speed of the motor according to the distance.
	Moti.stop();
	delay(500);

	MotorSpinRightAngle(90);
	
	Moti.goForward();
	delay(100*distance); 			// The coefficient 100 depends of the linear speed of the motor according to the distance.
	Moti.stop();
	delay(500);
	
	MotorSpinRightAngle(90);
	
	Moti.goForward();
	delay(100*distance); 			// The coefficient 100 depends of the linear speed of the motor according to the distance.
	Moti.stop();
	delay(500);
	
	MotorSpinRightAngle(90);

	}

/**
 * @class RECTANGLE
 * @brief The RECTANGLE class is used to describe for the robot what is the sequence of moviments to draw one rectangle.
 *
 * The square is formed by the sequence of four straight moviments (same distance 2 by 2) followed by one turn of 90 degrees.
 */

void Rectangle(int distance1, int distance2) {   // Figure of one rectangle according to the width and the length. 

	Moti.goForward();
	delay(100*distance1); 			// The coefficient 100 depends of the linear speed of the motor according to the distance.
	Moti.stop();
	delay(500);
	MotorSpinRightAngle(90);
	Moti.goForward();
	delay(100*distance2); 			// The coefficient 100 depends of the linear speed of the motor according to the distance.
	Moti.stop();
	delay(500);
	MotorSpinRightAngle(90);
	Moti.goForward();
	delay(100*distance1); 			// The coefficient 100 depends of the linear speed of the motor according to the distance.
	Moti.stop();
	delay(500);
	MotorSpinRightAngle(90);
	Moti.goForward();
	delay(100*distance2); 			// The coefficient 100 depends of the linear speed of the motor according to the distance.
	Moti.stop();
	delay(500);
	MotorSpinRightAngle(90);

}

/**
 * @class CROSS
 * @brief The CROSS class is used to describe for the robot what is the sequence of moviments to draw one cross.
 *
 * The cross is formed by four branches
 */

void Cross (int distance) {     // Figure of one cross depending on the size of its branches. 

	Moti.goForward();
	delay(100*distance);
	Moti.goBackward();
	delay(100*distance);
	MotorSpinRightAngle(90);      // The robot runs the size of the branches, go back and turn 90 degrees to start the next branches.
	Moti.goForward();
	delay(100*distance);
	Moti.goBackward();
	delay(100*distance);
	MotorSpinRightAngle(90);
	Moti.goForward();
	delay(100*distance);
	Moti.goBackward();
	delay(100*distance);
	MotorSpinRightAngle(90);
	Moti.goForward();
	delay(100*distance);
	Moti.goBackward();
	delay(100*distance);
	MotorSpinRightAngle(90);

}

/**
 * @class CIRCLE
 * @brief The CIRCLE class is used to describe for the robot what is the sequence of moviments to draw one circle.
 *
 * The circle is formed by the diferences between the wheels speed (doing one angulair speed) that provoke one full turn with one specific radius.
 */

void Circle (int circleRadius, int circleSpeed) {

	circleSpeed = constrain(circleSpeed, Moti.getMotorMinSpeed(), Moti.getMotorMaxSpeed());

	int circleCoefficient = 1 - (0.1*0.1*circleSpeed/255)/circleRadius ;   // Had been considered the distances between the wheels = 0.1 meter and motor linear speed at 255 n considere distance entre roues = 0.1 et vitesse lineaire a 255 such as 0.1 m/s. 

	Moti.checkGyroscope();
	initialAngle = Moti.getYPR(0);
	deviationAngle = 360;

	Moti.spinLeftWheel(circleSpeed, 0);
	Moti.spinRightWheel(circleSpeed * circleCoefficient, 0); 	   // Radius equal distance between wheels * maximun linear speed / (1 - coeff)
	Moti.setMovingState(true);
	delay (1000);

	while (abs(deviationAngle) > 5){

	Moti.checkGyroscope();
	deviationAngle = Moti.getYPR(0) - initialAngle;

	}

	Moti.stop();

}

/**
 * @class SPIRAL
 * @brief The SPIRAL class is used to describe for the robot what is the sequence of moviments to draw one spiral.
 *
 * The spiral is formed by the diferences between the wheels speed (doing one angulair speed) that provoke some full turns with the instantaneous radius rising.
 */

void Spirale (int coeff, int spiralSpeed) {

	spiralSpeed = constrain(spiralSpeed, Moti.getMotorMinSpeed(), Moti.getMotorMaxSpeed());
	coeff = constrain(coeff, 1, 10);

	for (int i = 2; i <= coeff ; i++) {
	Moti.spinLeftWheel(spiralSpeed, 0);
	Moti.spinRightWheel(spiralSpeed * (i*0.1), 0); 	   // Radius equal the distance between wheels * maximun linear speed / (1 - coeff)

	Moti.setMovingState(true);

	delay(2000); }   // Time equal the 2*pi*Radius/Speed, where speed is equal to 0.1*speed/255

	Moti.stop();

}

/**
 * @class BEHAVIOUR
 * @brief The BEHAVIOUR class is used to join the drawings in a desired behaviour.
 */

void Behaviour (){

	Moti.blinkLed(0,0,255,5,250);
	Moti.printRgbColor(0,0,255);
	Square(20);	
	Moti.blinkLed(0,0,255,5,250);
	Moti.printRgbColor(0,0,255);
	Square(60);	

	Moti.blinkLed(255,0,0,5,250);
	Moti.printRgbColor(255, 0, 0);		
	Spirale (7,255);
	Moti.blinkLed(255,0,0,5,250);
	Moti.printRgbColor(255, 0, 0);		
	Spirale (10,255);

	Moti.blinkLed(0,255,0,5,250);
	Moti.printRgbColor(0, 255, 0);
	Cross(30);
	Moti.blinkLed(0,255,0,5,250);
	Moti.printRgbColor(0, 255, 0);		
	Cross(50);

	Moti.blinkLed(0,255,255,5,250);
	Moti.printRgbColor(0,255,255);			
	Rectangle(20,40);	
	Moti.blinkLed(0,0,255,5,250);
	Moti.printRgbColor(0,0,255);
	Rectangle(60,100);	

	Moti.blinkLed(255,0,255,5,250);
	Moti.printRgbColor(255, 0, 255);		
	Circle(40,255);
	Moti.blinkLed(255,0,255,5,250);
	Moti.printRgbColor(255, 0, 255);		
	Circle(70,255);

}


//#######//
// SETUP //
//#######//

void setup() {
	Moti.initVerbose();
}



//######//
// LOOP //
//######//

void loop() {
	
	delay(2000);
	MotorSpinLeftAngle(360);
	delay(2000);
	MotorSpinRightAngle(720);
	delay(2000);
	MotorSpinLeftAngle(1080);
	//Behaviour();

}

