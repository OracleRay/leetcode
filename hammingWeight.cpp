#include <iostream>
#include <bitset>
#include <cstdint>
using namespace std;

int hammingWeight(uint32_t n) {
    if (n / 32 == 1)
        n = (int32_t) n;
    int weight, count = 0;
    for (int i = 0; i < 32; i++) {
        weight = n % 2;
        if (weight == 1) 
            count++;
        n /= 2;
    }
    return count;
}
