#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    // 对齐补零
    int lenl1 = 1;
    int lenl2 = 1;
    ListNode *p = l1;
    ListNode *q = l2;
    while (p->next != NULL)
    {
        lenl1++;
        p = p->next;
    }
    while (q->next != NULL)
    {
        lenl2++;
        q = q->next;
    }

    if (lenl1 > lenl2)
    {
        for (int i = 0; i < lenl1 - lenl2; ++i)
        {
            q->next = new ListNode(0);
            q = q->next;
        }
    }
    if (lenl1 < lenl2)
    {
        for (int i = 0; i < lenl2 - lenl1; ++i)
        {
            p->next = new ListNode(0);
            p = p->next;
        }
    }

    // 开始计算
    bool flag = false;
    p = l1;
    q = l2;
    ListNode *l3 = new ListNode(-1);
    ListNode *w = l3;
    int sum = 0;

    while (p != NULL && q != NULL)
    {

        if (flag)
        {
            sum = p->val + q->val + 1;
        }
        else
        {
            sum = p->val + q->val;
        }

        w->next = new ListNode(sum % 10);
        flag = sum >= 10 ? true : false;
        p = p->next;
        q = q->next;
        w = w->next;
    }
    if (flag)
    {
        w->next = new ListNode(1);
    }
    return l3->next;
}

int main(int argc, char *argv[])
{
    ListNode *l1 = new ListNode(9);
    ListNode *p = l1;
    p->next = new ListNode(1);
    p = p->next;
    p->next = new ListNode(6);

    ListNode *l2 = new ListNode(0);

    ListNode *l3 = addTwoNumbers(l1, l2);

    while (l3 != NULL)
    {
        std::cout << l3->val;
        l3 = l3->next;
    }
    std::cout << std::endl;

    return 0;
}