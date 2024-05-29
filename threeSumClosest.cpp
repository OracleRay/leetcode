//
// Created by L1584 on 2024/2/1.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int resSum = 20000;
    int closestDistance = 20000;
    sort(nums.begin(), nums.end());
    for (int midIndex = 0; midIndex < nums.size(); midIndex++) {
        int frontIndex = 0, rearIndex = nums.size() - 1;
        int sum;
        while (frontIndex < rearIndex) {
            /*跳过midIndex所指示元素*/
            if (midIndex == frontIndex || midIndex == rearIndex) {
                if (midIndex == frontIndex) frontIndex++;
                else rearIndex--;
                continue;
            }
            else {
                sum = nums[midIndex] + nums[frontIndex] + nums[rearIndex];
                if (sum < target) frontIndex++;
                else if (sum > target) rearIndex--;
                else return sum;
            }
        }
        if (abs(sum - target) < closestDistance) {
            closestDistance = abs(sum - target);
            resSum = sum;
        }
    }
    return resSum;
}

//int main() {
//    vector<int> nums = {0,1,2};
//    cout << threeSumClosest(nums, 3);
//    return 0;
//}
