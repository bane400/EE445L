// Initiazlizes Port D for Switch input
// Handles input for music playback

#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"

uint8_t SWinput;

typedef struct{
	uint16_t wavePos;
	uint16_t noteTime;
	uint8_t currentInstrument;
}Player;



void PortD_Init(void){								//Initialize PD0-3
	SYSCTL_RCGCGPIO_R |= 0x08;
	SWinput = 0;
	GPIO_PORTD_DIR_R &= ~0x0F;					// make PD0-3 inputs
	GPIO_PORTD_DEN_R |= 0x0F;						// enable digital I/O on PD0-3
	GPIO_PORTD_IS_R &= ~0x0F;						// PD0-3 is edge sensitive
	GPIO_PORTD_IBE_R &= ~0x0F;					// PD0-3 is not both edges
	GPIO_PORTD_IEV_R |= 0x0F;						// PD0-3 is rising edge sensitive
	GPIO_PORTD_ICR_R = 0x0F;						// clear flags for PD0-3
	GPIO_PORTD_IM_R |= 0x0F;						// arm interrrupts on PD0-3
																			// set interrupt priority to 2
	NVIC_PRI0_R = (NVIC_PRI0_R&0x00FFFFFF)|0x40000000;
	NVIC_EN0_R = 1<<19;
}

void GPIOPortD_Handler(void){
	if(GPIO_PORTD_RIS_R == 0x01){
		GPIO_PORTD_ICR_R = 0x01;
		// do stuff
	}
	if(GPIO_PORTD_RIS_R == 0x02){
		GPIO_PORTD_ICR_R = 0x02;
		// do stuff
	}
	if(GPIO_PORTD_RIS_R == 0x04){
		GPIO_PORTD_ICR_R = 0x04;
		// do stuff
	}
	if(GPIO_PORTD_RIS_R == 0x08){
		GPIO_PORTD_ICR_R = 0x08;
		// do stuff
	}
}

void Process_Input(void){
	// read SWinput and react accordingly
}
