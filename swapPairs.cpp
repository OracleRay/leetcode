//
// Created by L1584 on 2024/3/22.
//
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *p = head->next;
    head->next = p->next;
    p->next = head;
    head = p;
    p = p->next;
    while (p->next != nullptr && p->next->next != nullptr) {
        ListNode *q = p->next;
        p->next = q->next;
        p = p->next;
        if (p->next != nullptr)
            q->next = p->next;
        else
            q->next = nullptr;
        p->next = q;
        p = p->next;
    }
    return head;
}

//int main() {
//    auto *head = new ListNode(1);
//    auto *node1 = new ListNode(2);
//    auto *node2 = new ListNode(3);
//    auto *node3 = new ListNode(4);
//    auto *node4 = new ListNode(5);
//    auto *node5 = new ListNode(6);
//    auto *node6 = new ListNode(7);
//    head->next = node1;
//    node1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    node4->next = node5;
//    node5->next = node6;
//    head = swapPairs(head);
//    ListNode *p = head;
//    while (p != nullptr) {
//        cout << p->val << ' ';
//        p = p->next;
//    }
//}
