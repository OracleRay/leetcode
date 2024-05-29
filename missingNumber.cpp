//
// Created by L1584 on 2024/2/25.
//

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

/**
 * 方法一：排序
 * @param nums
 * @return
 */
//int missingNumber(vector<int>& nums) {
//    sort(nums.begin(), nums.end());
//    if (nums[0] != 0)
//        return 0;
//    for (int i = 1; i < nums.size(); i++)
//        if (nums [i] != i)
//            return i;
//    return nums.size();
//}

/**
* 方法二：数学
*/
int missingNumber(vector<int>& nums) {
    int sum = 0;
    for (int num: nums)
        sum += num;
    return (1 + nums.size()) * (nums.size()) / 2 - sum;
}