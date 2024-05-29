//
// Created by L1584 on 2024/2/21.
//

#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int thirdMax(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<>());   //逆序排序
    int count = 1;    // 数有几个不同的数字
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i-1])
            count++;
        if (count == 3)
            return nums[i];
    }
    return nums[0];
}

//int main () {
//    vector<int> nums = {2,2,3,1};
//    cout << thirdMax(nums);
//    return 0;
//}