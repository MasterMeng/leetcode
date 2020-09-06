#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using std::cout;
using std::deque;
using std::endl;
using std::vector;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        deque<int> tmp;

        for (int i = 0; i <= nums.size(); ++i)
        {
            while (!tmp.empty() && nums[i] > nums[tmp.back()])
            {
                tmp.pop_back();
            }
            if (!tmp.empty() && tmp.front() < i - k + 1)
                tmp.pop_front();

            tmp.push_back(i);
            if (i >= k - 1)
                res.push_back(nums[tmp.front()]);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> res = s.maxSlidingWindow(nums, 3);
    for (auto i : res)
        cout << i << "\t";
    cout << endl;
    return 0;
}
