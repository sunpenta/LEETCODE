// 快速幂-迭代
// x ⋿(-100, 100), n ⋿ [INT_MIN, INT_MAX], xⁿ ⋿ [-1e4, 1e4]
#include <iostream>
using namespace std;
double pow(double x,int n);

int main()
{
    double x=4; long n=3; // 输入
    cout<<quickMul(x,n)<<endl; // 输出
    return 0;
}

double quickMul(double x,long n)
{
    double ans=1.0;
    while (n)
    {
        if (n%2==1) // n的最低位是1
            ans*=x;
        x*=x;
        n/=2;       
    }
    return ans;
}

double pow(double x,int n)
{
    if (n==0) return 1.0;
    long N=n; //INT_MIN变成整数会溢出
    return N>0? quickMul(x,N):1.0/quickMul(x,-N);
}
