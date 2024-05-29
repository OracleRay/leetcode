#include <iostream>
using namespace std;   

/**
 * @brief 将字符串s只保留小写字母和数字
 * 
 * @param s 
 * @return string 
 */
string simplifyString(string s) {
    string newS;
    for (char letter: s) 
        if ((letter > 96 && letter < 123) || (letter > 64 && letter < 91) || isdigit(letter)) { // 过滤标点
            if (letter > 64 && letter < 91) // 过滤大小写
                letter += 32;
            newS.push_back(letter);
        }
    return newS;
}

bool isPalindrome(string s) {
    s = simplifyString(s);
    int frontIndex = 0, rearIndex = s.size() - 1;
    while (frontIndex <= rearIndex) {
        if (s[frontIndex] != s[rearIndex])   // 判断第一个字符和最后一个字符是否相等
            return false;
        frontIndex++;
        rearIndex--;
    }
    return true;
}

// int main() {
//     string s = "0P";
//     string newS = simplifyString(s);
//     for (char c: newS) 
//         cout << c;
//     cout << endl << isPalindrome(s);
//     cout << endl << isdigit('s');
//     return 0;
// }

