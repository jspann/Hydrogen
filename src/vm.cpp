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
unsigned int getMemoryLocation();
int execute(unsigned int instr);

void initVM(FILE *fle){
	//Create data structures
	checkenv();
	mainFile = fle;
	//Create initial thread

	functionStack.initStack();
	programRegister.initRegister();
	readMagic(fle);

	running = 1;
	while (running){
		unsigned int instr = getInstruction();//fetch
		// printf("HD QUALITY [%hd]\n", instr);
		// printf("UNSIGNED EDITION [%u]\n", instr);
		execute(instr);//decode and execute
		//debugger pause check
	}
	printf("-----------------\n");
	programRegister.killRegister();
	functionStack.killStack();
}

unsigned int getInstruction(){
	int temp;
	fread(&temp,sizeof(unsigned int),1,mainFile);
	return temp;
}

unsigned int getMemoryLocation(){
	unsigned int loc;
	bool isRef = isReference();
	fread(&loc,sizeof(unsigned int),1,mainFile);
	if (isRef){
		return loc;
	}else{
		// badhalt("Reference error");
	}
	return -1;
}

unsigned int getParameterValue(){
	unsigned int value;
	bool isRef = isReference();
	fread(&value,sizeof(unsigned int),1,mainFile);
	printf("parameter: %d\n", value);
	if (isRef){
		int t = programRegister.returnValue(value);
		return t;
	}
	return value;
}

bool isReference(){
	char flag;
	fread(&flag,sizeof(char),1,mainFile);
	// cout << "flaG:"<<flag<<endl;
	if (flag == 0){//not a reference
		printf("FALSE FLAG\n");
		return false;	
	}
	//otherwise
	printf("TRUE FLAG\n");
	return true;
}

int execute(unsigned int instr){
	printf("OPCODE: [%d]\n", instr);
	if (instr == 0){//hlt
		running = 0;//stop looking for new cycles
	}else if (instr == 1){
		//moving one variable to another variable
		//get parameter
		unsigned int loc = getMemoryLocation();
		unsigned int val = getParameterValue();
		programRegister.setValueAt(loc, val);
	}else if (instr == 2){//add
		unsigned int loc = getMemoryLocation();
		unsigned int val1 = getParameterValue();
		unsigned int temp = programRegister.returnValue(loc)+val1;
		programRegister.setValueAt(loc, temp);
	}else if (instr == 3){//sub
	}else if (instr == 4){//
	}else if (instr == 5){//
	}else if (instr == 6){//
	}else if (instr == 7){//
	}else if (instr == 8){//
	}else if (instr == 9){//
	}else if (instr == 10){//
	}else if (instr == 11){//defi
		unsigned int t = getParameterValue();//will always be value
		cout << "t is: " << t <<endl;
		printf("%ud\n", t);
		programRegister.addValue(t);
	}else if (30){//dmp
		programRegister.dumpRegister();
	}else{
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
		magics[i] = (int)temp;
	}

	if ((magics[0] == 72) && (magics[1] == 89) && (magics[2] == FILE_VERSION)){
		//Magic Values are all correct
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

void checkenv(){
	if (sizeof(char) != 1){
		badhalt("1 byte read structure invalid");
	}

	if (sizeof(unsigned int) != 4){
		badhalt("4 byte read structure invalid");
	}

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