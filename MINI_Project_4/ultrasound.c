#include "gpio.h"
#include "icu.h"
#include "util/delay.h"

uint8 g_edgetoggle = 0;
uint16 g_ontime = 0;
ICU_ConfigType ICU_C1 = {F_CPU_8, RAISING};

void Ultrasonic_edgeProcessing(void)
{
	if (g_edgetoggle == 0)
	{
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(FALLING);
		g_edgetoggle = 1;
	}

	else if (g_edgetoggle == 1)
	{
		g_ontime = ICU_getInputCaptureValue();
		g_edgetoggle = 0;
		ICU_setEdgeDetectionType(RAISING);
	}
}


void Ultrasonic_init(void)
{
	ICU_init(&ICU_C1);

	ICU_setCallBack(Ultrasonic_edgeProcessing);

	GPIO_setupPinDirection(PORTB_ID, PIN5_ID, PIN_OUTPUT);
}

void Ultrasonic_Trigger(void)
{
	GPIO_writePin(PORTB_ID, PIN5_ID, LOGIC_HIGH);
	_delay_us (10);
	GPIO_writePin(PORTB_ID, PIN5_ID, LOGIC_LOW);
}

uint16 Ultrasonic_readDistance(void)
{
	uint16 distance;
	Ultrasonic_Trigger();

	distance = ((float32) g_ontime)/57.97101449;

	return  distance;
}


