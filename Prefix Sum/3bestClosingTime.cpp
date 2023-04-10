// 商店最少罚款-prefix sum  l-2483
// s[i]: 'Y':ith hour有顾客, 'N':ith hour没顾客; jth:closing time, 若i<j, s[i]='N'; 若i>=j,s[i]='Y', 罚款+1
#include <iostream>
#include <vector>
using namespace std;
int bestClosingTime(string s);

int main()
{
    string s="YYNY"; // input
    cout<<bestClosingTime(s)<<endl; // output:2
}

int bestClosingTime(string s)
{
    int n=s.length();
    int profit=0, maxprofit=0, h=0; // h:closing time
    for (int i=0; i<n; i++)
    {
        profit+= s[i]=='Y'?1:-1; // replace if
        if (profit>maxprofit)
        {
            maxprofit=profit;
            h=i+1;
        }
    }
    return h;
}