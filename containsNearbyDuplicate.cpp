//
// Created by L1584 on 2024/3/13.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
        if (m.find(nums[i]) != m.end()) {
            if (m[nums[i]] == i)
                continue;
            if (abs(m[nums[i]] - i) <= k)
                return true;
            else
                m[nums[i]] = i;  // 标记每个元素的最大下标
        } else
            m[nums[i]] = i;
    }
    return false;
}

//int main() {
//    vector<int> nums = {1,2,3,1,2,3};
//    cout << containsNearbyDuplicate(nums, 2);
//}