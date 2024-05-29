//
// Created by L1584 on 2024/2/23.
//

#include <vector>
#include "iostream"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {
    if (head == nullptr)
        return head;

    // 解决开头就有相等元素的情况
    ListNode *res = head;
    while (res != nullptr && res->val == val)
        res = res->next;
    if (res == nullptr)
        return res;

    // 解决后来元素相等的情况
    ListNode *pre = res;
    ListNode *p = res->next;
    while (p != nullptr) {
        if (p->val == val) {
            pre->next = p->next;
            p = p->next;
            continue;
        }
        pre = pre->next;
        if (p != nullptr)
            p = p->next;
    }
    return res;
}

//int main() {
//    vector<int> node = {1,2,2,2,1};
//    auto *head = new ListNode(node[0]);
//    ListNode *p = head;
//    for (int i = 1; i < node.size(); i++) {
//        auto *newNode = new ListNode(node[i]);
//        p->next = newNode;
//        p = p->next;
//    }
//
//    ListNode *res = removeElements(head, 2);
//    ListNode *q = res;
//    while (q != nullptr) {
//        cout << q->val;
//        q = q->next;
//    }
//
//    return 0;
//}