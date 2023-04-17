// 除法-二分查找+快速乘  l-29
// 不能使用乘法、除法、取余运算；时间复杂度：O（logN)
#include <iostream>
#include <limits.h>
using namespace std;
int divide(int dividend, int divisor);

int main()
{
    int dividend = INT_MIN, divisor = 3; // 输入：被除数，除数
    int ans=divide(dividend,divisor);  //输出
    cout<<ans<<endl;
    system("pause");
}

int divide(int dividend, int divisor)
{
    // 被除数为最小值
    if (dividend == INT_MIN)
    {
        if (divisor == 1)
            return INT_MIN;
        if (divisor == -1)
            return INT_MAX;
    }
    // 除数为最小值
    if (divisor == INT_MIN)
        return dividend == INT_MIN ? 1 : 0;
    // 被除数为 0
    if (dividend == 0)
        return 0;
    
    /*
    // 特殊情况:
    // 被除数为0
    if (dividend==0) return 0;
    // 除数等于1,包含被除数为INT_MIN的情况
    if (divisor==1) return dividend;
    // 除数等于-1
    if (divisor==-1)
    {   
        if (dividend>INT_MIN)
            return -dividend;
        else   
            return INT_MAX; //被除数为INT_MIN的情况
    }
    */
    // 被除数，除数都变负
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
    if(dividend>divisor) return 0;
    // 快速乘：判断 z * y >= x 是否成立； x(被除数) 和 y(除数) 是负数，z是正数
    auto quickAdd = [](int x,int y, int z)
    {  
        // x(被除数) 和 y(除数) 是负数，z() 是正数   
        int result = 0, add = y;
        // z循环除2
        while (z)
        {   
            if (z & 1) // 奇数；z的二进制的最末位1，相当于if(n%2==1)
            {  
                // 保证 result + add >= x，防止溢出，用差来表示
                if (result < x - add) return false; // y<x
                result += add; // y
            }

            if (z != 1) 
            {
                // 保证 add + add >= x
                if (add < x - add)  return false;//y+y<x
                add += add; //2add
            }
            z >>= 1; // 按位右移1位，相当于/=2
        }
        return true;
    };
    
    // 二分查找
    int left = 1, right = INT_MAX, ans = 0;
    while (left <= right) // 注意溢出，不能用left+right；并且不能使用除法
    {
        int mid = left + ((right - left) >> 1); //等价于mid = (left + right)/2，1和INT_MAX的mid为偶数
        
        bool check = quickAdd(dividend,divisor, mid); //检查dividen<=divisor*mid是否成立
        if (check) 
        {
            ans = mid;
            if (mid == INT_MAX) break; // 防止溢出
            left = mid + 1; // mid一直为偶数
        }
        else 
            right = mid - 1; 
    }
    return rev ? -ans : ans;
}
