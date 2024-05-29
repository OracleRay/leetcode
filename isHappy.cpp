//
// Created by L1584 on 2024/2/17.
//
#include <vector>
#include <cmath>
#include "iostream"
using namespace std;

bool isHappy(int n) {
    vector<int> singleNum;
    for (int i = 0; i < 10 && n != 1; i++) {  // 限制循环次数
        if (i == 9)
            return false;
        int nextN = 0;
        while (n >= 1) {
            nextN += (int)pow(n % 10, 2);
            n /= 10;
        }
        n = nextN;
    }
    return true;
}

//int main (){
//    cout << isHappy(19);
//    return 0;
//}
