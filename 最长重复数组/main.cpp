#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// 滑动窗口
class Solution
{
public:
    int maxLength(vector<int> &A, vector<int> &B, int addA, int addB, int len)
    {
        int ret = 0, k = 0;
        for (int i = 0; i < len; i++)
        {
            if (A[addA + i] == B[addB + i])
            {
                k++;
            }
            else
            {
                k = 0;
            }
            ret = ret > k ? ret : k;
        }
        return ret;
    }

    int findLength(vector<int> &A, vector<int> &B)
    {
        int n = A.size(), m = B.size();
        int ret = 0;
        for (int i = 0; i < n; ++i)
        {
            int len = m < n - i ? m : n - i;
            int maxLen = maxLength(A, B, i, 0, len);
            ret = ret > maxLen ? ret : maxLen;
        }
        for (int i = 0; i < m; ++i)
        {
            int len = n < m - i ? n : m - i;
            int maxLen = maxLength(A, B, 0, i, len);
            ret = ret > maxLen ? ret : maxLen;
        }
        return ret;
    }
};