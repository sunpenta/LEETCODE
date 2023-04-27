// 最短same - kmp  l-214

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string shortestPalindrome(string s);

int main()
{
    string s="abcd"; // input
    cout<<shortestPalindrome(s)<<endl; // output:"aabbaa"
    return 0;
}

int KMP(string s)
{
    int n=s.length();
    vector<int> kmp(n+1);
    kmp[0]=-1;
    int i=0, j=-1;
    while (i<n)
    {
        while (j!=-1 && s[i]!=s[j])
            j=kmp[j];
        ++i, ++j;
        kmp[i]=j;
    }
    return kmp[n];
}
string shortestPalindrome(string s)
{
    int n=s.length();
    string rs(s.rbegin(),s.rend());
    string t=rs+'#'+s;
    int l=KMP(t);
    string tmp=s.substr(0,n-l); // remove last l-elements
    reverse(tmp.begin(),tmp.end());
    return s+tmp;
}