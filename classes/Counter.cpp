//
// Created by konstantin on 23.04.19.
//

#include "Counter.h"

void Counter::push_back_id(){
    ids.push_back(++counter);
}

int Counter::get_order(unsigned int id){
    for ( auto it = ids.begin(); it != ids.end(); it++) {
        if(*it == id){
            return it - ids.begin();
        }
    }
    return -1;
}

void Counter::delete_id(unsigned int order) {
    auto it = ids.begin() + order;
    ids.erase(it);
}

void Counter::erase_id(unsigned int index) {
    for ( auto it = ids.begin(); it != ids.end(); it++) {
        if(*it == index){
            ids.erase(it);
            break;
        }
    }
}

int Counter::get_id(unsigned int order){
    auto it = ids.begin() + order;
    return *it;
}