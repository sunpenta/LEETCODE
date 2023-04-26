// 数字的各位之和   l-258
// 把数字的各位累加，直到和为1位数字
#include <iostream>
using namespace std;
int addDigits(int num);

int main()
{
    int num=38; // input
    cout<<addDigits(num)<<endl;
    return 0;
}
int addDigits(int num)
{
    int sum=0;
    while (num>0)
    {
        sum+=num*10;
        num/=10;
        if (num==0 && sum>9)
        {
            num=sum;
            sum=0;
        }
    }
    return sum;
}