#ifndef LEKA_MOTI_ARDUINO_LED_H_
#define LEKA_MOTI_ARDUINO_LED_H_

/**
 * @file Led.h
 * @author Ladislas de Toldi
 * @version 1.0
 */

#include <Arduino.h>

enum ColorName {
		DARK_RED, RED, LIGHT_RED, PURPLE, BLUE, LIGHT_BLUE, WHITE, LIGHT_PINK, YELLOW, DARK_YELLOW, ORANGE, DARK_ORANGE, LIGHT_GREEN, GREEN, RAND
	};


/**
 * @class Led
 * @brief Led class gathers all the LED functions for Moti.
 */
class Led {

	public:

		Led(uint8_t redPin, uint8_t greenPin, uint8_t bluePin);

		Led();

		void init();

		//	SET CONSTANTS
		void setMaxBrightness(int value);
		void setRedMaxBrightness(int value);
		void setGreenMaxBrightness(int value);
		void setBlueMaxBrightness(int value);


		//	GET CONSTANTS
		int getMaxBrightness();
		int getRedMaxBrightness();
		int getGreenMaxBrightness();
		int getBlueMaxBrightness();


    	//	RESET CONSTANTS
		void resetMaxBrightness();
		void resetRedMaxBrightness();
		void resetGreenMaxBrightness();
		void resetBlueMaxBrightness();


		//	LED
		void colorSwitcher(ColorName color);

		void setRgb(int8_t index, int value);
		void setRgb(int redValue, int greenValue, int blueValue);
		void setRed(int value);
		void setGreen(int value);
		void setBlue(int value);

		uint8_t getRgb(uint8_t index);
		uint8_t getRed();
		uint8_t getGreen();
		uint8_t getBlue();

		void printRgb();
		void printRgb(ColorName color);
		void printRgb(int red, int green, int blue);

		void blinkAsync(ColorName color, int numberOfBlinks, uint16_t timeBtwBlink);
		void blinkAsync(int red, int green, int blue, int numberOfBlinks, uint16_t timeBtwBlink);

		void blinkSync(ColorName color, int numberOfBlinks, uint16_t timeBtwBlink);
		void blinkSync(int red, int green, int blue, int numberOfBlinks, uint16_t timeBtwBlink);

		void fadeLedTo(ColorName color);

		void turnOff();
		void turnOn();


	private:

		//	VARIABLES
		
		uint64_t previousMillis = 0;
		int i = 0, j = 0, k = 0;

		int16_t rgb[3], rgbBuffer[3];

		uint8_t redPin;
		uint8_t greenPin;
		uint8_t bluePin;

		uint8_t _ledMaxBrightness;
		uint8_t _redMaxBrightness;
		uint8_t _greenMaxBrightness;
		uint8_t _blueMaxBrightness;

		bool state;

		//	CONSTANTS
		static const uint8_t DEFAULT_LED_MAX_BRIGHTNESS   = 255;
		static const uint8_t DEFAULT_RED_MAX_BRIGHTNESS   = 255;
		static const uint8_t DEFAULT_GREEN_MAX_BRIGHTNESS = 255;
		static const uint8_t DEFAULT_BLUE_MAX_BRIGHTNESS  = 255;

		//	DEFAULT LED PINS
		static const uint8_t DEFAULT_RED_PIN   = 8;
		static const uint8_t DEFAULT_GREEN_PIN = 9;
		static const uint8_t DEFAULT_BLUE_PIN  = 10;
};

#endif