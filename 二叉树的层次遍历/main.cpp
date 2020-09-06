#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::queue;
using std::vector;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> level;
            int length = q.size();
            for (int i = 0; i < length; ++i)
            {
                auto node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            res.push_back(level);
        }
        // // 自低向上输出
        // reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
