//
// Created by L1584 on 2024/3/11.
//

#include "iostream"
#include "vector"
using namespace std;

int maxSubArray(vector<int>& nums) {
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = max(nums[i], dp[i-1] + nums[i]);  // 看看把之前的加上是否比当前值大
        res = max(res, dp[i]);
    }
    return res;
}

//int main() {
//    vector<int> nums = {5,4,-1,7,8};
//    cout << maxSubArray(nums);
//}
