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
/* 第i轮后，前i个灯泡不变；经奇数次切换，最终是ON，例[ON][ON,OFF,ON], 经偶数次切换，最终是OFF，例[ON,OFF][ON,OFF,ON,OFF]
   结果是有奇数次切换的round/position数，即有奇数个除数的个数，即有完全平方根的个数（例，1[1,1]奇 3[1,3]偶 4[1,4][2,2]奇） */
int bulbSwitch(int n)
{
    int i=1;
    for (; pow(i,2)<=n; i++) {}
    return i-1;
}