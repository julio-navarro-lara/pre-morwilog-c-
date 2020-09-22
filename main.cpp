//
//  main.cpp
//  hommilieres
//
//  Created by Julio Navarro Lara on 25/11/15.
//  Copyright (c) 2015 Julio Navarro Lara. All rights reserved.
//

#include <iostream>
#include <thread>
//#include "log_generator.h"

//Recollector
#include "parse_file.h"
#include "Storager.h"
#include "Trigger.h"

//Loghill
#include "Orchestrator.h"

int main(int argc, const char * argv[]) {
    
    //We define the fields we are retrieving from the logs.
    //Those are going to be the important fields for using in our algorithm
    string headers[] = {"id","origin","timestamp","source","destination","protocol","action"};
    
    //We create the log database
    void* db = wg_attach_database((char*)"1000", 2000000);
    
    //************
    //Loghill module
    //************
    
    //We have to initiate the Orchestrator daemon in the Loghill as a separate thread
    //Provisionally we create the Orchestrator object in the Trigger... problems with the references to external objects for initiating a thread through lambda funcions
    
    //Orchestrator orchestrator;
    //We call the init() method of orchestrator but by reference
    //That means that we can still access the methods of "orchestrator" from the main thread!
    //Finally the solution were the lambda functions
    //CAREFUL: As we pass a reference to "orchestrator" instead of a copy, we need to ensure that we join the thread before we end the execution of the main thread, so we don't leave the execution of the new thread running
//    std::thread loghill_thread {
//        [&orchestrator] { orchestrator.init(); }
//    };
    
    //When we init the thread for the Orchestrator
    //std::thread t1(orchestrator); //For starting a thread with a copy
    //std::thread t2(Orchestrator()); //For creating a temporary object in the call
    //std::thread loghill_thread(std:ref(orchestrator)); //For not creating a copy, for entering a reference to the same object
    
    Orchestrator orchestrator(db);
    
    //************
    //Recollector module
    //************
    
    //Creation of the storager for managing the shared database
    Storager storager(headers, db);
    
    //Creation of the Trigger for communicating with the Loghill module
    Trigger trigger(orchestrator);
    
    //Parsing of a sample file
    int number_of_logs = parse_from_file("logsample", "satf", &storager, &trigger);
    
    //We free the memory
    storager.free_memory();
    
    cout << number_of_logs << endl;
    
    return 0;
}

