//
//  Parser.cpp
//  
//
//  Created by James Spann on 4/23/14.
//
//

#include <fstream>

#include "Parser.h"
#include "vm.h"
#include "Variable.h"

using namespace std;

int addToInt(int origi, int val);

string operand;
bool isVariable;
int currentInt;
Variable parameters[5];
SymbolTable rect;

void parse(char* fname){
    rect.initializeTable();
    char ch;
    int numParams;
    int paramPlace = 0;
    currentInt = 0;
    
    fstream fin(fname, fstream::in);
    
    while (fin >> noskipws >> ch) {
        if (isalpha(ch)) {
            operand += ch;
        }else if (isdigit(ch)) {
            int lucy = ch - '0';
            currentInt = addToInt(currentInt,lucy);
            
        }else{
            switch (ch) {
                case ' ':
                    
                    break;
                case ',':
                    
                    Variable t;
                    t.value = currentInt;
                    
                    t.datatype = (isVariable) ? (1) : (0);
                    
                    parameters[paramPlace] = t;
                    paramPlace++;
                    

                    
                    currentInt = 0;
                    isVariable = false;
                    break;
                case '$':
                    isVariable = true;
                    break;
                case '\n':
                    
                    
                    if (operand.compare("defi") == 0) {
                        rect.addToTable('i',currentInt);
                    }else if (operand.compare("add") == 0) {
                        int jt = 0;
                        
                        if (paramPlace != 1 && paramPlace != 0) {
                            
                            for (int d = 1; d < paramPlace; d++) {
                                if (parameters[d].datatype == 1){
                                    jt +=rect.returnValues(parameters[d].value);
                                }else{
                                    jt +=parameters[d].value;
                                }
                                
                            }
                            
                        }
                        

                        
                        rect.setValue(parameters[0],jt);
                    }else if (operand.compare("call") == 0) {
                        
                    }else if (operand.compare("call") == 0) {
                        
                    }else{
                        cout << "Unknown operand: " << operand << endl;
                        cout << "Halting" << endl;
                        exit(1);
                    }
                    

                    
                    
                    currentInt=0;
                    paramPlace = 0;
                    operand = "";
                    break;
                default:
                    cout <<"Parse error";
            }
        }

    }
    rect.printTable();

}




int addToInt(int origi, int val){
    return (origi * 10)+val ;
}
