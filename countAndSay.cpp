//
// Created by L1584 on 2024/5/31.
//

#include "iostream"

using namespace std;

string countAndSay(int n) {
    string res = "1";
    if (n == 1)
        return res;
    for (int i = 1; i < n; i++) {
        int count = 1, len = res.length();

        //将res进行行程长度编码
        string temp_res;
        for (int j = 1; j < len; j++) {
            if (res[j] == res[j - 1])
                count++;
            else {
                temp_res.push_back((char) ('0' + count));
                temp_res.push_back(res[j - 1]);
                count = 1;
            }
        }

        //添加最后一部分
        if (count == 1)
            temp_res.push_back((char) ('1'));
        else
            temp_res.push_back((char)('0' + count));
        temp_res.push_back(res[len - 1]);

        //赋值
        res = temp_res;
    }
    return res;
}

/*
int main() {
    cout << countAndSay(4);
    return 0;
}*/
