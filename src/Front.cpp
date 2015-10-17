//
//  Front.c
//  
//
//  Created by James Spann on 3/4/14.
//
//
#include <string.h>
#include <stdio.h>
#include "Front.h"
#include "Parser.h"
#include "Hydrogen.h"
#include "vm.h"
#include "Flags.h"

char *filename;
void printversion(){
	printf("Hydrogen Version %i.%02i\n",MAJOR_VERSION,MINOR_VERSION);
	printf("Hydrogen File Version: %i\n",FILE_VERSION);
	//printf("Hydrogen Version \033[1;31m%i.%02i\033[0m\n",MAJOR_VERSION,MINOR_VERSION);
	//std::cout << "\033[1;31mbold red text\033[0m\n";
}

void printFileVersion(){
	printf("Hydrogen File Version: %i\n",FILE_VERSION);

}

void help(){
	printf("\nAvailable commands\n");
	printf("=================\n");
	printf("-v for version\n");
	printf("-R <filename> for running a file\n");
//    printf("-l for logging output to log.txt\n");
//    printf("-l <filename> for logging output to <filename> \n");
	printf("-? for this screen\n\n");
}


int main (int argc, char *argv[]) {
	
	if (argv[1] == NULL){
		help();
	} else{
		if(strcmp(argv[1],"-v")==0){
			
			printversion();
		}else if(strcmp(argv[1],"-R")==0){
			filename=argv[2];
			
			if (strcmp(argv[3],"-l")==0) {

//                isLog = true;
			}else{
//                isLog = false;
			}
			
			FILE *fp = fopen(filename,"r");
			if( fp ) {
				initVM();
				fclose(fp);
				
				
			} else {
				printf("The file doesn't exist. Make sure you have titled it correctly. \n");
			}
			
			
		}else if(strcmp(argv[1],"-?")==0){
			help();
		}else{
			
			printf("Invalid command. Please enter -? for available commands.\n");
		}
	}
	return 0;
}