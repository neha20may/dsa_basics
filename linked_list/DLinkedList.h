//
// Created by Neha on 10/09/22.
//

#ifndef PLOTTING_LINKEDLIST_H
#define PLOTTING_LINKEDLIST_H

#include "iostream"

using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev= nullptr;
    }
};

class DLinkedList {
public:
    Node *head;
    Node *tail;

    DLinkedList() {

    }

    void append(Node *node) {
        if (head == nullptr) {
            head = node;
        } else {
            tail->next = node;
            node->prev= tail;
        }
        tail = node;
    };

    Node *findPrev(Node *node) {
        return  node->prev;
    }

    void del(Node *node) {
        Node* prev= node->prev;
        Node* next= node->next;
        if(prev!= nullptr)
            prev->next= next;
        else
            head= next;

        if(next != nullptr)
            next->prev= prev;
        else
            this->tail =prev;

        node->prev= nullptr;
        node->next= nullptr;
        //delete node;

    }

    void print() {
        Node *cur = this->head;
        while (cur != nullptr) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};


#endif //PLOTTING_LINKEDLIST_H
