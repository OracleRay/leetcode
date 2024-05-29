#include <iostream>
#include <math.h>
using namespace std;

int titleToNumber(string columnTitle) {
    int number = 0;
    for (int i = columnTitle.size() - 1; i >= 0; i--)
        number += (columnTitle[i] - 64) * pow(26, columnTitle.size() - 1 - i);
    return number;
}