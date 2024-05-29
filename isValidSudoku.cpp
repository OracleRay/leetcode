//
// Created by L1584 on 2024/5/27.
//

#include <cstring>
#include "vector"
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    int row[9][9];  // 存储9行的9个数字
    int colum[9][9];  // 存储9列的9个数字
    int subSudoku[3][3][9];  // 存储3行3列的9个数字

    // 初始化辅助空间
    memset(row, 0, sizeof (row));
    memset(colum, 0, sizeof (colum));
    memset(subSudoku, 0, sizeof (subSudoku));

    // 遍历
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            // 如果是空格则跳过
            if (board[i][j] == '.')
                continue;
            // 将board[i][j]对应的数字所在行列标记值+1
            int num = board[i][j] - '0' - 1;
            row[i][num]++;
            colum[j][num]++;
            subSudoku[i / 3][j / 3][num]++;
            if (row[i][num] > 1 || colum[j][num] > 1 || subSudoku[i / 3][j / 3][num] > 1)
                return false;
        }
    }
    return true;
}