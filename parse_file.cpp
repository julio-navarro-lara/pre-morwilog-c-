//
//  parse_file.cpp
//  hommilieres
//
//  Created by Julio Navarro Lara on 30/11/15.
//  Copyright (c) 2015 Julio Navarro Lara. All rights reserved.
//

#include "parse_file.h"

int parse_from_file(string filename, string format, Storager* storager, Trigger* trigger){
    int numberoflogs = 0;
    string line;
    ifstream file (filename, ios::in | ios::binary);
    
    if (file.is_open()){
        while (getline(file, line)) {
            //list_of_logs.push_back(line);
            //if we are calling saft
            void* record = storager->store_line(satf_to_map(line));
            trigger->trig_from_log_from_file(record);
            numberoflogs++;
        }
        file.close();
    }
    else cout << "Unable to open file";
    
    return numberoflogs;
};