#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<string> getValidT9Words(string num, vector<string> &words)
{
    vector<char> table = {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5', '6', '6', '6', '7', '7', '7', '7', '8', '8', '8', '9', '9', '9', '9'};

    int length = num.size();
    int i;
    vector<string> res;
    for (auto word : words)
    {
        if (length != words.size())
            continue;
        for (i = 0; i < length; ++i)
            if (table[word[i] - 'a'] != num[i])
                break;
        if (i == length)
            res.emplace_back(word);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
