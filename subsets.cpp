//
// Created by L1584 on 2024/2/22.
//

#include "iostream"
#include "vector"

using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    res.emplace_back();      // 插入空子集
    for (int num: nums) {
        int times = res.size();     // 循环次数1,2,4,8......
        for (int j = 0; j < times; j++) {
            vector<int> temp = res[j];
            temp.push_back(num);      // 当前元素和之前的子集合并
            res.push_back(temp);     // 再把合并好的新子集加入
        }
    }
    return res;
}

//int main() {
//    vector<int> nums = {1,2,3};
//    vector<vector<int>> res = subsets(nums);
//    for (vector<int> i: res) {
//        for (int j: i)
//            cout << j << " ";
//        cout << endl;
//    }
//    return 0;
//}