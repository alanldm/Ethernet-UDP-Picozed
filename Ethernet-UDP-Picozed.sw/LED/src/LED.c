#include "xparameters.h"
#include "xil_io.h"
#include "xil_printf.h"

#define GPIO_BASE  XPAR_AXI_GPIO_0_BASEADDR
#define GPIO_DATA  (GPIO_BASE + 0x0)
#define GPIO_CONFIG   (GPIO_BASE + 0x4)

extern char inbyte(void);

void choice(){
	xil_printf("\n\rWhich LED would you like to toggle?\n\r[1] - LED D17\n\r[2] - LED D18\n\rEnter: ");
}

int main() {
	xil_printf(
	"\n\r __    _____ ____     _____ _____ _____ _____ __    _____ \n\r"
	"|  |  |   __|    \    |_   _|     |   __|   __|  |  |   __|\n\r"
	"|  |__|   __|  |  |    | | |  |  |  |  |  |  |  |__|   __|\n\r"
	"|_____|_____|____/     |_| |_____|_____|_____|_____|_____|\n\r"
	"		                                                   \n\r"
	);


    Xil_Out32(GPIO_CONFIG, 0x00);

    char LED_number;
    u32 state;
    while (1) {
    	choice();

    	LED_number = inbyte();

    	xil_printf("%c\n\r", LED_number);

    	LED_number = LED_number - 48;

    	if(LED_number < 1 || LED_number > 2){
    		xil_printf("Invalid LED!\n\r");
    	} else {
        	state = Xil_In32(GPIO_DATA);

        	state ^= (1 << (LED_number-1));

        	Xil_Out32(GPIO_DATA, state);
    	}
    }

    return 0;
}
