#include <iostream>
#include <fstream>
//#import "bool.h"
#include "vm.h"
#include "stack.h"
#include "heap.h"

#define KBLU  "\x1B[34m"


bool running = 1;//1 if the vm is running and 0 if it is halted
//using namespace std;


void loadFile(char* filename){

}

void initVM(){
	//Create initial thread
	Stack functionStack;
	functionStack.initStack();

	//Check magic numbers

	while(1){
		//get instruction
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