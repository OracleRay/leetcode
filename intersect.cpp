//
// Created by L1584 on 2024/3/22.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    int i = 0, j = 0, n = nums1.size(), m = nums2.size();
    vector<int> res;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    while (i < n && j < m) {
        if (nums1[i] < nums2[j])
            i++;
        else if (nums1[i] > nums2[j])
            j++;
        else {
            res.push_back(nums1[i]);
            i++;
            j++;
        }
    }
    return res;
}

//int main() {
//    vector<int> nums1 = {1,2,2,1};
//    vector<int> nums2 = {2,2};
//    vector<int> res = intersect(nums1, nums2);
//    for (int item: res)
//        cout << item << ' ';
//}