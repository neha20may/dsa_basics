//
// Created by Neha on 10/09/22.
//

#ifndef LINKED_LIST_LINKEDHASHMAP_H
#define LINKED_LIST_LINKEDHASHMAP_H


#include "DLinkedList.h"
#include <algorithm>
#include <unordered_map>

class LinkedHashMap {
    int size;
    int capacity;
    unordered_map<int, Node *> map;
    DLinkedList *list;
public:
    LinkedHashMap(int cap) {
        this->capacity = cap;
        list = new DLinkedList();
    }

    void put(int key) {
        Node *node = new Node(key);
        if (this->size >= this->capacity) {
            int keyToEvict = list->head->data;
            list->del(list->head);

            map.erase(keyToEvict);
        } else {
            this->size++;
        }
        map[key] = node;
        list->append(node);

    }

    bool get(int key) {
        if (map.find(key) != map.end()) {
            Node *node = map[key];

            list->del(node);
            list->append(node);
            return true;
        } else {
            return false;
        }
    }

    void print() {
        list->print();
    }


};


#endif //LINKED_LIST_LINKEDHASHMAP_H
