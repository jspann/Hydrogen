//
//  Table.h
//  
//
//  Created by James Spann on 3/28/14.
//
//

#ifndef ____Table__
#define ____Table__

#include <iostream>
#include "Variable.h"


class SymbolTable {
    int tableSpaces;//Number of registers in the VM
    
public:
    void initializeTable();
    void addToTable(char,int);
    void printTable();
    int returnValues(int);
    void setValue(Variable, int);
    //void setValue(int loc, int vu);
};


#endif /* defined(____Table__) */
