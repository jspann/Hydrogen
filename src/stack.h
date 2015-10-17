//
//  stack.h
//  
//
//  Created by James Spann on 10/16/15.
//
//

#ifndef _stack_h
#define _stack_h
#import "Hydrogen.h"

class Stack{
	int values[MAX_FUNCTION];//Cannot remain a static number
	int scount;//Number of used spaces in stack

	public:
		Stack();
		void initStack(){scount = 0;int i;for(i = 0; i<MAX_FUNCTION; i++){values[i]=0;}return;}//Creates stack
		void push(int p){values[scount] = p;scount++;return;}//Adds value to top of stack
		void pop(){scount--;return;}//Removes topmost value in stack
		int count(){return scount;}//Number of used spaces in stack
};

Stack::Stack(){

}
#endif
