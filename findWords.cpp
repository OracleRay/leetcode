#include <iostream>
#include <vector>
using namespace std;

vector<char> findLine(char letter) {
    vector<char> firstLine = {'q','w','e','r','t','y','u','i','o','p'};
    vector<char> secondLine = {'a','s','d','f','g','h','j','k','l'};
    vector<char> thirdLind = {'z','x','c','v','b','n','m'};

    for (char keyboardLetter: firstLine) 
        if (keyboardLetter == letter)
            return firstLine;

    for (char keyboardLetter: secondLine) 
        if (keyboardLetter == letter)
            return secondLine;

    for (char keyboardLetter: thirdLind) 
        if (keyboardLetter == letter)
            return thirdLind;

    return firstLine;
}

vector<string> findWords(vector<string>& words) {
    vector<string> res;

    for (string word: words) {   // 遍历给定的几个单词
        vector<char> line = findLine((char)tolower(word[0]));
        int j = 1;    // 从这个单词的第二个字母开始遍历
        while (j < word.length()) {      // 遍历每个单词的字母
            int i = 0;
            while (i < line.size()) {       // 遍历键盘上的那一行
                if ((char)tolower(word[j]) == line[i])
                    break;
                i++;
            }
            if (i == line.size())
                break;
            j++;
        }
        if (j == word.length())
            res.push_back(word);
    }

    return res;
}


// int main() {
//     vector<string> words = {"Hello","AlasKa","Dad","Peace"};
//     vector<string> res = findWords(words);

//     for (string word: res) {
//         cout << word << endl;
//     }

//     return 0;
// }