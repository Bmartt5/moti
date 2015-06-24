/*
   Copyright (C) 2013-2014 Ladislas de Toldi <ladislas at weareleka dot com>
   and Leka <http://weareleka.com>

   This file is part of Moti, a spherical robotic smart toy for autistic children.

   Moti is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Moti is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Moti. If not, see <http://www.gnu.org/licenses/>.
   */

/**
 * @file Communication.cpp
 * @author Ladislas de Toldi and Flavien Raynaud
 * @version 1.0
 */

#include "Communication.h"

#define serial Serial1

namespace Communication {

	/**
	 * @brief Writes motors data to the serial
	 */
	void sendMotorData(void) {
		serial.print(F("M,"));  /* M like Motors */
		serial.print(DriveSystem::getRightMotorDirection());
		serial.print(F(","));
		serial.print(DriveSystem::getRightMotorSpeed());
		serial.print(F(","));
		serial.print(DriveSystem::getLeftMotorDirection());
		serial.print(F(","));
		serial.print(DriveSystem::getLeftMotorSpeed());
	}


	/**
	 * @brief Writes leds data to the serial
	 */
	void sendLedData(void) {
		Color color = Light::getColor(HEART);

		serial.print(F("L,")); /* L like Leds */
		serial.print(Light::getState(HEART));
		serial.print(F(","));
		serial.print(color.getR());
		serial.print(F(","));
		serial.print(color.getG());
		serial.print(F(","));
		serial.print(color.getB());
	}


	/**
	 * @brief Writes sensors data to the serial
	 */
	void sendSensorData(void) {
		Serial.print(F("S,"));
		Serial.print(Sensors::getAccX());
		Serial.print(F(","));
		Serial.print(Sensors::getAccY());
		Serial.print(F(","));
		Serial.print(Sensors::getAccZ());
		Serial.print(F(","));
		Serial.print(Sensors::getGyrYDeg());
		Serial.print(F(","));
		Serial.print(Sensors::getGyrPDeg());
		Serial.print(F(","));
		Serial.println(Sensors::getGyrRDeg());
	}


	/**
	 * @brief Writes motors, leds and sensors data to the serial
	 */
	void sendAllData(void) {
		serial.print(F("A,")); /* A like All */
		serial.print(millis());
		serial.print(F(";"));

		sendMotorData();
		serial.print(F(";"));
		sendLedData();
		serial.print(F(";"));
		sendSensorData();
		serial.println(F(""));
		serial.flush();
	}
}
