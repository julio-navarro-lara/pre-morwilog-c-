//
//  log_generator.cpp
//  hommilieres
//
//  Created by Julio Navarro Lara on 25/11/15.
//  Copyright (c) 2015 Julio Navarro Lara. All rights reserved.
//

#include "log_generator.h"
//#include "boost/date_time.hpp"

LogGenerator::LogGenerator(std::string filename){
    web_servers = {"74.125.103.20","74.125.103.21","74.125.103.22"};
    mail_servers = {"74.125.103.23","74.125.103.24"};
    all_servers.reserve(web_servers.size()+mail_servers.size());
    all_servers.insert(all_servers.end(),web_servers.begin(),web_servers.end());
    all_servers.insert(all_servers.end(),mail_servers.begin(),mail_servers.end());
    
    users = {"68.180.194.242","68.180.194.243","69.147.112.168","69.147.112.169",
        "87.248.122.141","87.248.122.142","209.131.41.48","209.131.41.49","216.39.58.17",
        "216.39.58.18","216.39.58.78"};
    
    actions = {"ACCEPT","DROP"};
    actions_prob = {0.7, 1};
    protocols = {"http", "smtp", "ftp", "ssh"};
    protocols_prob = {0.8, 0.9, 0.95, 1};
    
    timesteps_prob = {0.3, 0.7, 0.9, 1};
    numberoflogs = 100;
}

void LogGenerator::generate_firewall(){
    //DAte time
    std::map<std::string, std::string> datalog;
    
    for(int i = 1; i <= numberoflogs; i++){
        
        datalog["id"]=std::to_string(i);
        datalog["origin"]="FW-1";
        
        //Temas de tiempo
    
        datalog["source"] =     users[rand() % users.size()];
        datalog["protocol"] =   protocols[rand() % protocols.size()];
        
        if(datalog["protocol"]=="http"){
            datalog["destination"] = web_servers[rand() % web_servers.size()];
        }else if (datalog["protocol"]=="smtp"){
            datalog["destination"] = mail_servers[rand() % mail_servers.size()];
        }else{
            datalog["destination"] = all_servers[rand() % all_servers.size()];
        }
        cout << datalog["source"] << endl;
        
        datalog.clear();
        
    }
    
    
    printf("Hola C++");
    
    
}