#include <iostream>
#include <vector>
using namespace std;    

/**
 * @brief 把num转换为二进制的逆序（只需考虑有几个0，1）
 * 
 * @param num 
 * @return vector<int> 
 */
vector<int> convertBinary(int num) {   
    vector<int> res;
    while (num >= 1) {
        res.push_back(num % 2);
        num /= 2;
    }
    return res;
}

int sumIndicesWithKSetBits(vector<int>& nums, int k) {
    int res = 0;   // 结果
    int index = 0;   // 下标
    for (int num: nums) {
        vector<int> binarys = convertBinary(index);
        int count = 0;   // 数有几个1
        for (int binary: binarys) {
            if (binary == 1)
                count++;
            if (count > k) 
                break;
        }
        if (count == k) 
            res += num;
        index++;
    }
    return res;
}

// int main () {
//     vector<int> nums = {5,10,1,5,2}; 
//     cout << sumIndicesWithKSetBits(nums, 1);
//     return 0;
// }