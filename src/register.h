//
//  register.h
//  
//
//  Created by James Spann on 10/20/15.
//
//

#ifndef _register_h
#define _register_h
#import "Hydrogen.h"

const int MAX_SPACES = 500;
class Register{
	int usedSpaces;
	int values[MAX_SPACES];
	int types[MAX_SPACES];

	public:
		Register();
		void initRegister();
		void dumpRegister();
		void setValueAt(int loc, int vu);
		void addValue(int value);
		unsigned int returnValue(int atLocation);
		void killRegister();
};



#endif
