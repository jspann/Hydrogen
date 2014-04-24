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

public:
    void initializeTable();
    void addToTable(char,int);
    void printTable();
    int returnValues(int);
    void setValue(Variable, int);
};


#endif /* defined(____Table__) */
