//
// Created by L1584 on 2024/5/27.
//

#include <vector>

using namespace std;

vector<vector<int>> res;
vector<int> subRes;

void dfs(vector<int>& candidates, int target, int index) {
    if (index == candidates.size())
        return;
    if (target == 0) {
        res.push_back(subRes);
        return;
    }

    // 跳过当前数，和下一位组合
    dfs(candidates, target, index + 1);

    // 不跳过，选择当前数继续组合
    if (target - candidates[index] >= 0) {
        subRes.push_back(candidates[index]);
        dfs(candidates, target - candidates[index], index);
        /**
         * 从上一步递归出来后，两种情况：
         * 1.subRes为空。
         * 2.target - candidates[index] < 0
         * 不管哪种情况，一定要弹出上一步压入subRes中的数字。
         */
        subRes.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    dfs(candidates, target, 0);
    return res;
}
