//
// Created by L1584 on 2024/2/16.
//

#include "iostream"
using namespace std;

int addDigits(int num) {
    if (num < 10)
        return num;
    int nextNum = 0;
    while (num >= 1) {
        nextNum += num % 10;
        num /= 10;
    }
    return addDigits(nextNum);
}

// int main (){
//    cout << addDigits(3829);
//    return 0;
// }
