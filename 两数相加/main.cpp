#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> s1, s2;
        while (l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode *ret = nullptr;
        int carry = 0;
        while (!s1.empty() || !s2.empty() || carry != 0)
        {
            int a = s1.empty() ? 0 : s1.top();
            int b = s2.empty() ? 0 : s2.top();
            if (!s1.empty())
                s1.pop();
            if (!s2.empty())
                s2.pop();
            int cur = a + b + carry;
            carry = cur / 10;
            cur %= 10;
            auto curnode = new ListNode(cur);
            curnode->next = ret;
            ret = curnode;
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
