// sqrt(x)  l-69
// -> √x 向下取整 
#include <iostream>
using namespace std;
int mySqrt(int x);

int main()
{
    int x=7; // intput
    int res=mySqrt(x); // output:2
    cout<<res<<endl;
    return 0;
}

int mySqrt(int x)
{
    int left=0, right=x/2;
    while (left<=right)
    {
        int mid=(left+right)/2;
        if ((long)mid*mid==x) 
            return mid;
        else if ((long)mid * mid > x)
            right=mid-1;
        else
            left=mid+1;
    }
    return left-1;
}