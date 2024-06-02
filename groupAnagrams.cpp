//
// Created by L1584 on 2024/6/2.
//

#include <unordered_map>
#include <algorithm>
#include "iostream"
#include "vector"

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
    int n = strs.size();

    //使strs形成一个排序序列sortedStr
    vector<string> sortedStr = strs;
    for (string& s: sortedStr)
        sort(s.begin(), s.end());

    //将strs和sortedStr进行map映射
    unordered_map<string, vector<string>> m;
    for (int i = 0; i < n; i++) {
        if (m.find(sortedStr[i]) == m.end())   //没找到，则新建key
            m[sortedStr[i]];
        m[sortedStr[i]].push_back(strs[i]);
    }

    //将map中的value加入temp_res，最后再加入res
    vector<vector<string>> res;
    for (auto & iter : m) {
        vector<string> temp_res;
        temp_res.reserve(iter.second.size());  //一次性分配好空间，提高后续遍历时push_back的效率
        for (const auto &item: iter.second)
            temp_res.push_back(item);
        res.push_back(temp_res);
    }
    return res;
}

/*
int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = groupAnagrams(strs);
    for (const auto &s: res) {
        for (const auto& i: s)
            cout << i << ' ';
        cout << endl;
    }
}*/
