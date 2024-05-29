//
// Created by L1584 on 2024/2/24.
//

#include <vector>
#include "iostream"

using namespace std;

int hammingDistance(int x, int y) {
    vector<int> bin1, bin2;
    int res = 0;
    while (x > 0) {
        bin1.push_back(x % 2);
        x = (x - x % 2) / 2;
    }
    while (y > 0) {
        bin2.push_back(y % 2);
        y = (y - y % 2) / 2;
    }
    int index = 0;
    while (index < bin1.size() && index < bin2.size()) {
        res += bin1[index] ^ bin2[index];
        index++;
    }
    while (index < bin1.size()) {
        res += bin1[index] ^ 0;
        index++;
    }
    while (index < bin2.size()) {
        res += 0 ^ bin2[index];
        index++;
    }
    return res;
}

//int main() {
//    cout << hammingDistance(1, 4);
//    return 0;
//}