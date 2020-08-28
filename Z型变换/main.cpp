/*
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G
*/
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string convert(string s, int numRows)
{
    if (numRows == 1)
        return s;

    int n = s.size();
    string ret;
    int zlen = 2 * (numRows - 1);
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; i + j < n; j += zlen)
        {
            ret += s[j + i];
            if (i != 0 && i != numRows - 1 && j + zlen - i < n)
                ret += s[j + zlen - i];
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
    string s = "LEETCODEISHIRING";
    int numRows = 3;
    string ret = convert(s, numRows);
    cout << ret << endl;
    s = "LEETCODEISHIRING";
    numRows = 4;
    cout << convert(s, numRows) << endl;
    return 0;
}
