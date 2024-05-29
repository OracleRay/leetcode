//
// Created by L1584 on 2024/3/12.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    unsigned long long n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    if (n < 4)
        return res;
    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] == nums[i-1])  // 防止重复
            continue;
        if (nums[i] + nums[i+1] > target && target >= 0)
            break;
        for (int j = i + 1; j < n - 2; j++) {
            if (j > i+ 1 && nums[j] == nums[j-1])
                continue;
            int left = j + 1, right = n - 1;
            vector<int> temp;
            while (left < right) {
                long sum = (long) nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while (left < right && nums[left+1] == nums[left])  // 防止重复
                        left++;
                    left++;
                    while (left < right && nums[right-1] == nums[right])
                        right--;
                    right--;
                }
                else if (sum < target)
                    left++;
                else
                    right--;
            }
        }
    }
    return res;
}

//int main() {
//    vector<int> nums = {0,0,0,1000000000,1000000000,1000000000,1000000000};
//    vector<vector<int>> res = fourSum(nums, 1000000000);
//    for (const auto& i: res) {
//        for (auto j: i)
//            cout << j << ',';
//        cout << endl;
//    }
//}
