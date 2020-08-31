#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Solution
{
public:
    string printBin(double num)
    {
        string res = "0.";
        int i = 30;
        while (num > 0 && i--)
        {
            num *= 2;
            if (num >= 1)
            {
                res += '1';
                --num;
            }
            else
            {
                res += '0';
            }
        }
        return num != 0 ? "ERROR" : res;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
