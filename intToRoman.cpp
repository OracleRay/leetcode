#include <iostream>
using namespace std;

string intToRoman(int num) {
    string roman[7] = {"I", "V", "X", "L", "C", "D", "M"};
    string res;
    for (int i = 0; i < 7 && num > 0; i += 2) {
        int yuShu = num % 10;
        if (yuShu < 4) 
            for (int j = 0; j < yuShu; j++)
                res.insert(0, roman[i]);
        else if (yuShu == 4) {
            res.insert(0, roman[i + 1]);
            res.insert(0, roman[i]);
        } else if (yuShu > 4 && yuShu < 9) {
            for (int j = 0; j < yuShu - 5; j++) 
                res.insert(0, roman[i]);
            res.insert(0, roman[i + 1]);     
        } else if (yuShu == 9 && i + 2 < 7) {
            res.insert(0, roman[i + 2]);
            res.insert(0, roman[i]);
        } 
        num /= 10;    
    }
    return res;
}