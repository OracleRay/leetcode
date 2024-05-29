//
// Created by L1584 on 2024/3/10.
//

#include "iostream"
#include "vector"
using namespace std;

bool canJump(vector<int>& nums) {
    if (nums.size() == 1)
        return true;
    int jump = 0;
    for (int i = 0; i < nums.size(); i++) {
        jump = max(jump, i + nums[i]);
        if (i >= jump)
            break;
        if (jump >= nums.size() - 1)
            return true;
    }
    return false;
}

//int main() {
//    vector<int> nums = {0};
//    cout << canJump(nums);
//}
