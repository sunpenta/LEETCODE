// 灯泡切换 - math  l-319
// 1 round: turn all on, 2 round: turn 2-th off; 3 round: toggle 3-th, ..., i round: toggle i-th;n⋿[0,1e9], 直接模拟TLE
#include <iostream>
#include <cmath>
using namespace std;
int bulbSwitch(int n);

int main()
{
    int n=5; // input;
    cout<<bulbSwitch(n)<<endl; // output:2
    return 0;
}
int bulbSwitch(int n)
{
    int i=1;
    for (; pow(i,2)<=n; i++) {}
    return i-1;
}