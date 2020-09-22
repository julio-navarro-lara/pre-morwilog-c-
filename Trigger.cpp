//
//  Trigger.cpp
//  
//
//  Created by Julio Navarro Lara on 05/01/16.
//
//

#include "Trigger.h"

Trigger::Trigger(Orchestrator &orch){
    orchestrator = &orch;
}

int Trigger::trig_from_log_from_file(void* record){
    
    orchestrator->init_morwi(record);
    
    return 1;
}
