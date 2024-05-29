//
// Created by L1584 on 2024/5/26.
//

#include <vector>
#include <algorithm>
#include "iostream"

using namespace std;

void nextPermutation(vector<int> &nums) {
    // 第一次遍历：从右往左查找第一个降序的num1，下标为smaller
    int n = nums.size();
    int smaller = 0, bigger = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            smaller = i;
            break;
        }
    }

    // 第二次遍历：从右往左查找第一个比num1大的数，下标为bigger
    for (int i = n - 1; i >= 0; i--) {
        if (nums[i] > nums[smaller]) {
            bigger = i;
            break;
        }
    }

    // 交换nums[smaller]和nums[bigger]
    swap(nums[smaller], nums[bigger]);

    // 反转nums[smaller]后的所有元素
    if (smaller == bigger && smaller == 0)
        reverse(nums.begin(), nums.end());
    else
        reverse(nums.begin() + smaller + 1, nums.end());
}
