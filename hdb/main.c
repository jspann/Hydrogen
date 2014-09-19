//
//  main.c
//  
//
//  Created by James Spann on 7/28/14.
//
//
#include <string.h>
#include <stdio.h>

char *filename;
void printversion(){
}


void help(){
    printf("\nAvailable commands\n");
    printf("=================\n");
    printf("-v for version\n");
    printf("./hdb <program name> to add your application to memory\n");
}


int main (int argc, char *argv[]) {
    
    if (argv[1] == NULL){
        help();
    } else{
        if(strcmp(argv[1],"-v")==0){
            
            printversion();
        }else if(!argv[1] == NULL){
            filename=argv[1];
            
            
            
        }else{
            help();
        }
    }
    return 0;
}