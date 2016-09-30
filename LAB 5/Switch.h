// initialize Port D for edge triggered interrupts
// 4 inputs are initialzied PD0-4
void PortD_Init(void);

// captures input from Port D
// changes the value of SWinput
void GPIOPortD_Handler(void);
	
// performs different tasks depending on
// the value of SWinput
void Process_input(void);
