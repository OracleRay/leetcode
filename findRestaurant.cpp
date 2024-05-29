#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    vector<string> res;
    int index1 = 0, index2;    // 两个链表的下标
    int minIndex = INT32_MAX;   // 记录最小下标之和
    while (index1 < list1.size()) {
        index2 = 0;
        while (index2 < list2.size()) {
            if (!list1[index1].compare(list2[index2])) {
                if (index1 + index2 < minIndex) {
                    minIndex = index1 + index2;   // 更新minIndex
                    res.clear();    // 清空之前的饭店名称
                    res.push_back(list2[index2]);
                } else if (index1 + index2 == minIndex)
                    res.push_back(list2[index2]);    
                break;
            }
            index2++;
        }
        index1++;
    }
    return res;
}

// int main() {
//     vector<string> list1 = {"happy","sad","good"};
//     vector<string> list2 = {"sad","happy","good"};
//     vector<string> res = findRestaurant(list1, list2);
//     for (string item: res) 
//         cout << item << endl;
//     return 0;
// }