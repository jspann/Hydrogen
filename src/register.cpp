#include <iostream>
#include "register.h"
using namespace std;

Register::Register(){

}

void Register::initRegister(){
	usedSpaces = 0;
}

void Register::dumpRegister(){
	cout << "| Place | Type | Value |" << endl;
	for (int u = 0; u<usedSpaces; u++) {
		cout << "|   "<< u <<"   |  "<< types[u] <<"   |   "<< values[u] <<"   |" << endl;
	}
		cout << "|-------|------|-------|" << endl;
}



void Register::setValueAt(int loc, int vu){
	values[loc] = vu;
}

int Register::returnValue(int atLocation) {
    if (atLocation > MAX_SPACES || atLocation < 0){
        cout << "Invalid memory location" << endl;
        return 0;
    }
    
    return values[atLocation];
}

void Register::killRegister(){
	
}

void Register::addValue(int value){
	values[usedSpaces] = value;
	usedSpaces++;
}