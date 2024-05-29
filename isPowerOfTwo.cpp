//
// Created by L1584 on 2024/2/25.
//

#include "cmath"

bool isPowerOfTwo(int n) {
    for (int i = 0; i < pow(2, 32); i++) {
        if (n == pow(2, i))
            return true;
        else if (n < pow(2, i))
            break;
    }
    return false;
}