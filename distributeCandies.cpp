//
// Created by L1584 on 2024/2/22.
//

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int distributeCandies(vector<int>& candyType) {
    int count = 1;      // 数有几块糖
    sort(candyType.begin(), candyType.end());
    for (int i = 1; i < candyType.size(); i++)
        if (candyType[i] != candyType[i-1])
            count++;
    return count > candyType.size() / 2 ? candyType.size() / 2 : count;
}

//int main() {
//    vector<int> candyType = {1,1,2,3};
//    cout << distributeCandies(candyType);
//    return 0;
//}