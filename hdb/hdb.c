//
//  hdb.c
//  
//
//  Created by James Spann on 7/28/14.
//
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "hdb.h"
char *filename;
int contin = 1;
void printversion(){
	printf("Hydrogen Debugger 1.0 by James Spann");
}


void help(){
	printf("\nAvailable commands:\n\n");
	printf("attach <hydro file>    -  adds the program to memory\n");
	printf("run    -  runs the program in memory\n");
	printf("quit    -  quits the program\n");
}


int main (int argc, char *argv[]) {
	while (contin == 1) {
		enterCommands();
	}
	return 0;
}

void enterCommands(){
	char str1[20];
	char str2[20];
	

	printf("(hdb) ");   
	printf("\"%s\"",str2);
	printf("%luL%lu",sizeof(str1),strlen(str1));
	printf("[%luL%lu]",sizeof(str2),strlen(str2));

	if (strcmp(str1,"quit")==0) {
		contin = 0;
	}else if (strcmp(str1,"attach")==0) {
		if (str2 != '\0') {
			printf("nothing");
		}else{
			printf("something");
		}
		filename = str2;
	}else if (strcmp(str1,"start")==0) {
		system("hydro -R ");
	}else if (strcmp(str1,"help")==0) {
		help();
	}else if (strcmp(str1,"clear")==0) {
		system("clear");
	}else{
		printf("Invalid command\n");
	}
}