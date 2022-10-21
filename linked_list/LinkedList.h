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

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node *head;
    Node *tail;

    LinkedList() {

    }

    void append(Node *node) {
        if (head == nullptr) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    };

    Node *findPrev(Node *node) {
        Node *cur = head;
        Node *prev = nullptr;
        while (cur != nullptr) {
            if (cur == node)
                break;
            prev = cur;
            cur = cur->next;
        }
        return prev;
    }

    void del(Node *node) {
        if (this->head == node) {
            head = head->next;
        }
        if (node->next != nullptr) {
            node->data = node->next->data;
            Node *ne = node->next;
            node->next = node->next->next;
            node = ne;
        } else {
            auto prev = findPrev(node);
            this->tail = prev;
        }
        delete node;
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
