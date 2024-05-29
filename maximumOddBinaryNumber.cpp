//
// Created by L1584 on 2024/3/13.
//

#include <iostream>
#include <algorithm>

using namespace std;

string maximumOddBinaryNumber(string s) {
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == '1') {
            if (s[s.length() - 1] != '1')  // 往开头插
                swap(s[i], s[s.length() - 1]);
            else {  // 往末尾插
                s.erase(s.begin() + i);
                s.insert(s.begin(), '1');
            }
        }
    }
    return s;
}

//int main() {
//    string s = "0101";
//    cout << maximumOddBinaryNumber(s);
//}
