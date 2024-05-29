//
// Created by L1584 on 2024/3/7.
//

#include "iostream"
#include "vector"
using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int> (n));
    // 初始化dp数组
    for (int i = 0; i < n; i++)
        dp[0][i] = 1;
    for (int j = 0; j < m; j++)
        dp[j][0] = 1;
    // 遍历
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
    // 输出
    return dp[m - 1][n - 1];
}

//int main () {
//    int m, n;
//    cin >> m >> n;
//    cout << uniquePaths(m, n);
//}
