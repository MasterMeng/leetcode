#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> cs;
    int rk = -1;
    int ans = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (i != 0)
        {
            cs.erase(s[i - 1]);
        }
        while (rk + 1 < s.size() && !cs.count(s[rk + 1]))
        {
            cs.insert(s[rk + 1]);
            ++rk;
        }
        ans = max(ans, rk - i + 1);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    string s = "abcaabcc";
    int n = lengthOfLongestSubstring(s);
    cout << n << endl;
    return 0;
}
