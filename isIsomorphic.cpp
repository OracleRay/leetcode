#include <iostream>
#include <unordered_set>

using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.length() != t.length())
        return false;
    for (int i = 0; i < s.length(); i++)
        for (int j = i + 1; j < s.length(); j++)
            if ((s[i] == s[j] && t[i] != t[j]) || (s[i] != s[j] && t[i] == t[j]))
                return false;
    return true;
}

//int main() {
//    string s = "badc";
//    string t = "baba";
//    cout << isIsomorphic(s, t);
//    return 0;
//}