//
// Created by L1584 on 2024/3/10.
//

#include "iostream"
#include "vector"
using namespace std;

int numDecodings(string s) {
    vector<int> dp(s.size() + 1);
    dp[0] = 1;
    for (int i = 1; i <= s.size(); i++) {
        if (s[i-1] != '0')
            dp[i] += dp[i-1];
        if (i > 1 && (s[i-1] - '0') + (s[i-2] - '0') * 10 <= 26 && s[i-2] != '0')
            dp[i] += dp[i-2];
    }
    return dp[s.size()];
}

//int main() {
//    string s = "12";
//    cout << numDecodings(s);
//}