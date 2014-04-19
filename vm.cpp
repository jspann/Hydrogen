#include <iostream>
#include <fstream>
#include "vm.h"
#include "Table.h"

#define KBLU  "\x1B[34m"


int running = 1;//1 if the vm is running and 0 if it is halted
using namespace std;
string operand;
bool isVariable;
int currentInt;
int parameters[5];


void execute(char* fname){
    SymbolTable rect;
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
                    numParams = isOperand();
                    
                    break;
                case ',':

                    parameters[paramPlace] = currentInt;
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
                                jt +=parameters[d];
                            }
                            
                        }
                        
                        if (isVariable) {
                            jt += rect.returnValues(currentInt);
                        }
                        
                        
                        rect.setValue(parameters[0],jt);
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
/*
 Operands:
 add <where it will be stored>,<first value>,<second value>
 defi <value>
 sub <where it will be stored>,<first value>,<second value>
 hlt
*/

int isOperand(){
    if (operand.compare("defi") == 0) {
        return 1;
    }else if (operand.compare("add") == 0 || operand.compare("sub") == 0) {
        return 3;
    }else if (operand.compare("hlt") == 0||operand.compare("halt") == 0) {
        return 0;
    }else{
        cout <<"Invalid operand: \""<< operand << "\"" << endl;
        return -1;
    }
}



int addToInt(int origi, int val){
    return (origi * 10)+val ;
}

void runCode(){
    
}