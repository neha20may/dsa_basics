//
// Created by Neha on 11/09/22.
//

#ifndef LINKED_LIST_MAXQUEUE_H
#define LINKED_LIST_MAXQUEUE_H

#include "queue"
using namespace std;
class maxQueue {
    queue<int> q;
    queue<int> maxQ;
public:
    void getMax(){

    }

    void enqueue(int key){
        q.push(key);
        int max=0;
        if(!maxQ.empty())
            max= maxQ.front();
        if(key >= max){
            maxQ.push(key);
        }else{

        }
    }

    void dequeu(){

    }

};


#endif //LINKED_LIST_MAXQUEUE_H
