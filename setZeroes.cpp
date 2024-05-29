//
// Created by L1584 on 2024/5/28.
//

#include <vector>
#include "unordered_set"
#include "iostream"

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    unordered_set<int> row;
    unordered_set<int> column;

    // 将矩阵中0所在的行和列用无序表存储
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] == 0) {
                row.insert(i);
                column.insert(j);
            }

    // 按照行进行清零
    for (const auto &item : row)
        for (int i = 0; i < n; i++)
            matrix[item][i] = 0;

    // 按照列进行清零
    for (const auto &item : column)
        for (int i = 0; i < m; i++)
            matrix[i][item] = 0;
}

/*
int main() {
    vector<vector<int>> res = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};
    setZeroes(res);
    for (const auto& i: res) {
        for (auto j: i)
            cout << j << ' ';
        cout << endl;
    }
    return 0;
}*/
