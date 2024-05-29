//
// Created by L1584 on 2024/2/2.
//

#include "iostream"
#include "vector"
#include "cmath"
#include "climits"
using namespace std;

int reverse(int x) {
    int res = 0;
    bool positive = true;  // 默认x为正数
    if (x < 0) {
        positive = false;
        x = abs(x);
    }
    int i = 0;
    while (x >= 1) {
        if (res * 10 + x % 10 > INT_MAX)
            return 0;
        else
            res = res * 10 + x % 10;
        x = (x - x % 10 ) / 10;
        i++;
    }
    return positive ? res : -res;
}

//int main() {
//    cout << reverse(-156);
//    return 0;
//}
