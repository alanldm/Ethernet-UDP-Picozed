#include "xparameters.h"
#include "xil_io.h"
#include "xil_printf.h"

#define GPIO_BASE  XPAR_AXI_GPIO_0_BASEADDR
#define GPIO_DATA  (GPIO_BASE + 0x0)
#define GPIO_TRI   (GPIO_BASE + 0x4)

extern char inbyte(void);

void delay() {
    for (volatile int i = 0; i < 10000000; i++);
}

int main() {
    xil_printf("Starting...\n\r");

    Xil_Out32(GPIO_TRI, 0x00);

    char LED_number;
    u32 state;
    while (1) {
    	xil_printf("Toggle LED: \n\r");

    	LED_number = inbyte();
    	LED_number = LED_number - 49;

    	xil_printf("\nNumber:%i\n\r", LED_number);

    	state = Xil_In32(GPIO_DATA);

    	state ^= (1 << LED_number);

    	Xil_Out32(GPIO_DATA, state);
    }

    return 0;
}
