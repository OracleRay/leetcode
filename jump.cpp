//
// Created by L1584 on 2024/3/10.
//

#include "iostream"
#include "vector"
using namespace std;

int jump(vector<int>& nums) {
    if (nums.size() == 1)
        return 0;
    int step = 0;
    int max_to = 0; // 从起始点“最远”可以跳到哪
    int new_max_to = 0; // 如果不一次跳到“最远”，先跳到与max_to之间的某一位置，那么可以跳到最远的距离是哪
    for (int i = 0; i < nums.size(); i++) {
        new_max_to = std::max(new_max_to, i + nums[i]);  // 与max_to之间的某一位置的结点可以到达的最远距离
        if (i >= max_to) {    // 已经跳到了max_to
            step++;
            max_to = new_max_to;
        }
        if (max_to >= nums.size() - 1)
            return step;
    }
    return 0;
}

//int main() {
//    vector<int> nums = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
//    cout << jump(nums);
//}