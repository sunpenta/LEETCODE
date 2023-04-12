// reverse string - 原地  l-344
// 时间复杂度:O(n) 空间复杂度:O(1)
#include <iostream>
using namespace std;
string reverseI(string s);

int main()
{
    string s="edocteel"; // input
    cout<<reverseI(s)<<endl; // output:"leetcode"
}

string reverseI(string s)
{
    int n=s.length(), tmp;
    for (int i=0, j=n-1; i<=j; ++i, --j)
    {
        tmp=s[i]; s[i]=s[j]; s[j]=tmp;
    }
    return s;
}