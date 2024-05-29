//
// Created by L1584 on 2024/5/28.
//

#include <vector>
#include "iostream"

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int> (n));
    int index = 1;
    int left = 0, right = n - 1, up = 0, down = n - 1;  // 定义上下左右边界
    while (right >= left && down >= up) {
        for (int i = left; i <= right; i++)  // 从左到右
            matrix[up][i] = index++;
        up++;
        for (int i = up; i <= down; i++)   // 从上到下
            matrix[i][right] = index++;
        right--;
        for (int i = right; i >= left; i--)  // 从右到左
            matrix[down][i] = index++;
        down--;
        for (int i = down; i >= up; i--)  // 从下到上
            matrix[i][left] = index++;
        left++;
    }
    return matrix;
}

/*
int main() {
    vector<vector<int>> res = generateMatrix(3);
    for (const auto& i: res) {
        for (auto j: i)
            cout << j << ' ';
        cout << endl;
    }
    return 0;
}*/
