//
// Created by L1584 on 2024/3/14.
//

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

void dfs(vector<vector<int>>& res, vector<int>& nums, int index) {
    if (index == nums.size()) {
        res.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        dfs(res, nums, index + 1);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    dfs(res, nums, 0);
    return res;
}

//int main() {
//    vector<int> nums = {1, 2, 3};
//    vector<vector<int>> res = permute(nums);
//    for (const auto& i: res) {
//        for (int j: i)
//            cout << j << ' ';
//        cout << endl;
//    }
//}