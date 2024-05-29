#include <iostream>
#include <vector>
using namespace std;   

/**
 * @brief 划分枢轴函数
 * 
 * @param nums 
 * @param low 
 * @param high 
 * @return int 
 */
int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[low];
    while (low < high) {
        while (low < high && nums[high] >= pivot) high--;
        nums[low] = nums[high];
        while (low < high && nums[low] <= pivot) low++;
        nums[high] = nums[low];
    }
    nums[low] = pivot;
    return low;
}

/**
 * @brief 快速排序
 * 
 * @param nums 
 * @param low 
 * @param high 
 */
void quickSort(vector<int>& nums, int low, int high) {
    if (low < high) {
        int pivot = partition(nums, low, high);
        quickSort(nums, low, pivot-1);
        quickSort(nums, pivot+1, high);
    }
}

int majorityElement(vector<int>& nums) {
    if (nums.size() < 2)
        return nums[0];
    quickSort(nums, 0, nums.size() - 1);       // 快速排序
    // for (int num: nums) 
    //     cout << num;
    if (nums[nums.size() / 2] == nums[nums.size() / 2 - 1] || 
        nums[nums.size() / 2] == nums[nums.size() / 2 + 1]
    )
        return nums[nums.size() / 2];
    else 
        return -1;
}

// int main() {
//     vector<int> nums = {1};
//     cout << majorityElement(nums);
//     return 0;
// }