#include <iostream>
#include <string.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int count, length = 0;      //窗口长度
    int temp = 0;      // 子串遍历时的初始指针
    if (s.length() == 1)
        return 1;
    for (int i = 1; i < s.length(); i++) {
        count = 1;         // 窗口长度初始化为1
        for (int j = temp; j < i; j++) {
            if (s[j] == s[i]) {
                temp = j + 1;     // 缩小窗口
                break;
            }
            count++;
        }
        if (count > length)        // 更新窗口长度
            length = count;
    }
    return length;
}
