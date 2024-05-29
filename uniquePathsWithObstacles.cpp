//
// Created by L1584 on 2024/3/7.
//

#include "iostream"
#include "vector"
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
    vector <int> f(m);
    f[0] = (obstacleGrid[0][0] == 0);     // 滚动数组
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (obstacleGrid[i][j] == 1) {
                f[j] = 0;
                continue;
            }
            if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
                f[j] += f[j - 1];
            }
        }
    }
    return f.back();
}

//int main () {
//    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
//    cout << uniquePathsWithObstacles(obstacleGrid);
//}