//
// Created by L1584 on 2024/3/19.
//
#include "iostream"

using namespace std;

bool valid(int front, int rear, string s) {
    while (front < rear) {
        if (s[front] != s[rear])
            return false;
        front++;
        rear--;
    }
    return true;
}

bool validPalindrome(string s) {
    int front = 0, rear = s.length() - 1;
    while (front < rear) {
        if (s[front] != s[rear])
            return valid(front + 1, rear, s) || valid(front, rear - 1, s);
        front++;
        rear--;
    }
    return true;
}

//int main() {
//    string s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
//    cout << validPalindrome(s) ;
//}