#include <Arduino.h>
#include <Led.h>


/**
 * @file Led.cpp
 * @author Ladislas de Toldi
 * @version 1.0
 */

//-----------------------------------------------------//
// CONSTRUCTORS
//-----------------------------------------------------//

/**
 * @brief Led Class Constructor
 */
Led::Led(){
	//nothing to do here
}

/**
 * @brief Led Class Constructor
 *
 * @param redPin Red pin
 * @param greenPin Green pin
 * @param bluePin Blue pin
 */
Led::Led(uint8_t redPin, uint8_t greenPin, uint8_t bluePin) : _redPin(redPin), _greenPin(greenPin), _bluePin(bluePin) {
	_RGB[0] = 0;
	_RGB[1] = 0;
	_RGB[2] = 0;

	_tmpRGB[0] = 0;
	_tmpRGB[1] = 0;
	_tmpRGB[2] = 0;
}

//-----------------------------------------------------//
// GENERAL METHODS
//-----------------------------------------------------//

/**
 * @brief Method used to set the value of red, green or blue
 * @param index 0, 1 or 2 for red, green or blue.
 * @param value value for the corresponding led. It must be between 0-255
 */
void Led::setRgb(uint8_t index, uint8_t value){
	chMtxLock(&rgbValuesMutex);
		_RGB[index] = value;
	chMtxUnlock();
}

/**
 * @brief Method used to set red, green and blue all at once
 * @param redValue   the red led value, must be between 0-255
 * @param greenValue the green led value, must be between 0-255
 * @param blueValue  the blue led value, must be between 0-255
 */
void Led::setRgb(uint8_t redValue, uint8_t greenValue, uint8_t blueValue){
	chMtxLock(&rgbValuesMutex);
		_RGB[0] = redValue;
		_RGB[1] = greenValue;
		_RGB[2] = blueValue;
	chMtxUnlock();
}

/**
 * @brief Getter method to get the value of red, green or blue
 * @param index 0, 1 or 2 for red, green or blue.
 * @return returns the corresponding value, an uint8_t between 0-255
 */
uint8_t Led::getRgb(uint8_t index) const{
	return _RGB[index];
}

/**
 * @brief Outputs the _RGB[] values with the RGB Led
 */
void Led::shine() const {
	analogWrite(_redPin, _RGB[0]);
	analogWrite(_greenPin, _RGB[1]);
	analogWrite(_bluePin, _RGB[2]);
}

/**
 * @brief Shine the Led with color you want
 * @param color name of your color
 */
void Led::shine(ColorName color){
	colorSwitcher(color);
	shine();
}

/**
 * @brief Outputs the _RGB[] values with the RGB Led
 *
 * @param redValue red value to output
 * @param greenValue green value to output
 * @param blueValue blue value to output
 */
void Led::shine(uint8_t red, uint8_t green, uint8_t blue){
	setRgb(red, green, blue);
	shine();
}

/**
 * @brief Turns led OFF.
 */
void Led::turnOff(){
	shine(0, 0, 0);
}

/**
 * @brief Color switcher used to get rgb[] values of different colors by their
 * name such as RED, GREEN, BLUE, etc.
 *
 * @param color the name of the color from enum ColorName{}
 */
void Led::colorSwitcher(ColorName color){
	chMtxLock(&rgbValuesMutex);
		switch(color){
			case DARK_RED:
				_RGB[0] = 186;
				_RGB[1] = 48;
				_RGB[2] = 42;
				break;

			case RED:
				_RGB[0] = 255;
				_RGB[1] = 0;
				_RGB[2] = 0;
				break;

			case LIGHT_RED:
				_RGB[0] = 222;
				_RGB[1] = 63;
				_RGB[2] = 89;
				break;

			case PURPLE:
				_RGB[0] = 165;
				_RGB[1] = 67;
				_RGB[2] = 188;
				break;

			case BLUE:
				_RGB[0] = 41;
				_RGB[1] = 133;
				_RGB[2] = 220;
				break;

			case LIGHT_BLUE:
				_RGB[0] = 95;
				_RGB[1] = 184;
				_RGB[2] = 224;
				break;

			case WHITE:
				_RGB[0] = 248;
				_RGB[1] = 253;
				_RGB[2] = 253;
				break;

			case LIGHT_PINK:
				_RGB[0] = 255;
				_RGB[1] = 232;
				_RGB[2] = 225;
				break;

			case YELLOW:
				_RGB[0] = 250;
				_RGB[1] = 211;
				_RGB[2] = 51;
				break;

			case DARK_YELLOW:
				_RGB[0] = 244;
				_RGB[1] = 174;
				_RGB[2] = 51;
				break;

			case ORANGE:
				_RGB[0] = 240;
				_RGB[1] = 143;
				_RGB[2] = 51;
				break;

			case DARK_ORANGE:
				_RGB[0] = 239;
				_RGB[1] = 134;
				_RGB[2] = 59;
				break;

			case LIGHT_GREEN:
				_RGB[0] = 216;
				_RGB[1] = 255;
				_RGB[2] = 56;
				break;

			case GREEN:
				_RGB[0] = 0;
				_RGB[1] = 255;
				_RGB[2] = 0;
				break;

			case RAND:
				_RGB[0] = random(0, 255);
				_RGB[1] = random(0, 255);
				_RGB[2] = random(0, 255);
				break;

			default:
				_RGB[0] = random(0, 255);
				_RGB[1] = random(0, 255);
				_RGB[2] = random(0, 255);
				break;
		}
	chMtxUnlock();

}


//-----------------------------------------------------//
// CONSTANTS
//-----------------------------------------------------//
