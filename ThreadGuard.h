//
//  ThreadGuard.h
//  
//
//  Created by Julio Navarro Lara on 06/01/16.
//
//

#ifndef ____ThreadGuard__
#define ____ThreadGuard__

#include <stdio.h>
#include <thread>

//We create a thread controller class so we create an object for every thread (daemon) created and we make sure they are destroyed at the end of the execution of main
class ThreadGuard{
    std::thread& t;
public:
    explicit ThreadGuard(std::thread& t_):
    t(t_)
    {}
    
    ~ThreadGuard(){
        if(t.joinable()){
            t.join();
        }
    }
    
    ThreadGuard(ThreadGuard const&)=delete;
    
    ThreadGuard& operator=(ThreadGuard const&)=delete;
};

#endif /* defined(____ThreadGuard__) */
