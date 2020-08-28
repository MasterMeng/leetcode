#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if (digits.empty())
            return res;
        map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};
        string com;
        backtrack(res, phoneMap, digits, 0, com);
        return res;
    }
    void backtrack(vector<string> &coms, map<char, string> phoneMap, string digits, int index, string &com)
    {
        if (index == digits.size())
            coms.push_back(com);
        else
        {
            char digit = digits[index];
            string letters = phoneMap.at(digit);
            for (char letter : letters)
            {
                com.push_back(letter);
                backtrack(coms, phoneMap, digits, index + 1, com);
                com.pop_back();
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    auto res = solution.letterCombinations("23");
    for (auto re : res)
        cout << re << "\t";
    cout << endl;
    return 0;
}
