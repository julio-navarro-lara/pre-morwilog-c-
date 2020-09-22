//
//  Storager.h
//  hommilieres
//
//  Created by Julio Navarro Lara on 30/11/15.
//  Copyright (c) 2015 Julio Navarro Lara. All rights reserved.
//

#ifndef __hommilieres__Storager__
#define __hommilieres__Storager__

#include <stdio.h>
#include <iostream>
#include <map>
#include "whitedb/dbapi.h"
using namespace std;

class Storager {
private:
    void* db;
    string* headers;
    int numCol;

public:
    Storager(string* headers, void* database);
    
    //It stores a log line represented as a map<field_name,field_value> in the memory
    //It returns a pointer to the record created
    void* store_line(map<string, string> logline);
    
    //It frees the log memory
    int free_memory();
};

#endif /* defined(__hommilieres__Storager__) */
