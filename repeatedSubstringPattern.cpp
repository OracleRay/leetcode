//
// Created by L1584 on 2024/2/19.
//

#include <iostream>

using namespace std;

bool repeatedSubstringPattern(string s) {
    if (s.length() == 1)
        return false;
    int buChang = 1;
    while (buChang < s.length()) {
        string substring = s.substr(0, buChang);    // 确定子串
        for (int i = substring.length(); i < s.length(); i+=buChang) {
            string substring_back = s.substr(i, buChang);   // 后续与子串同长的串
            if (substring_back == substring && i == s.length() - buChang)
                return true;
            if (substring_back != substring)
                break;
        }
        buChang++;
    }
    return false;
}

//int main (){
//    cout << repeatedSubstringPattern("abcabcabcabc");
//    return 0;
//}

