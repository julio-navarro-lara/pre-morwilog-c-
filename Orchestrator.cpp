//
//  Orchestrator.cpp
//  hommilieres
//
//  Created by Julio Navarro Lara on 15/12/15.
//  Copyright (c) 2015 Julio Navarro Lara. All rights reserved.
//

#include "Orchestrator.h"

Orchestrator::Orchestrator(void* database){
    number_of_morwis = 0;
    db = database;
}

void Orchestrator::init_morwi(void* record){
    
    //Initiate Morwi as a thread
    
    std::thread morwi_test(test, db, record);
    
    //Add the thread to a list
    //morwi_list.push_back(morwi_thread);
    number_of_morwis++;
    std::cout << number_of_morwis << std::endl;
    
    //Detach Morwi
    morwi_test.detach();
    
}


