//
//  HThread.h
//  
//
//  Created by James Spann on 4/23/14.
//
//

#ifndef ____HThread__
#define ____HThread__

#include <iostream>

struct HThread {
    int tid;//the number of the thread
    int priority;//1 for main threads 2 for secondary thread
    
    void start();
    void pause();
    void resume();
    void stop();

    void setPriority(int newPrior);
};

#endif /* defined(____HThread__) */
