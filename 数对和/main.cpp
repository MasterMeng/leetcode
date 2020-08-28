/*
设计一个算法，找出数组中两数之和为指定值的所有整数对。一个数只能属于一个数对。

示例 1:

输入: nums = [5,6,5], target = 11
输出: [[5,6]]
示例 2:

输入: nums = [5,6,5,6], target = 11
输出: [[5,6],[5,6]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pairs-with-sum-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

vector<vector<int>> pairSums(vector<int> &nums, int target)
{
    vector<vector<int>> res;
    if (nums.size() < 2)
        return res;

    sort(nums.begin(), nums.end());
    int left = 0;
    int right = nums.size() - 1;
    int sum = 0;
    while (left < right)
    {
        sum = nums.at(left) + nums.at(right);
        if (sum > target)
            --right;
        else if (sum < target)
            ++left;
        else
        {
            res.push_back(vector<int>{nums.at(left), nums.at(right)});
            ++left;
            --right;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> nums{5, 6, 5};
    int target = 11;
    auto res = pairSums(nums, target);

    for (auto re : res)
    {
        for (auto i : re)
            cout << i << "\t";
        cout << endl;
    }
    nums.push_back(6);
    res = pairSums(nums, target);

    for (auto re : res)
    {
        for (auto i : re)
            cout << i << "\t";
        cout << endl;
    }
    return 0;
}
