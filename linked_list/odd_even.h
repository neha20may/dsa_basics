/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void append(ListNode *node, ListNode *&tail, ListNode *&head) {
        if (head == nullptr) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }

    ListNode *sort(ListNode *cur) {
        ListNode *oddTail = nullptr, *evenTail = nullptr, *oddHead = nullptr, *evenHead = nullptr;
        int index = 0;
        while (cur != nullptr) {
            switch (index % 2) {
                case 0: {
                    append(cur, evenTail, evenHead);


                }
                    break;
                case 1: {
                    append(cur, oddTail, oddHead);

                }
                    break;
            }
            cur = cur->next;
            index++;
        }

        if (evenTail != nullptr) {
            evenTail->next = oddHead;
        }

        if (oddTail != nullptr) {
            oddTail->next = nullptr;
        }


        ListNode *result;

        if (evenHead != nullptr) {
            result = evenHead;
        } else {
            result = oddHead;
        }


        return result;
    }

    ListNode *oddEvenList(ListNode *head) {
        auto l = sort(head);
        return l;
    }
};