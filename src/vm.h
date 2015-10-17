//
//  vm.h
//  
//
//  Created by James Spann on 3/4/14.
//
//

#ifndef _vm_h
#define _vm_h
//int fileLog;//A flag for logging output to a file. 1 for one 0 for off

void badhalt(std::string reason);
void initVM();
void loadFile(char* filename);

#endif
