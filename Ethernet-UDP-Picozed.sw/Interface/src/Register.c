#include "Register.h"

void Register_options(){
	xil_printf("\x1B[2J\x1B[H");
	xil_printf(" [1] - Read from registers \n\r");
	xil_printf(" [2] - Write to a register \n\r");
	xil_printf("[ESC] - Return			   \n\r");
}

char Register_choice(){
	char choice;

	choice = inbyte();

	return choice;
}

void Register_bin(u32 data, char value_bin[33]){
	for(int i = 31; i >= 0 ; i--){
		value_bin[31 - i] = (data & (1u << i)) ? '1' : '0';
	}

	value_bin[32] = '\0';
}

void Register_ascii(u32 data, char value_ascii[5]){
	for(int i = 0; i < 4; i++){
		value_ascii[i] = (data >> (24 - i*8)) & 0xFF;
	}

	value_ascii[4] = '\0';
}

void Register_read(){
	xil_printf("\x1B[2J\x1B[H");
	xil_printf("---------------------------------------------------------------------------------------------------\n\r");
	xil_printf("| REGISTER |   ADDRESS  | DIRECTION | (MSB)      DATA (BIN)      (LSB) | DATA (HEX) | DATA (ASCII)|\n\r");
	//         "|   regN   | 0xAAAAAAAA |   Output  | 00000000000000000000000000000000 |  AAAAAAAA  |     ABCD    |\n\r"

	u32 addr;
	u32 data;
	char value_ascii[5];
	char value_bin[33];

	for(int i = 0; i < NMBR_REGS; i++){
		addr = BASE_ADDR + 0x4*i;
		data = Xil_In32(addr);
		Register_bin(data, value_bin);
		Register_ascii(data, value_ascii);

		xil_printf("|   reg%i   ", i);
		xil_printf("| 0x%08X ", addr);
		xil_printf("|   %s  ", (i<5 ? "Input " : "Output"));
		xil_printf("| %s ", value_bin);
		xil_printf("|  %08X  ", data);
		xil_printf("|     %s    |\n\r", (data == 0) ? "NULL" : value_ascii);
	}
	xil_printf("---------------------------------------------------------------------------------------------------\n\r");

	xil_printf("[ESC] - Return\n\r");
	while(Register_choice() != '\x1B'){}
}

u8 hex2bin(char c){
	c = toupper(c);

	if(c >= '0' && c <= '9') return c - '0';
	if(c >= 'A' && c <= 'F') return 10 + (c - 'A');
	return 0xFF;
}

void Register_output(){
	xil_printf("\x1B[2J\x1B[H");
	xil_printf(" [1] - reg5\n\r");
	xil_printf(" [2] - reg6\n\r");
	xil_printf(" [3] - reg7\n\r");
	xil_printf(" [4] - reg8\n\r");
	xil_printf(" [5] - reg9\n\r");
	xil_printf("[ESC] - Return\n\r");
}

void Register_write(){
	int choice;
	do{
		Register_output();
		choice = Register_choice();

		if(choice == 27){
			return;
		}

	}while(!(choice >= 49 && choice <= 53));


	char hex;
	u32 value;
	u8 bin;
	for(int i = 0; i<8; i++){
		hex = Register_choice();
		xil_printf("0x %c\n\r", hex);

		bin = hex2bin(hex);

		value = (value << 4) | bin;
	}

	Xil_Out32(BASE_ADDR + 0x4*(choice - 44), value);
}

void Register(){
	char choice;
	xil_printf("\x1B[2J\x1B[H");
	while(1){
		Register_options();
		choice = Register_choice();

		if(choice == '\x1B'){
			break;
		}else if(choice == '1'){
			Register_read();
		}else if(choice == '2'){
			Register_write();
		}
	}

	return;
}
