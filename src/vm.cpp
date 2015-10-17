#include <iostream>
#include <fstream>
//#import "bool.h"
#include "vm.h"
#include "stack.h"
#include "heap.h"

#define KBLU  "\x1B[34m"


bool running = 0;//1 if the vm is running and 0 if it is halted
//using namespace std;

short int readMagicHeader(FILE *file);
void readMagic(FILE *fle);

void initVM(FILE *fle){
	//Create initial thread
	Stack functionStack;
	functionStack.initStack();
	readMagic(fle);

	running = 1;
	//while(1){
		//get instruction

		//get parameters for instruction
	//}
}

void readMagic(FILE *fle){
	/*char magics[3];
	char temp;
	
	fread(&temp,sizeof(char),1,fle);
	printf("%hd %c\n", temp,temp);
	magics[0] = (int)temp;

	fread(&temp,sizeof(short),1,fle);
	printf("%hd\n", temp);
	magics[1] = (int)temp;

	printf("[%d] %c\n", magics[0],magics[0]);
	printf("[%d] %c\n", magics[1],magics[1]);*/
	char magics[3];
	char temp;
	
	fread(&temp,sizeof(char),1,fle);
	printf("%hd %c\n", temp,temp);
	magics[0] = (int)temp;

	fread(&temp,sizeof(char),1,fle);
	printf("%hd\n", temp);
	magics[1] = (int)temp;

	printf("[%d] %c\n", magics[0],magics[0]);
	printf("[%d] %c\n", magics[1],magics[1]);
	for (int i = 0; i < 3; i++){

		// magics[i] = temp;
		// printf("%d %d %d\n", i, (int)magics[i],(int)temp);
	}

	if ((magics[0] == 72) && (magics[1] == 89)){// && (three == FILE_VERSION)){
		printf("HEY!!!\n");
	}else{
		printf("Error: invalid magic\n");
	}

}
// short int readMagic(FILE *file){
// 	short int instr;
	
// 	printf("%d\n", instr);
// 	return (int)instr;
// }

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