//
// Created by L1584 on 2024/3/14.
//

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // 按对角线反转
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            swap(matrix[i][j], matrix[j][i]);

    // 逆置
    for (int i = 0; i < n; i++)
        reverse(matrix[i].begin(), matrix[i].end());

    // 输出
    cout << '[';
    for (int i = 0; i < n; i++) {
        cout << '[';
        for (int j = 0; j < n; j++) {
            if (j != n - 1)
                cout << matrix[i][j] << ',';
            else
                cout << matrix[i][j];
        }
        cout << ']';
    }
    cout << ']';
}

//int main() {
//    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
//    rotate(matrix);
//}