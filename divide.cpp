#include <iostream>

using namespace std;

int towNumDivide(int dividend, int divisor) {
    if (dividend < 0)
        return -1;
    return  towNumDivide(dividend - divisor, divisor) + 1;
}

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN) {
        if (divisor == 1) {
            return INT_MIN;
        }
        if (divisor == -1) {
            return INT_MAX;
        }
    }
    if (divisor == INT_MIN) {
        return dividend == INT_MIN ? 1 : 0;
    }
    // 考虑被除数为 0 的情况
    if (dividend == 0) {
        return 0;
    }
    bool positive = false;
    if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
        positive = true;
    int res = towNumDivide(abs(dividend), abs(divisor));
    if (!positive)
        return -res;
    else
        return res;
}

//int main() {
//    cout << divide(-2147483648, -1);
//}