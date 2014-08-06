#include <iostream>
#include <fstream>
#include "vm.h"
#include "Table.h"

#define KBLU  "\x1B[34m"


int running = 1;//1 if the vm is running and 0 if it is halted
using namespace std;

void initVM(){
    //Create initial thread
    //Get how much memory is available for use and platform info (Clock Speed, io ports, etc.)
}

void badhalt(std::string reason){
    //Stop all of the threads
    //Print out error message
#ifdef __APPLE__ && __MACH__
    cout << "\033[1;31mError: \033[0m\n" << reason << endl;
#else
    std::cout << "Error: " << reason << endl;
#endif
    
    exit(0);
}