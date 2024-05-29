//
// Created by L1584 on 2024/2/21.
//

#include "iostream"
#include "vector"
using namespace std;

/**
 * 未做出
 * @param board
 * @param word
 * @return
 */

bool exist(vector<vector<char>>& board, string word) {
    int w = 0, b1 = 0;
    while (b1 < board.size()) {
        int b2 = 0, temp_b2 = 0, temp_b1 = b1;
        while (temp_b1 < board.size()) {     // 先横着走
            if (word[w] == board[temp_b1][temp_b2]) {
                w++;
                temp_b2++;
            } else {
                temp_b1++;
            }
            if (temp_b1 == board.size()) {
                w = 0;
                b2++;
                temp_b2 = b2;
            }
        }
        b1++;
        if (w == word.size() - 1)
            return true;
    }
    return false;
}

//int main() {
//    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','F'}};
//    string word = "ABCCED";
//    cout << exist(board, word);
//    return 0;
//}