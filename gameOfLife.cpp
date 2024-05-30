//
// Created by L1584 on 2024/5/29.
//

#include <vector>
#include <iostream>

using namespace std;

bool judge(vector<int>& subBoard, bool live) {
    if (subBoard.size() == 0)
        return false;
    int countLive = 0;
    for (auto item: subBoard)
        if (item == 1)
            countLive++;
    if (live) {
        if (countLive < 2 || countLive > 3)
            return false;
    } else {
        if (countLive == 3)
            return true;
    }
   return live;
}

void gameOfLife(vector<vector<int>>& board) {
    bool live;
    int m = board.size(), n = board[0].size();
    vector<vector<int>> res(m, vector<int>(n));
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            live = board[j][i];

            // 将board[j][i]四周的元素添加到subBoard
            vector<int> subBoard;
            // 添加上面一行
            if (j > 0) {
                if (i == 0 && i == n - 1)  //解决board只有一列元素的情况
                    subBoard.insert(subBoard.end(), {board[j - 1][i]});
                else {
                    if (i == 0)
                        subBoard.insert(subBoard.end(), {board[j - 1][i], board[j - 1][i + 1]});
                    else if (i > 0 && i < n - 1)
                        subBoard.insert(subBoard.end(), {board[j - 1][i - 1], board[j - 1][i], board[j - 1][i + 1]});
                    else
                        subBoard.insert(subBoard.end(), {board[j - 1][i - 1], board[j - 1][i]});
                }
            }

            // 添加中间一行
            if (i != 0 || i != n - 1) {  //排除board只有一个元素的情况
                if (i == 0)  //只有右边
                    subBoard.insert(subBoard.end(), {board[j][i + 1]});
                else if (i > 0 && i < n - 1)  //两边都有
                    subBoard.insert(subBoard.end(), {board[j][i - 1], board[j][i + 1]});
                else  // 只有左边
                    subBoard.insert(subBoard.end(), {board[j][i - 1]});
            }

            // 添加下面一行
            if (j < m - 1) {
                if (i == 0 && i == n - 1)  //解决board只有一列元素的情况
                    subBoard.insert(subBoard.end(), {board[j + 1][i]});
                else {
                    if (i == 0)
                        subBoard.insert(subBoard.end(), {board[j + 1][i], board[j + 1][i + 1]});
                    else if (i > 0 && i < n - 1)
                        subBoard.insert(subBoard.end(), {board[j + 1][i - 1], board[j + 1][i], board[j + 1][i + 1]});
                    else
                        subBoard.insert(subBoard.end(), {board[j + 1][i - 1], board[j + 1][i]});
                }

            }
            res[j][i] = judge(subBoard, live);
        }
    }
    board = res;
}

/*int main() {
    vector<vector<int>> board = {{1},{0},{0},{1},{0},{0},{1},{0},{0},{1}};
    gameOfLife(board);
    for (const auto &item: board) {
        for (auto i: item)
            cout << i << ' ';
        cout << endl;
    }
}*/
