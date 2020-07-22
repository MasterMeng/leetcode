#include <iostream>
#include <limits.h>
#include <string>

using std::cout;
using std::endl;
using std::string;

int reverse(int x)
{
    int ret = 0;
    while (x != 0)
    {
        int pop = x % 10;
        x /= 10;
        if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && pop > 7))
            return 0;
        if (ret < INT_MIN / 10 || (ret == INT_MIN / 10 && pop < -8))
            return 0;
        ret = ret * 10 + pop;
    }
    return ret;
}

int myAtoi(string str)
{
    int n = str.size();
    long ret = 0;
    bool negative = false;
    int index = 0;
    while (index < n && str[index] == ' ')
        index++;
    if (str[index] == '-')
    {
        negative = true;
        index++;
    }
    else if (str[index] == '+')
        index++;
    if (str[index] > '9' || str[index] < 0)
        return 0;

    while (index < n && (str[index] >= '0' && str[index] <= '9'))
    {
        ret = ret * 10 + str[index] - '0';
        if (ret - 1 > INT_MAX)
            break;
        index++;
    }

    if (negative)
        ret = 0 - ret;
    if (ret > INT_MAX)
        return INT_MAX;
    if (ret < INT_MIN)
        return INT_MIN;
    return ret;
}

int main(int argc, char const *argv[])
{
    int ret = myAtoi("42");
    cout << ret << endl;
    return 0;
}
