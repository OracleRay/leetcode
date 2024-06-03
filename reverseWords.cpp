//
// Created by L1584 on 2024/6/2.
//

#include "iostream"

using namespace std;

/**
 * 从后往前删除空格
 * @param s 字符串
 * @param i 下标
 */
int deleteBlank(string &s, int i) {
    while (i >= 0 && s[i] == ' ')
        i--;
    return i;
}

string reverseWords(string s) {
    int n = s.size(), slow = n - 1;
    string res;

    //删除最后面的空格
    slow = deleteBlank(s, slow);

    //从后往前遍历
    for (int fast = slow; fast >= 0; fast--) {
        if (fast == 0 || s[fast - 1] == ' ') {
            res += s.substr(fast, slow - fast + 1) + " ";
            slow = deleteBlank(s, fast - 1);
            fast = slow + 1;
        }
    }
    return res.substr(0, res.size() - 1);  //去掉最后一个空格
}

/*
int main() {
    cout << reverseWords("a good   example");
}*/
