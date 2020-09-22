//
//  log_generator.h
//  hommilieres
//
//  Created by Julio Navarro Lara on 25/11/15.
//  Copyright (c) 2015 Julio Navarro Lara. All rights reserved.
//

#ifndef __hommilieres__log_generator__
#define __hommilieres__log_generator__

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <iostream>

using namespace std;

class LogGenerator {
    std::string filename;
    std::vector<std::string> web_servers;
    std::vector<std::string> mail_servers;
    std::vector<std::string> all_servers;
    std::vector<std::string> users;
    std::vector<std::string> actions;
    std::vector<float> actions_prob;
    std::vector<std::string> protocols;
    std::vector<float> protocols_prob;
    
    std::vector<float> timesteps_prob;
    int numberoflogs;
    
public:
    LogGenerator(std::string filename);
    void generate_firewall();
    
};

#endif /* defined(__hommilieres__log_generator__) */
