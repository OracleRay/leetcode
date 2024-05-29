//
// Created by L1584 on 2024/2/2.
//

#include "iostream"
#include "climits"
using namespace std;

int myAtoi(string s) {
    int res = 0;
    bool positive = true, positiveSignal = false, negativeSignal = false;  // 默认为正数且没有符号;
    bool begin = false;   // 确认数字是否开始
    for (char c: s) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '.') {
            if (begin)    //已经开始遍历了但是扫描到字母或小数点，直接返回
                return positive ? res : -res;
            else             // 还没开始就遍历到了字母，直接返回0
                return 0;
        }
        if (c == '+' || c == '-') {
            if (positiveSignal || negativeSignal)
                return 0;   // 已经出现过正负号，返回0
            if (c == '+')
                positiveSignal = true;
            if (c == '-') {
                negativeSignal = true;
                positive = false;   // 结果为负数
            }
        }
        if (c >= '0' && c <= '9') {
            begin = true;
            if ((long long)res * 10 +  (int) c - 48 > INT_MAX)    // 防止越界
                return positive ? INT_MAX : -INT_MAX - 1;
            else
                res = res * 10 +  (int) c - 48;
        }
    }
    return positive ? res : -res;
}

//int main() {
//    int res = myAtoi("21474836460");
//    cout << res;
//    return 0;
//}