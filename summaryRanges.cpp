//
// Created by L1584 on 2024/2/25.
//

#include "iostream"
#include "vector"

using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    if (nums.empty()) {
        return res;
    }
    string range;
    int begin = 0, end = 1;
    for (end = 1; end < nums.size(); end++) {
        if (nums[end] != nums[end - 1] + 1) {
            if (begin == end - 1)
                range.append(to_string(nums[begin]));
            else {
                range.append(to_string(nums[begin]) + "->" + to_string(nums[end - 1]));
            }
            res.push_back(range);
            range = "";
            begin = end;
        }
    }
    if (begin == end - 1)
        range.append(to_string(nums[begin]));
    else {
        range.append(to_string(nums[begin]) + "->" + to_string(nums[end - 1]));
    }
    res.push_back(range);
    return res;
}

//int main(){
//    vector<int> nums = {-2147483648,-2147483647,2147483647};
//    vector<string> res = summaryRanges(nums);
//    for (string s: res)
//        cout << s << ", ";
//    return 0;
//}