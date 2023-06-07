// sqrt(x)  l-69
// -> √x 向下取整 
#include <iostream>
using namespace std;
int sqrt(int x);

int main()
{
    int x=7; // intput
    int res=sqrt(x); // output:2
    cout<<res<<endl;
    return 0;
}

int sqrt(int x)
{
    int i=0;
    for (; i*i<=x; i++) {}
    return i-1;
}