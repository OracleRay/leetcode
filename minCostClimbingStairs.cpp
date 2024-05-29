//
// Created by L1584 on 2024/3/7.
//

#include "iostream"
#include "vector"
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    cost.push_back(0);
    cost.push_back(0);
    vector<int> dp(cost.size());
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < cost.size(); i++) {
        dp[i] = min(dp[i - 1] + cost[i], dp[i - 2] + cost[i]);
    }
    //输出dp数组
    for (int i : dp)
        cout << i << ' ';
    return dp[dp.size() - 1];
}

//int main() {
//    vector<int> cost = {10,15,20};
//    cout << minCostClimbingStairs(cost);
//}
