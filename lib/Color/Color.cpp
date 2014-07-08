/*
Copyright (C) 2013-2014 Ladislas de Toldi <ladislas at weareleka dot com> and Leka <http://weareleka.com>

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

#include "Color.h"


/**
 * @file Color.cpp
 * @author Ladislas de Toldi
 * @version 1.0
 */


const Color Color::Black = Color(0, 0, 0);
const Color Color::White = Color(255, 255, 255);
const Color Color::RedPure = Color(255, 0, 0);
const Color Color::GreenPure = Color(0, 255, 0);
const Color Color::BluePure = Color(0, 0, 255);
const Color Color::DarkRed = Color(186, 48, 42);
const Color Color::LightRed = Color(222, 63, 89);
const Color Color::Purple = Color(165, 67, 188);
const Color Color::LightBlue = Color(95, 184, 224);
const Color Color::LightPink = Color(255, 232, 225);
const Color Color::Yellow = Color(250, 211, 51);
const Color Color::DarkYellow = Color(244, 174, 51);
const Color Color::Orange = Color(240, 143, 51);
const Color Color::DarkOrange = Color(239, 134, 59);
const Color Color::LightGreen = Color(216, 255, 56);	


Color::Color() {
	_r = _g = _b = 0;
}

Color::Color(int16_t r, int16_t g, int16_t b) {
	_r = r;
	_g = g;
	_b = b;
}

void Color::getRGB(int16_t* r, int16_t* g, int16_t* b) {
	*r = _r;
	*g = _g;
	*b = _b;
}

int16_t Color::getR(void) {
	return _r;
}

int16_t Color::getG(void) {
	return _g;
}

int16_t Color::getB(void) {
	return _b;
}

void Color::setRGB(int16_t r, int16_t g, int16_t b) {
	_r = r;
	_g = g;
	_b = b;
}
