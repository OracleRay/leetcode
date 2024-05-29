//
// Created by L1584 on 2024/3/23.
//
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *p = headA, *q = headB;
    int a = 0, b = 0;
    while (p->next != nullptr) {
        p = p->next;
        a++;
    }
    p = headA;
    while (q->next != nullptr) {
        q = q->next;
        b++;
    }
    q = headB;
    while (a > b) {
        p = p->next;
        a--;
    }
    while (a < b) {
        q = q->next;
        b--;
    }
    while (p != q) {
        p = p->next;
        q = q->next;
    }
    return p;
}