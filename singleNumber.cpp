#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int fuZhu[60001];
    for (int i = -30000; i <= 30000; i++)
        fuZhu[i + 30000] = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (fuZhu[nums[i] + 30000] == -1)      // 还没访问过
            fuZhu[nums[i] + 30000] = 0;
        else if (fuZhu[nums[i] + 30000] == 0)  // 已经访问过
            fuZhu[nums[i] + 30000] = -2;
    }
    for (int i = -30000; i <= 30000; i++)
        if (fuZhu[i + 30000] == 0)
            return i;
    return 30001;
}
