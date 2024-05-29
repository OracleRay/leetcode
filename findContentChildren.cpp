//
// Created by L1584 on 2024/2/18.
//

#include <vector>
#include <iostream>
#include "algorithm"

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int contentChildren = 0;   // 已满足孩子数量
    int weiKouIndex = 0, bingGanIndex = 0;
    while (weiKouIndex < g.size() && bingGanIndex < s.size()) {
        while (bingGanIndex < s.size() && g[bingGanIndex] > s[weiKouIndex])
            bingGanIndex++;
        if (bingGanIndex < s.size())
            contentChildren++;
        bingGanIndex++;
        weiKouIndex++;
    }
    return contentChildren;
}

//int main (){
//    vector<int> g = {10,9,8,7,10,9,8,7};
//    vector<int> s = {10,9,8,7};
//    cout << findContentChildren(g, s);
//    return 0;
//}