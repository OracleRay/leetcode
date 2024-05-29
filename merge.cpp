//
// Created by L1584 on 2024/3/23.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty())
        return intervals;
    int n = intervals.size();
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());
    res.push_back(intervals[0]);
    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= res.back()[1]) {
            if (intervals[i][1] < res.back()[1])   //第一个集合包含第二个集合
                continue;
            else {  // 有交集
                int temp = res.back()[0];  // 记录结果集中最后一个区间的第一个元素
                res.pop_back();
                res.push_back({temp, intervals[i][1]});  // 更新结果集
            }

        }
        else {
            res.push_back({intervals[i][0], intervals[i][1]});
        }
    }
    return res;
}

