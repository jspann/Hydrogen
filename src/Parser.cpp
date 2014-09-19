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
                    /*for (int h = 0; h<5; h++) {
                        cout << h << ": " << parameters[h].datatype << "/" << parameters[h].value << endl;
                        
                    }
                    cout << endl;*/
                    
                    if (operand.compare("defi") == 0) {
                        //rect.addToTable('i',currentInt);
                        rect.addToTable('i',parameters[0].value);
                    }else if (operand.compare("defb") == 0) {
                        rect.addToTable('b',parameters[0].value);
                    }else if (operand.compare("defc") == 0) {
                        rect.addToTable('l',parameters[0].value);
                    }else if (operand.compare("const") == 0) {
                        rect.addToTable('c',currentInt);
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
                    }else if (operand.compare("sub") == 0) {
                    }else if (operand.compare("mod") == 0) {
                    }else if (operand.compare("mult") == 0) {
                    }else if (operand.compare("call") == 0) {
                        //Get method name, parameters
                        //Save program counter here
                        //Go to the method section and invoke a new parser and an HStack (in future versions optimized programs will tell the vm if an HStack is needed)
                        //run that code
                        //on return, destroy HStack, move back to program counter and coninue program
                    }else if (operand.compare("mov") == 0) {
                    }else if (operand.compare("inc") == 0) {
                        rect.setValue(parameters[0],rect.returnValues(parameters[0].value) + 1);
                    }else if (operand.compare("dec") == 0) {
                        rect.setValue(parameters[0],rect.returnValues(parameters[0].value) - 1);
                    }else if (operand.compare("hlt") == 0) {
                        rect.printTable();
                        exit(0);
                    }else{
                        cout << "Unknown operand: " << operand << endl;
                        cout << "Halting" << endl;
                        exit(1);
                    }
                    

                    
                    
                    currentInt=0;
                    paramPlace = 0;
                    operand = "";
                    
                    //parameters[0] = 0;
                    memset(parameters, 0, sizeof(parameters)) ;
                    break;
                default:
                    cout <<"Parse error";
            }
        }

    }
    rect.printTable();
    cout << "son" << endl;

}





int addToInt(int origi, int val){
    return (origi * 10)+val ;
}
