//
// Created by L1584 on 2024/3/23.
//
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    if (intervals.empty()) {
        intervals.push_back(newInterval);
        return  intervals;
    }
    int n = intervals.size();
    vector<vector<int>> res;
    if (intervals[0][0] <= newInterval[0])
        res.push_back(intervals.front());
    else
        res.push_back(newInterval);
    for (int i = 0; i < n; i++) {
        int temp = res.back()[0] < newInterval[0] ? res.back()[0] : newInterval[0];
        if (res.back()[1] >= newInterval[0] && res.back()[1] < newInterval[1]) {
            res.pop_back();
            res.push_back({temp, newInterval[1]});  // 更新结果集
            i--;
        }
        else if (res.back()[1] >= intervals[i][0] && res.back()[1] < intervals[i][1]) {
            res.pop_back();
            res.push_back({temp, intervals[i][1]});  // 更新结果集
        }
        else if (res.back()[1] < intervals[i][1])
            res.push_back({intervals[i][0], intervals[i][1]});
    }
    if (res.back()[1] < newInterval[0])
        res.push_back(newInterval);
    else if (res.back()[1] < newInterval[1]) {
        int temp = res.back()[0];  // 记录结果集中最后一个区间的第一个元素
        res.pop_back();
        res.push_back({temp, newInterval[1]});  // 更新结果集
    }
    return res;
}

//int main() {
//    vector<vector<int>> intervals = {{0,5},{9,12}};
//    vector<int> newInterval = {7,16};
//    vector<vector<int>> res = insert(intervals, newInterval);
//    for (const auto& item: res) {
//        for (int i: item)
//            cout << i << ' ';
//        cout << endl;
//    }
//}
