//
//  Table.cpp
//  
//
//  Created by James Spann on 3/28/14.
//
//

#include "Table.h"
#define KBLU  "\x1B[34m"

int Svalues[40];
char Stypes[40];
int usedSpaces;//number of variables in table


using namespace std;

void SymbolTable::initializeTable(){
    usedSpaces = 0;
}

void SymbolTable::addToTable(char type,int v){
    //type i=integer c=char
    //v is for value
    Stypes[usedSpaces] = type;
    Svalues[usedSpaces] = v;
    usedSpaces++;

}

void SymbolTable::setValue(int loc, int vu){
    Svalues[loc] = vu;
}

void SymbolTable::printTable(){
    cout << "| Place | Type | Value |" << endl;
    for (int u = 0; u<usedSpaces; u++) {
        cout << "|   "<< u <<"   |  "<< Stypes[u] <<"   |   "<< Svalues[u] <<"   |" << endl;
    }
        cout << "|-------|------|-------|" << endl;
}

int SymbolTable::returnValues(int atLocation) {
    if (atLocation > 40){
        cout << "Invalid memory location" << endl;
        return 0;
    }
    
    return Svalues[atLocation];
}