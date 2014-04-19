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


class SymbolTable {

public:
    void initializeTable();
    void addToTable(char,int);
    void printTable();
    void set_values (int,int);
    int returnValues(int);
    void setValue(int, int);
};


#endif /* defined(____Table__) */
