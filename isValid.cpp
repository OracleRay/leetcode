//
// Created by L1584 on 2024/2/14.
//

#include "iostream"
#include "map"
#include "stack"

using namespace std;

char anotherSign(char c) {
    map<char, char> m;
    m['('] = ')';
    m['['] = ']';
    m['{'] = '}';
    return m[c];
}

bool isValid(string s) {
    stack<char> stk;
    for (char c: s) {
        if (c == '(' || c == '[' || c == '{')
            stk.push(c);
        else {
            if (stk.empty() || c != anotherSign(stk.top()) )
                return false;
            else
                stk.pop();
        }
    }
    return stk.empty();
}

//int main (){
//    string s = "]";
//    cout << isValid(s);
//    return 0;
//}


