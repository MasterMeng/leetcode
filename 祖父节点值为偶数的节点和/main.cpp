#include <iostream>

using std::cout;
using std::endl;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int ans;
    void dfs(int gpVal, int ppVal, TreeNode *root)
    {
        if (!root)
            return;
        if (gpVal % 2 == 0)
            ans += root->val;

        dfs(ppVal, root->val, root->left);
        dfs(ppVal, root->val, root->right);
    }
    int sumEvenGrandparent(TreeNode *root)
    {
        dfs(1, 1, root);
        return ans;
    }
};