#include <iostream>
#include <fstream>
//#import "bool.h"
#include "vm.h"
#include "stack.h"
#include "register.h"
#include "heap.h"

#define KBLU  "\x1B[34m"


bool running = 0;//1 if the vm is running and 0 if it is halted
//using namespace std;
FILE *mainFile;

short int readMagicHeader(FILE *file);
void readMagic(FILE *fle);
void getopcode();
char execute();

void initVM(FILE *fle){
	//Create data structures
	Stack functionStack;
	Register programRegister;
	
	mainFile = fle;
	//Create initial thread

	functionStack.initStack();
	programRegister.initRegister();
	readMagic(fle);

	running = 1;
	while (running){
		char instr = getInstruction();
	}
}

char getInstruction(){
	char temp;
	return fread(&temp,sizeof(char),1,mainFile);
}

int execute(char instr){
	switch(instr){
		case 1://
			break;
		case 2://add
			break;
		case 3://sub
			break;
		case 4://
			break;
		case 5://
			break;
		case 6://
			break;
		case 7://
			break;
		case 8://
			break;
		case 9://
			break;
		case 10://
			break;
		default:
			printf("oh\n");
			//badhalt("invalid operand");
	}
}

void readMagic(FILE *fle){
	char magics[3];
	char temp;
	for (int i = 0; i < 3; i++){
		fread(&temp,sizeof(char),1,fle);
		printf("%hd\n", temp);
		magics[i] = (int)temp;
	}

	if ((magics[0] == 72) && (magics[1] == 89) && (magics[2] == FILE_VERSION)){
		printf("HEY!!!\n");
		fread(&temp,sizeof(char),1,fle);
		printf("%hd\n", temp);
	}else{
		printf("Error: invalid magic\n");
	}


}

void getopcode(){

}

void decode(int x){

}

void badhalt(char* reason){
	//Stop all of the threads
	//Print out error message
#ifdef __APPLE__ && __MACH__
	std::cout << "\033[1;31mError: \033[0m\n" << reason << std::endl;
#else
	std::cout << "Error: " << reason << std::endl;
#endif
	
	exit(0);
}