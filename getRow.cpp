#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex) {
    if (rowIndex == 0)
        return {1};
    vector<vector<int>> yangHui;
    vector<int> newRowYangHui;    //下一行
    yangHui.push_back({1});
    for (int i = 0; i < rowIndex; i++) {
        vector<int> oldRowYangHui = yangHui[0];      //上一行
        yangHui.clear();     //清除之前的结果
        newRowYangHui = {1};
        for (int j = 1; j < oldRowYangHui.size(); j++)
            newRowYangHui.push_back(oldRowYangHui[j - 1] + oldRowYangHui[j]);   //生成下一行元素
        newRowYangHui.push_back({1});
        yangHui.push_back(newRowYangHui);
    }
    return newRowYangHui;
}

//int main() {
//    vector<int> res = getRow(0);
//    for (int item: res)
//        cout << item << " ";
//    return 0;
//}