//
// Created by L1584 on 2024/3/12.
//

#include <iostream>

using namespace std;

/**
 * 错误方法,应该用动态规划
 * @param s1
 * @param s2
 * @param s3
 * @return
 */
bool isInterleave(string s1, string s2, string s3) {
    int i = 0, j = 0, k = 0;
    while (k < s3.length() && i < s1.length() && j < s2.length()) {
        while (s1[i] == s3[k] && k < s3.length()) {
            i++;
            k++;
        }
        if (k == s3.length())
            break;
        while (s2[j] == s3[k] && k < s3.length()) {
            j++;
            k++;
        }
        if (s3[k] != s1[i] && s3[k] != s2[j])
            return false;
    }
    return (i >= s1.length() && j >= s2.length());
}

//int main() {
//    string s1 = "aa", s2 = "ab", s3 = "aaba";
//    cout << isInterleave(s1, s2, s3);
//}