//
// Created by L1584 on 2024/5/27.
//

#include <iostream>
#include "vector"
using namespace std;

/**
 * 算法思想：
 * 将数组一分为二，其中一定有一个是有序的，另一个可能是有序，也能是部分有序。
 * 此时有序部分用二分法查找。无序部分再一分为二，其中一个一定有序，另一个可能有序，可能无序。就这样循环.
 * @param nums
 * @param target
 * @return
 */
int search(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0)
        return -1;
    if (n == 1)
        return target == nums[0] ? 0 : -1;
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (nums[mid] == target)
            return mid;
        else {
            // 若左区间[l,mid]有序
            if (nums[l] <= nums[mid]) {
                if (target >= nums[l] && target < nums[mid])  // target在左区间
                    r = mid - 1;
                else  // target在右区间
                    l = mid + 1;
            }
            // 若右区间[mid,r]有序
            else {
                if (target > nums[mid] && target <= nums[r]) // target在右区间
                    l = mid + 1;
                else  // target在左区间
                    r = mid - 1;
            }
        }
    }
    return -1;
}

/*int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << search(nums, 5);
}*/
