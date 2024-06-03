//
// Created by L1584 on 2024/6/3.
//

#include <unordered_map>
#include "iostream"

using namespace std;

string getHint(string secret, string guess) {
    int bulls = 0, cows = 0, n = secret.size();
    unordered_map<char, int> map;  //记录每个字符出现的次数

    //第一次遍历统计公牛数量
    for (int i = 0; i < n; i++) {
        map[secret[i]] = map.find(secret[i]) == map.end() ? 1 : map[secret[i]] + 1;
        if (secret[i] == guess[i]) {
            bulls++;
            map[secret[i]]--;
            guess[i] = 'p';  //guess[i]不作为后续继续统计对象
        }
    }

    //第二次遍历统计奶牛数量
    for (int i = 0; i < n; i++) {
        if (map.find(guess[i]) != map.end() && map[guess[i]] != 0 && guess[i] != 'p') {
            cows++;
            map[guess[i]]--;
        }
    }
    return to_string(bulls) + "A" + to_string(cows) + "B";
}

/*
int main() {
    string secret = "11", guess = "10";
    cout << getHint(secret, guess);
}*/
