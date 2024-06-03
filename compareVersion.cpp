//
// Created by L1584 on 2024/6/3.
//

#include <vector>
#include "iostream"

using namespace std;

/**
 * 分割字符串后再用stoi函数转为整形
 * @param str
 * @return
 */
vector<int> split(string &str) {
    int n = str.size(), slow = 0;
    vector<int> res;
    for (int fast = slow; fast < n; fast++) {
        if (fast == n - 1 || str[fast + 1] == '.') {
            //将分割出来的子串转为整形后再压入res
            res.push_back(stoi(str.substr(slow, fast - slow + 1)));
            slow = fast + 2;
        }
    }
    return res;
}

int compareVersion(string version1, string version2) {
    vector<int> v1 = split(version1), v2 = split(version2);
    int n1 = v1.size(), n2 = v2.size();

    //先比较前面等长的部分
    int i = 0;
    while (i < n1 && i < n2) {
        if (v1[i] < v2[i])
            return -1;
        else if (v1[i] > v2[i])
            return 1;
        i++;
    }

    /**
     * 若前面都相等，剩下一个版本号的后面部分都是0，则返回0，否则返回-1/1；
     * 两个循环只执行一个
     */
    while (i < n1) {
        if (v1[i] != 0)
            return 1;
        i++;
    }
    while (i < n2) {
        if (v2[i] != 0)
            return -1;
        i++;
    }
    return 0;
}

/*
int main() {
    string version1 = "1.01", version2 = "1.001";
    */
/*vector<int> s = split(version2);
    for (const auto &item: s)
        cout << item << ' ';*//*

    cout << compareVersion(version1, version2);
}*/
