//
//  parse_line.cpp
//  hommilieres
//
//  Created by Julio Navarro Lara on 27/11/15.
//  Copyright (c) 2015 Julio Navarro Lara. All rights reserved.
//

#include "parse_line.h"

// This functions work with a single log line
// It returns its fields arranged in a map
map<string, string> satf_to_map (string logline){
    map<string,string> log_map;
    regex line_regex_global ("#S#(\\S+)#E#");
    regex line_regex ("([^=]+)=([^#]+)");
    
    smatch line_match;
    regex_match(logline, line_match, line_regex_global);
    
    stringstream ss(line_match[1]);
    string field;
    
    while (getline(ss, field, '#')){
        regex_match(field, line_match, line_regex);
        log_map[line_match[1]] = line_match[2];
    }
    
    return log_map;
}