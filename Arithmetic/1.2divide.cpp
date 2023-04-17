// 除法-类二分查找  l-29
// 不能使用乘法、除法、取余运算; 时间复杂度：O（logN)
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int divide(int dividend, int divisor);

int main()
{
    int dividend = INT_MIN, divisor = 3; // 输入：被除数，除数
    int ans=divide(dividend,divisor);  //输出
    cout<<ans<<endl;
    return 0;
}

int divide(int dividend, int divisor)
{
    // 考虑被除数为最小值的情况
    if (dividend == INT_MIN)
    {
        if (divisor == 1)
            return INT_MIN;
        if (divisor == -1)
            return INT_MAX;
    }
    // 考虑除数为最小值的情况
    if (divisor == INT_MIN)
        return dividend == INT_MIN ? 1 : 0;
    // 考虑被除数为 0 的情况
    if (dividend == 0)
        return 0;
    
    // 将所有的正数取相反数，这样就只需要考虑一种情况
    bool rev = false;
    if (dividend > 0)
    {
        dividend = -dividend;
        rev = !rev;
    }
    if (divisor > 0)
    {
        divisor = -divisor;
        rev = !rev;
    }

    vector<int> candidates = {divisor};
    // 注意溢出
    while (candidates.back() >= dividend - candidates.back())
        candidates.push_back(candidates.back() + candidates.back());

    int ans = 0;
    for (int i = candidates.size() - 1; i >= 0; --i)
    {
        if (candidates[i] >= dividend)
        {
            ans += (1 << i);
            dividend -= candidates[i];
        }
    }
    return rev ? -ans : ans;
}