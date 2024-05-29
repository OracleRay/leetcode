#include <iostream>
#include <string.h>
using namespace std;

string longestPalindrome(string s) {
    int count = 0;
    string palindrome = "";
    if (s.length() < 2)
        return s;
    else if (s.length() == 2) {
        if (s[0] == s[1])
            palindrome.append(s);
        else 
            palindrome.append(s.substr(0, 1));
        return palindrome; 
    } else if (s.length() == 3) {
        if (s[0] == s[1]) 
            palindrome.append(s.substr(0, 2));
        else if (s[1] == s[2])
            palindrome.append(s.substr(1, 2));
    }
    for (int i = 2; i < s.length(); i++) {       
        if (s[i] == s[i-2]) {
            count = 3;       // 回文串长度
            int j = 1;       // 回溯步长
            while (i+j < s.length() && i-2-j > -1) {
                if (s[i+j] != s[i-2-j])
                    break;
                count += 2;
                j++;
            }
            if (count > palindrome.length()) {      // 更新为更长的回文串
                palindrome = "";
                palindrome.append(s.substr(i-1-j, count)); 
            }
        }
        if (s[i] == s[i-1]) {
            count = 2;
            int j = 1;
            while (i+j < s.length() && i-1-j > -1) {
                if (s[i+j] != s[i-1-j])
                    break;
                count += 2;
                j++;
            }
            if (count > palindrome.length()) {
                palindrome = "";
                palindrome.append(s.substr(i-j, count));  
            }             
        }
    }
    if (count == 0 && palindrome.length() == 0) 
        palindrome.append(s.substr(0, 1));
    return palindrome; 
}
