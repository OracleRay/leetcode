//
// Created by L1584 on 2024/2/25.
//

#include "iostream"
#include "vector"

using namespace std;

bool isUgly(int n) {
    if (n <= 0)
        return false;
    else if (n == 1)
        return true;
    while (n > 1) {
        if (n % 2 == 0)
            n /= 2;
        else if (n % 3 == 0)
            n /= 3;
        else if (n % 5 == 0)
            n /= 5;
        else
            return false;
    }
    return true;
}