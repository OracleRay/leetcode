//
// Created by L1584 on 2024/3/20.
//
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int n = pushed.size();
    stack<int> stk;
    stk.push(pushed[0]);
    int i = 1, j = 0;   // 入栈指针和出栈指针
    while (!stk.empty() || j < n) {
        if (stk.empty() || stk.top() != popped[j]) {
            if (i >= n)
                return false;
            stk.push(pushed[i]);
            i++;
        }
        else {
            stk.pop();
            j++;
        }
    }
    return true;
}

//int main() {
//    vector<int> pushed = {1,2,3,4,5};
//    vector<int> popped = {4,5,3,2,1};
//    cout << validateStackSequences(pushed, popped);
//}

