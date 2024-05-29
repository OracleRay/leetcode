#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
 * 未完成
 */
vector<string> letterCombinations(string digits) {
    vector<string> res;
    if (digits.empty())
        return res;
    map<char, string> phoneMap{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    // 提取电话号码组合
    vector<string> combinations;
    for (int i = 0; i < digits.length(); i++)
        combinations.push_back(phoneMap.find(digits[i])->second);

    // 提取第一个组合中的字母
    for (char c: combinations[0]) {
        string resString;
        resString.push_back(c);
        res.push_back(resString);
    }

    // 与第一个组合的字母合并
    for (int i = 1; i < combinations.size(); i++) {
        int resIndex = 0;
        while (resIndex < res.size()) {
            if (res[resIndex].length() == i + 1)
                break;
            for (char c: combinations[i]) {
                res[resIndex].push_back(c);
                res.push_back(res[resIndex]);
                res[resIndex].pop_back();
            }
            resIndex++;
        }
        // 删除长度不合规的字符串
        for (int j = 0; j < res.size(); j++) {
            if (res[j].length() != i + 1) {
                res.erase(res.begin() + j);
                j--;
            }
        }
    }
    return res;
}

// int main() {
//     string digits = "234";
//     vector<string> s = letterCombinations(digits);
//     for (const auto & i : s)
//         cout << i << endl;
// }