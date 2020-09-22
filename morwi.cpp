//
//  morwi.cpp
//  
//
//  Created by Julio Navarro Lara on 07/01/16.
//
//

#include "morwi.h"

void test(void* db, void* record){
    
    std::cout << wg_decode_str(db, wg_get_field(db, record, 2)) << std::endl;
}