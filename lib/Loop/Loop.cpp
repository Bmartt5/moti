#include <Arduino.h>
#include <Timer.h>

/**
 * @file Timer.cpp
 * @author Ladislas de Toldi
 * @version 1.0
 */

//-----------------------------------------------------//
// GENERAL
//-----------------------------------------------------//

/**
 * @brief Initialize the loop delay
 */
void Timer::init(){
	resetLoopDelay();
	resetSleepDelay();
}

/**
 * @brief Check if a delay has passed with +/- delta
 */
bool Timer::delay(uint64_t delay, uint64_t delta){
	if (millis() % delay <= delta || millis() % delay >= -delta){
		return true;
	}
	else
		return false;
}

/**
 * @brief Check if a delay has passed
 */
bool Timer::delay(uint64_t delay){
	if (millis() % delay){
		return true;
	}
	else
		return false;
}

//-----------------------------------------------------//
// SETTER
//-----------------------------------------------------//

/**
 * @brief Setter method for _loopDelay
 *
 * Once set, the _loopDelay can be accessed by calling getLoopDelay()
 * @param value the value you want to assign to _loopDelay.
 */
void Timer::setLoopDelay(int value){
	_loopDelay = value;
}

/**
 * @brief Setter method for _sleepDelay
 *
 * Once set, the _sleepDelay can be accessed by calling getSleepDelay()
 * @param value the value you want to assign to _sleepDelay.
 */
void Timer::setSleepDelay(int value){
	_sleepDelay = value;
}

//-----------------------------------------------------//
// GETTER
//-----------------------------------------------------//

/**
 * @brief Getter method for _loopDelay
 *
 * It is used to modify the speed of the loop: higher value means slower robot.
 * @return the value of _loopDelay
 */
int Timer::getLoopDelay(){
	return _loopDelay;
}

/**
 * @brief Getter method for _sleepDelay
 *
 * It is used to as a counter to determine the moment the robot should got to sleep. Higher value means longer awaken state.
 * @return the value of _sleepDelay
 */
int Timer::getSleepDelay(){
	return _sleepDelay;
}

//-----------------------------------------------------//
// RESET
//-----------------------------------------------------//

/**
 * @brief Reset method for _loopDelay to initial value
 */
void Timer::resetLoopDelay(){
	_loopDelay = DEFAULT_LOOP_DELAY;
}

/**
 * @brief Reset method for _sleepDelay to initial value
 */
void Timer::resetSleepDelay(){
	_sleepDelay = DEFAULT_SLEEP_DELAY;
}



