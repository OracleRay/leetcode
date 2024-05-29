//
// Created by L1584 on 2024/3/19.
//
#include "iostream"
#include "vector"

using namespace std;

char findTheDifference(string s, string t) {
    vector<int> count(26);
    for (char i : s)
        count[i - 'a']++;
    for (char i : t)
        if (--count[i - 'a'] < 0)
            return i;
    return ' ';
}

//int main() {
//    string s = "abcd";
//    string t = "abcde";
//    cout << findTheDifference(s, t);
//}
