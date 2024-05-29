//
// Created by L1584 on 2024/2/23.
//

#include <cstdint>
#include "vector"
#include "iostream"
#include "cmath"

using namespace std;

uint32_t reverseBits(uint32_t n) {
    vector<uint32_t> bits;
    uint32_t res = 0;
    while (n >= 1) {
        bits.push_back(n % 2);
        n = (n - (n % 2)) / 2;
    }
    for (int i = 0; i < bits.size(); i++)
        res += bits[i] * pow(2,  31 - i);
    return res;
}

//int main(){
//    uint32_t n = 43261596;
//    cout << reverseBits(n);
//    return 0;
//}