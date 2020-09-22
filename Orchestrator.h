//
//  Orchestrator.h
//  hommilieres
//
//  Created by Julio Navarro Lara on 15/12/15.
//  Copyright (c) 2015 Julio Navarro Lara. All rights reserved.
//

#ifndef __hommilieres__Orchestrator__
#define __hommilieres__Orchestrator__

#include <stdio.h>
#include <iostream>
#include <thread>
#include <vector>

#include "morwi.h"

class Orchestrator {
    
    int number_of_morwis;
    
    std::vector<std::thread> morwi_list;
    
    void* db;
    
public:

    Orchestrator(void* database);
    
    void init_morwi(void* record);
};

#endif /* defined(__hommilieres__Orchestrator__) */
