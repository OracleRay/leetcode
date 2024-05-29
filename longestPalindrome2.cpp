//
// Created by L1584 on 2024/2/15.
//
#include <map>
#include "iostream"
using namespace std;

int longestPalindrome2(string s) {
    // 构建哈希表
    map<char, int> m;
    for (char c: s) {
        if (m.find(c) == m.end())     //没找到则插入
            m[c] = 1;
        else {      // 找到则计数加一
            m[c] = ++m[c];
        }
    }

    // 遍历哈希表
    int count = 0;
    bool odd = false;
    for (auto & i : m) {
        if (i.second % 2 == 0)
            count += i.second;
        else {
            count += i.second - 1;
            odd = true;
        }
    }
    return odd ? count + 1 : count;
}

//int main (){
//    string s = "abccccdd";
//    cout << longestPalindrome2(s);
//    return 0;
//}