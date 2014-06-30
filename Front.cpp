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

char *filename;
void printversion(){
    printf("Hydrogen Version %i.%02i\n",MAJOR_VERSION,MINOR_VERSION);
    //printf("Hydrogen Version \033[1;31m%i.%02i\033[0m\n",MAJOR_VERSION,MINOR_VERSION);
    //std::cout << "\033[1;31mbold red text\033[0m\n";
}

void printFileVersion(){
    printf("Hydrogen File Version: ");

}

void help(){
    printf("\nAvailable commands\n");
    printf("=================\n");
    printf("-v for version\n");
    printf("-fv for file version\n");
    printf("-R for running a file\n");
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
            
            FILE *fp = fopen(filename,"r");
            if( fp ) {
                fclose(fp);
                parse(filename);
                
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