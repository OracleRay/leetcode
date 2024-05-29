//
// Created by L1584 on 2024/2/24.
//

#include <vector>
#include "iostream"

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    bool appear[nums.size()];
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
        appear[i] = false;
    for (int num : nums)
        if (!appear[num - 1])
            appear[num - 1] = true;
    for (int i = 0; i < nums.size(); i++)
        if (!appear[i])
            res.push_back(i + 1);
    return res;
}

//int main() {
//    vector<int> nums = {4,3,2,7,8,2,3,1};
//    nums = findDisappearedNumbers(nums);
//    for (int i: nums)
//        cout << i;
//    return 0;
//}