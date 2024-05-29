#include <iostream>
#include <string.h>
using namespace std;

int strStr(string haystack, string needle) {
    const char *hay = haystack.c_str();
    const char *need = needle.c_str();
    int i = 0, j;
    while (i < strlen(hay)) {
        j = 0;
        while (j < strlen(need)) {
            if (hay[i] == need[j]) 
                i++;
            else {
                i = i - j;
                break;
            }
            j++;
        }
        if (j == strlen(need)) {
            if (hay[i-1] == need[j-1])
                return i - j;
            else 
                return -1;
        }
        i++;
    }
    return -1;
}




