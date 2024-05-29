//
// Created by L1584 on 2024/2/16.
//

#include <cmath>
#include "iostream"
using namespace std;

/**
 * int转string
 * @param num
 * @return
 */
string convertInteger(int num) {
    if (num < 1)
        return "";
    int yuShu = num % 10;
    num /= 10;
    return convertInteger(num) + to_string(yuShu);
}

string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
        return "0";
    }
    // 计算num1*num2
    int convertNum1 = 0, convertNum2 = 0;
    for (int i = num1.length() - 1; i > -1; i--)
        convertNum1 += (num1[i] - '0') * pow(10, num1.length() - i - 1);
    for (int i = num2.length() - 1; i > -1; i--)
        convertNum2 += (num2[i] - '0') * pow(10, num2.length() - i - 1);
    int resNum = convertNum2 * convertNum1;
    // 把结果转换为string
    return convertInteger(resNum);;
}

//int main (){
//    cout << multiply("123", "3");
//    return 0;
//}