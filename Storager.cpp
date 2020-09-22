//
//  Storager.cpp
//  hommilieres
//
//  Created by Julio Navarro Lara on 30/11/15.
//  Copyright (c) 2015 Julio Navarro Lara. All rights reserved.
//

#include "Storager.h"

Storager::Storager(string* headers, void* database){
    this->headers = headers; //We have to define the log field we store in the database
    numCol = sizeof(headers)-1; //The number of columns come from the lenght of the headers array
    db = database;
}

void* Storager::store_line(map<string, string> logline){
    
    void *rec = wg_create_record(db, numCol);
    
    wg_int enc;
    
    for (int i = 0; i < numCol; i++) {
        //Everything is a string so far
        string entrystr = logline[headers[i]];
        
        //The only way of storing in WhiteDB is transforming the strings to char*
        char* entry = new char[entrystr.size() + 1];
        copy(entrystr.begin(), entrystr.end(), entry);
        entry[entrystr.size()] = '\0';
        
        enc = wg_encode_str(db, entry, NULL);
        
        wg_set_field(db, rec, i, enc);
        
    }
    
    return rec;
}

int Storager::free_memory(){
    wg_delete_database((char*)"1000");
    
    return 1;
}

