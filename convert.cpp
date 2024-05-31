//
// Created by L1584 on 2024/5/31.
//

#include "iostream"
#include "vector"

using  namespace std;

string convert(string s, int numRows) {
    if (numRows == 1)
        return s;
    vector<string> res(numRows, "");
    bool turn = false;
    int n = s.length(), numRows_i = 1;

    //拆分每一行
    res[0].push_back(s[0]);
    for (int i = 1; i < n; i++) {
        res[numRows_i].push_back(s[i]);
        //向下走
        if (!turn) {
            if (numRows_i != numRows - 1)
                numRows_i++;
            else {  //遇到拐角改变方向，向上走
                turn = true;
                numRows_i--;
            }
        }
        // 向上走
        else {
            if (numRows_i != 0)
                numRows_i--;
            else {
                turn = false;
                numRows_i++;
            }
        }
    }

    //合并
    string convert_res;
    for (int i = 0; i < numRows; i++)
        convert_res += res[i];
    return convert_res;
}

/*
int main() {
    cout << convert("AB", 1);
    return 0;
}*/
