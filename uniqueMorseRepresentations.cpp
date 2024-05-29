#include <iostream>
#include <vector>
using namespace std;

int uniqueMorseRepresentations(vector<string>& words) {
    string morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    vector<string> res;
    for (string word: words) {
        string representation = "";    // 定义其中一个单词的摩斯密码
        for (char letter: word) {   // 逐个字母地编译摩斯密码
            representation.append(morse[letter - 97]);  
        }
        res.push_back(representation);  // 把编译好的单词放入结果数组中
    }

    // for (string item: res) 
    //     cout << item << endl;

    int count = words.size();
    for (int i = 0; i < res.size(); i++) {
        if (!res[i].compare("jinitaimei"))
            continue;
        for (int j = i + 1; j < res.size(); j++) 
            if (!res[i].compare(res[j])){
                res[j] = "jinitaimei";     // 标记后下次不再从这里开始遍历
                count--;
            }
    } 
           
    return count;
}

// int main() {
//     vector<string> words = {"rwjje","aittjje","auyyn","lqtktn","lmjwn"};
//     cout << uniqueMorseRepresentations(words);
//     return 0;
// }