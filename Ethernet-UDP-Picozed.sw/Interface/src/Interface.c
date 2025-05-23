#include <stdlib.h>
#include "xil_printf.h"
#include "LED.h"
#include "Register.h"

extern char inbyte(void);

void project_name();
void project_info();
void clear();
void header();
void options();
void choice();

int main(){

	while(1){
		header();
		options();
		choice();
		clear();
	}

	return 0;
}

void header(){
	clear();
	project_name();
	project_info();
}

void options(){
	xil_printf("\n\r");
	xil_printf("[1] - LED Controller \n\r");
	xil_printf("[2] - Register Bank  \n\r");
	xil_printf("[0] - Exit			 \n\r");
}

void choice(){
	char choice = inbyte();

	xil_printf("%c\n\r", choice);

	if(choice == '1'){
		LED();
	} else if(choice == '2'){
		Register();
	} else if(choice == '0'){
		clear();
		exit(1);
	}
}

void clear(){
	xil_printf("\x1B[2J\x1B[H");
}

void project_info(){
	xil_printf("\n\r");
	xil_printf("Project	: Ethernet/UDP 						\n\r");
	xil_printf("Author	: Alan Lima de Medeiros 			\n\r");
	xil_printf("Tutor   : Matthieu Bezard					\n\r");
	xil_printf("Date	: 22-05-2025						\n\r");
	xil_printf("Version	: 1.0.0								\n\r");
	xil_printf("Board   : Picozed 7015 with Carrier FMC V1  \n\r");
}

void project_name(){
	xil_printf(
			"/  |  /  |/       \\ /       \\ /  |                    	\n\r"
			"$$ |  $$ |$$$$$$$  |$$$$$$$  |$$/   _______   ______  		\n\r"
			"$$ |  $$ |$$ |  $$ |$$ |__$$ |/  | /       | /      \ 		\n\r"
			"$$ |  $$ |$$ |  $$ |$$    $$/ $$ |/$$$$$$$/ /$$$$$$  |		\n\r"
			"$$ |  $$ |$$ |  $$ |$$$$$$$/  $$ |$$ |      $$ |  $$ |		\n\r"
			"$$ \\__$$ |$$ |__$$ |$$ |      $$ |$$ \\_____ $$ \\__$$ |	\n\r"
			"$$    $$/ $$    $$/ $$ |      $$ |$$       |$$    $$/ 		\n\r"
			" $$$$$$/  $$$$$$$/  $$/       $$/  $$$$$$$/  $$$$$$/  		\n\r"
	);
}
