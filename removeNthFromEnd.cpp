#include "iostream"
using namespace std;

//
// Created by L1584 on 2024/2/5.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head->next == nullptr) {
        if (n == 1)
            return nullptr;
        else
            return head;
    }
    ListNode *fast = head, *slow = head, *slowHead = head;
    for (int i = 0; i < n - 1; i++)
        fast = fast->next;

    if (fast->next == nullptr)
        return head->next;
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
        if (fast->next != nullptr)
            slowHead = slowHead->next;
    }
    slowHead->next = slow->next;
    return head;
}

//int main () {
//    ListNode *l1 = new ListNode(1);
//    ListNode *l2 = new ListNode(2);
//    ListNode *l3 = new ListNode(3);
//    ListNode *l4 = new ListNode(4);
//    ListNode *l5 = new ListNode(5);
//    l1->next = l2;
//    l2->next = nullptr;
////    l3->next = l4;
////    l4->next = l5;
////    l5->next = nullptr;
//    ListNode *res = removeNthFromEnd(l1, 2);
//    ListNode *p = res;
//    while (p != nullptr) {
//        cout << p->val;
//        p = p->next;
//    }
//    return 0;
//}