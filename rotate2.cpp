//
// Created by L1584 on 2024/5/28.
//

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * 方法一：三次翻转
 * @param nums
 * @param k
 */
/*void rotate(vector<int>& nums, int k) {
    k %= nums.size();

    // 翻转所有元素
    reverse(nums.begin(), nums.end());

    // 翻转 [0,k mod n−1] 区间的元素
    reverse(nums.begin(), nums.begin() + k);

    // 翻转 [k mod n, n - 1] 区间的元素
    reverse(nums.begin() + k, nums.end());
}*/

/**
 * 方法二：利用O(k)的辅助空间，把前面元素压入后面
 * @param nums
 * @param k
 */
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    for (int i = 0; i < n - k; i++)
        nums.push_back(nums[i]);  // 把前面的元素压入后面
    nums.erase(nums.begin(), nums.begin() + n - k);  // 删除前面的元素
}

/*int main() {
    vector<int> nums = {1,2,3,4,5,6,7};
    rotate(nums, 3);
    for (auto item: nums)
        cout << item;
}*/
