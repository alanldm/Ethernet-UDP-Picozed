#ifndef SRC_LED_H
#define SRC_LED_H

#include "xparameters.h"
#include "xil_printf.h"
#include "xil_io.h"

extern char inbyte(void);

#define GPIO_BASE   XPAR_AXI_GPIO_0_BASEADDR
#define GPIO_DATA   (GPIO_BASE + 0x0)
#define GPIO_CONFIG (GPIO_BASE + 0x4)

void LED_options();
int LED_choice();
void LED_toggle(int choice);
void LED();

#endif
