//
// Created by L1584 on 2024/3/13.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int i = 0;
    vector<int> res(2, -1);
    for (int num: nums) {
        if (num == target)
            break;
        i++;
    }
    if (i == nums.size())
        return res;
    else if (i == nums.size() - 1)
        res[1] = i;
    res[0] = i;
    for (int j = i + 1; j < nums.size(); j++)
        if (nums[j] != target) {
            res[1] = j - 1;
            return res;
        }
    res[1] = nums.size() - 1;
    return res;
}

//int main() {
//    vector<int> nums = {2,2};
//    vector<int> res = searchRange(nums, 2);
//    for (int item: res)
//        cout << item << ' ';
//
//}
