#include <iostream>
#include <fstream>
//#import "bool.h"
#include "vm.h"
#include "stack.h"
#include "register.h"
#include "heap.h"

#define KBLU  "\x1B[34m"


bool running = 0;//1 if the vm is running and 0 if it is halted
using namespace std;
Stack functionStack;
Register programRegister;

FILE *mainFile;

short int readMagicHeader(FILE *file);
void readMagic(FILE *fle);
unsigned int getInstruction();
bool isReference();
void getopcode();
unsigned int getParameterValue();
int execute(char instr);

void initVM(FILE *fle){
	//Create data structures
	
	mainFile = fle;
	//Create initial thread

	functionStack.initStack();
	programRegister.initRegister();
	readMagic(fle);

	running = 1;
	while (running){
		unsigned int instr = getInstruction();//fetch
		printf("HD QUALITY [%hd]\n", instr);
		printf("UNSIGNED EDITION [%u]\n", instr);
		execute(instr);//decode and execute
		//debugger pause check
	}
	printf("-----------------\n");
	programRegister.killRegister();
	functionStack.killStack();
}

unsigned int getInstruction(){
	int temp;
	fread(&temp,sizeof(int),1,mainFile);
	return temp;
}

unsigned int getParameterValue(){
	//check if variable/reference == True
		//return 
	//Return value
	unsigned int value;
	if (isReference()){
		fread(&value,sizeof(unsigned int),1,mainFile);
		int t = programRegister.returnValue(value);
		return t;
	}
	return value;
}

bool isReference(){
	char flag;
	fread(&flag,sizeof(char),1,mainFile);
	cout << "flaG:"<<flag<<endl;
	if (flag == 0){//not a reference
		return false;	
	}
	//otherwise
	return true;
}

int execute(char instr){
	printf("as an int: [%d]\n", instr);
	switch(instr){
		case 0://hlt
			running = 0;//stop looking for new cycles
			break;
		case 1://moving one variable to another variable
			//get parameter

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
	return 0;
}

void readMagic(FILE *fle){
	char magics[3];
	char temp;
	for (int i = 0; i < 3; i++){
		fread(&temp,sizeof(char),1,mainFile);
		printf("%hd\n", temp);
		magics[i] = (int)temp;
	}

	if ((magics[0] == 72) && (magics[1] == 89) && (magics[2] == FILE_VERSION)){
		printf("HEY!!!\n");
	}else{
		printf("Error: invalid magic\n");
	}
}

char readVariable(){
	return 10;
}

char readNumber(){
	return 12;
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