#include "xparameters.h"
#include "xil_io.h"
#include "xil_printf.h"

#define GPIO_BASE  XPAR_REGISTER_BANK_0_S00_AXI_BASEADDR
#define REG6_ADDR  (GPIO_BASE + 0x18)

extern char inbyte(void);

int main() {

	while(1){
		u32 name = 0x416C616E;
		Xil_Out32(REG6_ADDR, name);
	}

    return 0;
}
