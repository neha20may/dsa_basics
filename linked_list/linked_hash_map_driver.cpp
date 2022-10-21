//
// Created by Neha on 11/09/22.
//
#include "LinkedHashMap.h"
int main(){
    LinkedHashMap * lru = new LinkedHashMap(3);
    lru->put(1);
    lru->put(2);
    lru->put(3);
    lru->print();
    lru->get(1);
    lru->get(3);
    lru->print();
    lru->put(10);
    lru->put(11);
    lru->put(9);
    lru->print();
    lru->put(101);
    lru->put(110);
    lru->put(90);
    lru->print();

}
