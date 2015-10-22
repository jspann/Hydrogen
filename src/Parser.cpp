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
#include "Hydrogen.h"

using namespace std;

int addToInt(int origi, int val);

string operand;
bool isVariable;
int currentInt;
Variable parameters[5];
SymbolTable rect;

int methodOff = 0;

char ch;//place in file

//Header stuff
int pVal = 0;//value in header
int tempStore = 0;//Where we store integers as we get them from the file
ifstream fin;

int checkMagic(){
    //Returns 1 for invalid magic numbers
    //Returns 0 for correct magic numbers

    //char
    return 0;
}






























































































void parse(char* fname){
    rect.initializeTable();
    //originally here
    int numParams;
    int paramPlace = 0;
    currentInt = 0;
    
    //fstream fin(fname, fstream::in);
    
    fin.open(fname, ios::in);

    //Get the header
    
    headparse();
    
    
    
    
    //while (fin >> noskipws >> ch) {
    while(fin.get(ch)){
//        cout << "%" << ch << endl;
        if (isalpha(ch)) {
            operand += ch;
        }else if (isdigit(ch)) {
            int lucy = ch - '0';
            currentInt = addToInt(currentInt,lucy);
            //cout << ch << endl;
            
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
                    if (operand.compare("defi") == 0) {//Defining an integer
                        if (parameters[0].datatype == 1) {
                            rect.addToTable('i',rect.returnValues(parameters[0].value));
                        }else{
                            rect.addToTable('i',parameters[0].value);
                        }
                        
                    }else if (operand.compare("defb") == 0) {//Defining a bool
                        if (parameters[0].datatype == 1) {
                            rect.addToTable('b',rect.returnValues(parameters[0].value));
                            
                        }else{
                            rect.addToTable('b',parameters[0].value);
                        }
                        
                    }else if (operand.compare("defc") == 0) {//Defining a char
                        if (parameters[0].datatype == 1) {
                            rect.addToTable('l',rect.returnValues(parameters[0].value));
                            
                        }else{
                            rect.addToTable('l',parameters[0].value);
                        }

                    }else if (operand.compare("cnst") == 0) {//Defining a constant
                        if (parameters[0].datatype == 1) {
                            rect.addToTable('c',rect.returnValues(parameters[0].value));
                            
                        }else{
                            rect.addToTable('c',parameters[0].value);
                        }
                        
                        
                    }else if (operand.compare("add") == 0) {//Addition
                        int jt = 0;
                        
                        if (parameters[1].datatype == 1){
                            jt += rect.returnValues(parameters[1].value);
                        }else{
                            jt += parameters[1].value;
                        }

                        rect.setValue(parameters[0],rect.returnValues(parameters[0].value)+jt);
                    }else if (operand.compare("sub") == 0) {//Subratction
                        int jt = 0;
                        
                        if (parameters[1].datatype == 1) {
                            jt += rect.returnValues(parameters[1].value);
                        }else{
                            jt += parameters[1].value;
                        }
                        
                        rect.setValue(parameters[0],rect.returnValues(parameters[0].value)-jt);

                    //}else if (operand.compare("mod") == 0) {
                    //}else if (operand.compare("mult") == 0) {
                    //}else if (operand.compare("call") == 0) {
                        //Get method name, parameters
                        //Save program counter here
                        //Go to the method section and invoke a new parser and an HStack (in future versions optimized programs will tell the vm if an HStack is needed)
                        //run that code
                        //on return, destroy HStack, move back to program counter and coninue program
                    }else if (operand.compare("mov") == 0) {
                        int mt = 0;
                        if (parameters[1].datatype == 1){
                            mt += rect.returnValues(parameters[1].value);
                        }else{
                            mt += parameters[1].value;
                        }
                        rect.setValue(parameters[0],mt);
                    }else if (operand.compare("inc") == 0) {//Increment
                        rect.setValue(parameters[0],rect.returnValues(parameters[0].value) + 1);
                    }else if (operand.compare("dec") == 0) {//Decriment
                        rect.setValue(parameters[0],rect.returnValues(parameters[0].value) - 1);
                    }else if (operand.compare("dmp") == 0) {//Dump values
                        rect.printTable();
                    }else if (operand.compare("ret") == 0) {//Return function
                        printf("return function\n");
                    }else if (operand.compare("hlt") == 0) {//Halt
//                        rect.printTable();
                        //fclose(f);
                        exit(0);
                    }else{
                        cout << "Unknown operand: " << operand << endl;
                        cout << "Halting" << endl;
                        exit(1);
                    }


                    //logging
                    //fprintf(f,"");
                    /* Logging               if (strcmp(argv[4],NULL)==0) {
                     f = fopen("log.txt", "w");
                     if (f == NULL){
                     printf("Error opening file!\n");
                     exit(1);
                     }
                     }else{
                     f = fopen(argv[4], "w");
                     if (f == NULL){
                     printf("Error opening file!\n");
                     exit(1);
                     }
                     }*/

                    
                    
                    currentInt=0;
                    paramPlace = 0;
                    operand = "";
                    memset(parameters, 0, sizeof(parameters)) ;
                    break;
                default:
                    cout <<"Parse error";
            }
        }
    }
}

void headparse(){

    int head = 1;//0 when header is complete
    while (head == 1) {
        fin.get(ch);
        //cout << ch << endl;
        
        if (isdigit(ch)) {
            int lucy = ch - '0';
            tempStore = addToInt(tempStore, lucy);
            
        }else if (ch == 32){//spaces
            
            if (pVal == 0) {
                if (tempStore != 84){
                    cout << "Error. Illegal magic number" << endl;
                    exit(0);
                }
            }else if(pVal == 1){
                if (tempStore != FILE_VERSION){
                    cout << "Error. Illegal file version" << endl;
                    exit(0);
                }
            }else if(pVal == 2){
                methodOff = tempStore;
            }else{
                cout << "Error. Invalid header" << endl;
                exit(0);
            }
            
            pVal++;
            tempStore = 0;
        }else if (ch == '\n'){//new line
            
            if(pVal == 2){
                methodOff = tempStore;
                pVal++;
            }
            
            if (pVal != 3) {
                cout << "Error. Illegal header" << endl;
                exit(0);
            }else{
                head = 0;
            }
        }else{
            cout << "Error. Illegal header" << endl;
            exit(0);
        }
        
    }
    
    fin.get(ch);//skip new line


}



int addToInt(int origi, int val){
    return (origi * 10)+val ;
}
