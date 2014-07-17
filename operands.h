//
//  operands.h
//  
//
//  Created by James Spann on 7/10/14.
//
//

#ifndef _operands_h
#define _operands_h

enum opcodes {
    H_UNDEF     = 0,
    H_DEFINE    = 1,// <initial integer value>
    H_CONST     = 2,// <initial integer value>
    H_ADD       = 3,// <assigned register> <first value> <second value>
    H_SUB       = 4,// <assigned register> <first value> <second value>
    H_MULT      = 5,// <assigned register> <first value> <second value>
    H_DIV       = 6,// <assigned register> <first value> <second value>
    H_MOD       = 7,// <assigned register> <first value> <second value>
    H_INC       = 8,// <register being incremented>
    H_DEC       = 9,// <register being incremented>
    H_HLT       = 10,// Stops program
};

/*
#define defi 2 //
#define const 2 //

#define add 3 // <assigned register> <first value> <second value>
#define sub 3 // <assigned register> <first value> <second value>
#define mult 2// <assigned register> <first value> <second value>
#define div 2// <assigned register> <first value> <second value>
#define mod 3// <assigned register> <first value> <second value>

#define inc 1 //<register being incremented>
#define dec 1 //<register being decrimented>

#define coeq 2 //<first register> <second register/ second value>
#define cogt 2 //<first register> <second register/ second value>
#define colt 2 //<first register> <second register/ second value>

#define goto 1 //<line number>
#define ret 0 //return from function

#define hlt 0 //Stops program
*/


#endif
