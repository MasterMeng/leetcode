/*
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    if (nums.size() < 3)
        return res;

    sort(nums.begin(), nums.end());
    int length = nums.size();

    for (int first = 0; first < length; ++first)
    {
        if (first > 0 && nums[first] == nums[first - 1])
            continue;
        int third = length - 1;
        int target = -nums[first];

        for (int second = first + 1; second < length; ++second)
        {
            if (second > first + 1 && nums[second] == nums[second - 1])
                continue;
            while (second < third && nums[second] + nums[third] > target)
            {
                --third;
            }
            if (second == third)
                break;
            if (nums[second] + nums[third] == target)
                res.push_back({nums[first], nums[second], nums[third]});
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
