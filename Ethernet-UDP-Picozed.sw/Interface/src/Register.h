#ifndef SRC_REGISTER_H
#define SRC_REGISTER_H

#include <stdlib.h>
#include <stdint.h>
#include "xparameters.h"
#include "xil_printf.h"
#include "xil_io.h"

extern char inbyte(void);

#define BASE_ADDR XPAR_REGISTER_BANK_0_S00_AXI_BASEADDR
#define NMBR_REGS 10

void Register_options();
char Register_choice();
void Register_read();
void Register_write();
void Register_bin(u32 data, char value_bin[33]);
void Register_output();
void Register_ascii(u32 data, char value_ascii[5]);
u8 hex2bin(char c);
void Register();

#endif
