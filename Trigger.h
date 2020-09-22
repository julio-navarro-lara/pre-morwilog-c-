//
//  Trigger.h
//  
//
//  Created by Julio Navarro Lara on 05/01/16.
//
//

#ifndef ____Trigger__
#define ____Trigger__

#include <stdio.h>
#include <iostream>
#include <thread>

#include "ThreadGuard.h"

#include "Orchestrator.h"

class Trigger {
    Orchestrator* orchestrator;
public:
    Trigger(Orchestrator &orch);
    int trig_from_log_from_file(void* record);
    void test();
};

#endif /* defined(____Trigger__) */
