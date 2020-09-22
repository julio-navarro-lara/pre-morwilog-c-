//
//  parse_file.h
//  hommilieres
//
//  Created by Julio Navarro Lara on 30/11/15.
//  Copyright (c) 2015 Julio Navarro Lara. All rights reserved.
//

#ifndef __hommilieres__parse_file__
#define __hommilieres__parse_file__

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Storager.h"
#include "Trigger.h"
#include "parse_line.h"
using namespace std;

/*  
 Function parse_from_file
 
    Purpose:
        To parse the logs from a given file
 
    Accepts:
        string filename : name of the file where there are the logs we want to parse
        string format : name of the log format so we can choose the correct parser
        Storager* storager : Pointer to the Storager object who manages the database of logs in memory
 
    Returns:
        The number of parsed logs
 */
int parse_from_file(string filename, string format, Storager* storager, Trigger* trigger);

#endif /* defined(__hommilieres__parse_file__) */
