#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> res;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i)
    {
        m[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); ++i)
    {
        if (m.find(target - nums[i]) != m.end() && m[target - nums[i]] != i)
        {
            res.push_back(i);
            res.push_back(m[target - nums[i]]);
            break;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    int target = 9;

    vector<int> res = twoSum(nums, target);
    for (auto i : res)
    {
        cout << i << endl;
    }
    return 0;
}
