/*
 * ultrasonic.h
 *
 *  Created on: Mar 1, 2024
 *
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include "std_types.h"
/*
 * Description: Function to initialize the ICU as required , set icu callback function and set direction of
 * trigger pin
 */
void Ultrasonic_init(void);
/*
 * Description: Function to Send the Trigger pulse to the ultrasonic.
 */
void Ultrasonic_Trigger(void);

/*
 * Description : Function to Send the trigger pulse by using Ultrasonic_Trigger function.
 Start the measurements by the ICU from this moment
 */
uint16 Ultrasonic_readDistance(void);
/*
 * Description : Function to Set the ICU call back function .
 */
void Ultrasonic_edgeProcessing(void);
#endif /* ULTRASONIC_H_ */
