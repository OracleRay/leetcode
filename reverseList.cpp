//
// Created by L1584 on 2024/2/23.
//

#include "iostream"
#include "vector"

using namespace std;

struct ListNode {
 int val;
 ListNode *next;
 ListNode() : val(0), next(nullptr) {}
 ListNode(int x) : val(x), next(nullptr) {}
 ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    if (head == nullptr)
        return head;
    auto *newHead = new ListNode();
    ListNode *p = head;
    while (p != nullptr) {
        auto *newNode = new ListNode(p->val);
        newNode->next = newHead->next;
        newHead->next = newNode;
        p = p->next;
    }
    return newHead->next;
}
