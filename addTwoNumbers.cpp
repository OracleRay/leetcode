#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* add(ListNode* l1, ListNode* l2) {
    ListNode *p = l1;
    ListNode *q = l2;
    ListNode *pre;
    while (p != NULL && q != NULL) {
        if (p->val + q->val > 9) {
            p->val -= 10;
            if (p->next != NULL)
                p->next->val++;
            else if (q->next != NULL)
                q->next->val++;
            else {
                ListNode* lastNode = new ListNode(1);
                p->next = lastNode;
            }
        }
        p->val = p->val + q->val;
        pre = p;
        p = p->next;
        q = q->next;
    }
    if (p == NULL)
        pre->next = q;
    return pre;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *p = add(l1, l2);
    while (p != NULL) {
        if (p->val > 9) {
            p->val -= 10;
            if (p->next != NULL) 
                p->next->val++;
            else {
                ListNode* lastNode = new ListNode(1);
                p->next = lastNode;
            }
        }
        p = p->next;           
    }
    return l1;
}


