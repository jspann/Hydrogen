//
//  throwable.h
//  
//
//  Created by James Spann on 10/16/15.
//
//
 #ifndef _throwable_h
#define _throwable_h

struct throwableError{
	DivideError = 0,

	Breakpoint,
	Overflow,
	InvalidOpcode,
	DoubleFault
};

void throw();
#endif
