//
// Created by L1584 on 2024/3/11.
//

#include "iostream"
#include "vector"
using namespace std;

/**
 * 动态规划
 * @param grid
 * @return
 */
int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size()));
    dp[0][0] = grid[0][0];
    for (int i = 1; i < grid[0].size(); i++)
        dp[0][i] = dp[0][i-1] + grid[0][i];
    for (int i = 1; i < grid.size(); i++)
        dp[i][0] = dp[i-1][0] + grid[i][0];
    for (int i = 1; i < grid.size(); i++) {
        for (int j = 1; j < grid[i].size(); j++) {
            dp[i][j] = min(grid[i][j] + dp[i-1][j], grid[i][j] + dp[i][j-1]);
        }
    }
    return dp.back().back();
}

//int main() {
//    vector<vector<int>> nums = {{1,3,1},{1,5,1},{4,2,1}};
//    cout << minPathSum(nums);
//}