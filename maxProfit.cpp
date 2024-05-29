#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    vector<int> dp(prices.size());
    dp[0] = -prices[0];  // 获得的利润
    int cost = prices[0];  // 开销
    for (int i = 1; i < prices.size(); i++) {
        dp[i] = max(prices[i] - cost, dp[i-1]);  // 判断在第i-1天是否会获得最大利润
        cost = min(cost, prices[i]);
    }
    return dp.back() > 0 ? dp.back() : 0;
}

// int main() {
//     vector<int> prices = {7,6,4,3,1};
//     cout << maxProfit(prices);
//     return 0;
// }
