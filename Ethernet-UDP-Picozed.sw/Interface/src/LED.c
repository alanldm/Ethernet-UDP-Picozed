#include "LED.h"

void LED_options(){
	xil_printf("\x1B[2J\x1B[H");
	xil_printf(" [1] - Toggle LED D17 						\n\r");
	xil_printf(" [2] - Toggle LED D18 						\n\r");
	xil_printf("[ESC] - Return\n\r");
}

int LED_choice(){
	char choice;

	choice = inbyte();

	return choice;
}

void LED_toggle(int choice){
	u32 state;

	choice = choice - 48;

	if(choice < 1 || choice > 2){
		xil_printf("Invalid LED!\n\r");
	} else {
		state = Xil_In32(GPIO_DATA);

		state ^= (1 << (choice-1));

		Xil_Out32(GPIO_DATA, state);
	}
}

void LED(){
	int choice;
	while(1){
		LED_options();

		choice = LED_choice();

		if(choice == 27){
			break;
		} else {
			LED_toggle(choice);
		}
	}

	return;
}
