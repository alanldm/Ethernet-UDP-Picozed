#include "xparameters.h"
#include "xil_io.h"
#include "xil_printf.h"

#define GPIO_BASE  XPAR_REGISTER_BANK_0_S00_AXI_BASEADDR
#define REG6_ADDR  (GPIO_BASE + 0x18)

extern char inbyte(void);

void delay(){for(volatile int i = 0; i<200000000; i++){}}

int main() {

	u32 send = 0x416C616E;
	u32 message;

	char receive[5];
	while(1){

		Xil_Out32(REG6_ADDR, send);

		message = Xil_In32(GPIO_BASE+0x4);

		memcpy(receive, &message, 4);
		receive[4] = '\0';

		xil_printf("Message: %s\r\n", receive);

		delay();
	}

    return 0;
}
