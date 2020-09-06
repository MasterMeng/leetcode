#include <iostream>
#include <unordered_map>

using std::cout;
using std::endl;
using std::unordered_map;

struct Node
{
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    };
};

class Solution
{
public:
    unordered_map<Node *, Node *> mp;
    // 待优化
    Node *copyRandomList(Node *node)
    {
        if (node == nullptr)
            return nullptr;
        if (mp.count(node))
            return mp[node]; //已创建过该节点

        Node *ans = new Node(node->val);
        mp[node] = ans; //老节点和新节点映射
        ans->next = copyRandomList(node->next);
        ans->random = copyRandomList(node->random);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
