//
// Created by L1584 on 2024/2/23.
//

/**
 * 用队列实现栈
 */

#include "iostream"
#include "queue"

using namespace std;

class MyStack {
public:
    queue<int> queue1;
    queue<int> queue2;

    MyStack() {

    }

    void push(int x) {
        queue2.push(x);
        while (!queue1.empty()) {
            queue2.push(queue1.front());
            queue2.pop();
        }
        swap(queue1,queue2);
    }

    int pop() {
        int x = queue1.front();
        queue1.pop();
        return x;
    }

    int top() {
        return queue1.front();
    }

    bool empty() {
        return queue1.empty();
    }
};
