// 完全平方根  l-367
#include <iostream>
using namespace std;
int isPerfectSquare(int num);

int main()
{
    int x=7; // intput
    bool res=isPerfectSquare(x); // output:false
    cout<<boolalpha<<res<<endl;
    return 0;
}

int isPerfectSquare(int num)
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
