#include <iostream>
#include <unordered_set>
#include <vector>

using std::cout;
using std::endl;
using std::unordered_set;
using std::vector;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> num_set;
        for (auto num : nums)
            num_set.insert(num);
        int longest = 0;
        for (auto num : num_set)
        {
            if (!num_set.count(num - 1))
            {
                int cur = num;
                int step = 1;
                while (num_set.count(cur + 1))
                {
                    cur++;
                    step++;
                }
                longest = longest > step ? longest : step;
            }
        }
        return longest;
    }
};