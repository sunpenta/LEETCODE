// 二进制最多重复1
#include <bits/stdc++.h>
using namespace std;
int max_continous1(int num);

int main()
{
    int num;
    while (cin>>num)
    {
        cout<<max_continous1(num)<<endl;
    }
    system("pause");
}
 int max_continous1(int num)
 {
    int count=0, maxcount=0;
    for (int i=0;i<31;i++)
    {
        if ((num>>i)&1)
        {    
            count++;
            maxcount=max(maxcount,count);
        }
        else
        {
            count=0;
        }       
    }
    return maxcount;
 }