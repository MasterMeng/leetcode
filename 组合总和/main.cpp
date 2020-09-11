#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> res;
        dfs(ans, res, candidates, target, 0);
        return ans;
    }

    void dfs(vector<vector<int>> &ans, vector<int> &res, vector<int> &candidates, int target, int index)
    {
        if (target == 0)
        {
            ans.push_back(res);
            return;
        }
        if (target < 0)
            return;
        // 
        for (int i = index; i < candidates.size(); ++i)
        {
            res.push_back(candidates[i]);
            dfs(ans, res, candidates, target - candidates[i], i); // 不使用i+1，是为了可以重复使用当前的值
            res.pop_back();
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> candidates{2, 3, 6, 7};
    Solution s;
    auto ret = s.combinationSum(candidates, 7);

    for (auto rs : ret)
    {
        for (auto i : rs)
        {
            cout << i << "\t";
        }
        cout << endl;
    }

    return 0;
}
