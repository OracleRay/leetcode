//
// Created by L1584 on 2024/5/29.
//

#include <vector>

using namespace std;

/**
 * res[i]=除nums[i]外的所有nums中的元素乘积
 * @param nums
 * @return
 */
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();  // nums = [1,2,3,4]
    vector<int> res(n);

    // res[i]代表nums中前i个数的乘积
    res[0] = 1;
    for (int i = 1; i < n; i++)
        res[i] = res[i - 1] * nums[i - 1];  // res = [1,1,2,6]

    // 再让res[i]代表nums中前i个数和后面n-i-1个数的乘积
    int temp = 1;
    for (int i = n - 1; i >= 0; i--) {
        res[i] = temp * res[i];
        temp *= nums[i];
    }
    return res;
}