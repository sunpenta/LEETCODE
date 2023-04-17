// x的平方根 - 二分查找 l-69
// 结果只保留整数部分，小数部分舍去; 时间复杂度：O（logN)
#include <iostream>
using namespace std;
int sqrt(int x);

int main()
{
    int x=7; // 输入
    cout<<sqrt(x)<<endl; // 输出
    system("pause");
}

int sqrt(int x)
{
    // 特殊情况：避免x/mid无效
    if (x==0 || x==1) return x;
    int left=0; int right=x;
    while (left<right)
    {
        int mid=left+(right-left)/2; // 注意溢出
        if (mid==x/mid) return mid;
        else if (mid<x/mid)
        {
            left=mid+1;
        }
        else
        {
            right=mid;
        }
    }
    return left-1; // left是平方大于x的第1个数，只保留整数部分，那么left-1
}