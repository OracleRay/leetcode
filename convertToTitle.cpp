#include <iostream>
#include <algorithm>
using namespace std;

string convertToTitle(int columnNumber) {
    string res = "";
    while (columnNumber >= 1) {
        int yuShu = columnNumber % 26;
        if (yuShu == 0)
            yuShu += 26;
        res.push_back((char)yuShu + 64);            
        columnNumber = (columnNumber - yuShu) / 26;
    }
    reverse(res.begin(), res.end());
    return res;
}

// int main() {
//     cout << convertToTitle(2147483647);

//     return 0;
// }