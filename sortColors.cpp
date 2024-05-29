//
// Created by L1584 on 2024/2/14.
//

#include "iostream"
#include "vector"

using namespace std;

void sortColors(vector<int>& nums) {
    int countRed = 0, countWhite = 0, countBlue = 0;
    for (int color: nums) {
        switch (color) {
            case 0:
                countRed++;
                break;
            case 1:
                countWhite++;
                break;
            case 2:
                countBlue++;
                break;
            default:
                break;
        }
    }
    int index = 0;
    for (; index < countRed; index++)
        nums[index] = 0;
    for (; index < countRed + countWhite; index++)
        nums[index] = 1;
    for (; index < countRed + countWhite + countBlue; index++)
        nums[index] = 2;
}

//int main (){
//    vector<int> nums = {2,0,1};
//    sortColors(nums);
//    for (int color: nums)
//        cout << color << " ";
//    return 0;
//}