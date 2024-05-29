#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // 合并两个有序数组
    vector<int> mergeTowNums(nums1.size() + nums2.size());
    merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), mergeTowNums.begin());

    if (mergeTowNums.size() % 2 != 0)
        return (double)mergeTowNums[(mergeTowNums.size() - 1) / 2];
    else 
        return ((double)mergeTowNums[mergeTowNums.size() / 2] + (double)mergeTowNums[mergeTowNums.size() / 2 - 1]) / 2;
}

// int main() {
//     vector<int> nums1 = {1,2};
//     vector<int> nums2 = {3,4};
//     cout << findMedianSortedArrays(nums1, nums2);
//     return 0;
// }