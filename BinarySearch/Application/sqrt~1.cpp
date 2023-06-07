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
    int i=0;
    for (; (long)i*i<=x; i++) {}
    return i-1;
}