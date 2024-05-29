//
// Created by L1584 on 2024/2/20.
//

#include "iostream"
#include "vector"
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int width = matrix[0].size(), depth = matrix.size() - 1;
    int index = 0;
    while (res.size() < matrix[0].size() * matrix.size()) {
        for (int i = 0; i < width; i++)
            res.push_back(matrix[index][index + i]);
        width--;
        if (width < 0)
            break;
        for (int i = 0; i < depth; i++)
            res.push_back(matrix[i + index + 1][matrix[0].size() - index - 1]);
        depth--;
        if (depth < 0)
            break;
        for (int i = 0; i < width; i++)
            res.push_back(matrix[matrix.size() - 1 - index][matrix[0].size() - index - 2 - i]);
        width--;
        if (width < 0)
            break;
        for (int i = 0; i < depth; i++)
            res.push_back(matrix[matrix.size() - index - 2 - i][index]);
        depth--;
        index++;
    }
    return res;
}

//int main (){
//    vector<vector<int>> matrix = {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
//    vector<int> res = spiralOrder(matrix);
//    for (int i: res)
//        cout << i << " ";
//    return 0;
//}