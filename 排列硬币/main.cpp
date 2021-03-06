#include <cmath>
#include <iostream>
using namespace std;

/*
你总共有 n 枚硬币，你需要将它们摆成一个阶梯形状，第 k 行就必须正好有 k 枚硬币。

给定一个数字 n，找出可形成完整阶梯行的总行数。

n 是一个非负整数，并且在32位有符号整型的范围内。

示例 1:

n = 5

硬币可排列成以下几行:
¤
¤ ¤
¤ ¤

因为第三行不完整，所以返回2.
示例 2:

n = 8

硬币可排列成以下几行:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

因为第四行不完整，所以返回3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/arranging-coins
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int arrangeCoins(int n)
{
    //思路
    // 可转化为等差数列求和问题，之后一元二次方程求解
    // $\frac{k(k+1)}{2} = n$
    // $x = \frac{-b \pm \sqrt{b^2-4ac}}{2}$
    return int(float(sqrt(1 + 8 * (unsigned long long)n) - 1.0) / 2.0);
}

int main(int argc, char const *argv[])
{
    int k = arrangeCoins(25);
    cout << k << endl;
    return 0;
}
