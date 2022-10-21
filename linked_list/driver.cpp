//
// Created by Neha on 10/09/22.
//
#include <iostream>

using namespace std;

#include "LinkedList.h"

LinkedList *sort(LinkedList *l) {
    LinkedList *zero = new LinkedList();
    LinkedList *one = new LinkedList();
    LinkedList *two = new LinkedList();
    Node *cur = l->head;
    while (cur != nullptr) {
        switch (cur->data) {
            case 0: {
                zero->append(cur);

            }
                break;
            case 1: {
                one->append(cur);

            }
                break;
            case 2: {
                two->append(cur);

            }
                break;
        }
        cur =cur->next;
    }
    if (zero->tail != nullptr) {
        zero->tail = one->head;
    }
    if (one->tail != nullptr) {
        one->tail = two->head;
    }

    LinkedList *result = new LinkedList();

    if (zero->head != nullptr) {
        result->head = zero->head;
    } else if (one->head != nullptr) {
        result->head = one->head;
    } else {
        result->head = two->head;
    }

    if (two->tail != nullptr) {
        result->tail = two->tail;
    } else if (one->tail != nullptr) {
        result->tail = one->tail;
    } else {
        result->tail = zero->tail;
    }

    return result;

}

int main() {
    cout << "Hello, World!" << endl;
    LinkedList *list = new LinkedList();
    list->append(new Node(1));
    list->append(new Node(2));
    list->append(new Node(3));
    list->append(new Node(4));
    list->print();

    LinkedList *l2 = new LinkedList();
    l2->append(new Node(0));
    l2->append(new Node(1));
//    l2->append(new Node(2));
    l2->append(new Node(0));
    l2->append(new Node(0));
    l2->append(new Node(1));
    l2->append(new Node(1));
    l2->append(new Node(1));
//    l2->append(new Node(2));
//    l2->append(new Node(2));
    l2->print();

    auto l3 = sort(l2);
    l3->print();


}
