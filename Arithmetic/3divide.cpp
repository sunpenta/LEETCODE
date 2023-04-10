// 两数相除-二分查找+快速乘  l-29
// 不能使用乘法、除法、取余运算,在int范围内；注意边界溢出，int范围：-2^31(INT_MIN) - 2^31-1
#include <bits/stdc++.h>
using namespace std;
// dividend/int divisor=商，整除
int divide(int dividend,int divisor)
{
    // 特殊情况:
    //被除数为0
    if (dividend==0) return 0;
    //除数等于1,包含被除数为INT_MIN的情况
    if (divisor==1) return dividend;
    //除数等于-1
    if (divisor==-1)
    {   
        if (dividend>INT_MIN)
            return -dividend;
        else   
            return INT_MAX; //被除数为INT_MIN的情况
    }

    // 一般情况：
    // 将所有的正数取相反数，这样就只需要考虑一种情况,记录正负号？
    bool rev = true;
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
    // 被除数>除数，商为0，包含除数为INT_MIN的情况
    if(dividend>divisor) return 0;
   
    // 快速乘-需要判断 z * y >= x 是否成立，Lambda表达式
    // x(被除数) 和 y(除数) 是负数，z是正数
    auto quickAdd = [](int x, int y, int z) 
    { 
        int result = 0, add = y;
        // z循环除2
        while (z)
        {
            // 按位与，z的二进制的最末位为1，结果就不是0，为true。相当于if(n%2==1)
            if (z & 1)
            { 
                // 需要保证 result + add >= x，防止溢出，用差来表示
                if (result < x - add) return false;   // y<x
                result += add; // y
            }
            //z的二进制数不是最后1位
            if (z != 1)
            {
                // 需要保证 add + add >= x
                if (add < x - add) return false; // y+y<x
                add += add;  // 2add
            }
            z >>= 1; // 不能使用除法，按位右移1位，相当于/2
        }
        return true;
    };

    // 二分查找
    int left = 1, right = INT_MAX, ans = 0;
    while (left <= right)
    {
        // 注意溢出，不能用left+right；且不能使用除法,等价于mid = (left + right)/2
        int mid = left + ((right - left) >> 1);
        bool check = quickAdd(dividend, divisor, mid); // 检查dividen<=divisor*mid是否成立
        if (check)
        {
            ans = mid;
            if (mid == INT_MAX) break;    // 防止溢出
            left = mid + 1; 
        }
        else
            right = mid - 1;
    }
    return rev ? ans : -ans;
}
int main()
{
    int dividend = INT_MIN, divisor = 3; // 输入：被除数，除数
    int ans=divide(dividend,divisor);  //输出
    cout<<ans<<endl;
    system("pause");
}