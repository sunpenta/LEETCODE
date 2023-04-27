// 最短same - kmp  l-214
// 在string前加字母，使它成为最短回文串；length⋿[0,5e4]
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string shortestPalindrome(string s);

int main()
{
    string s="aabba"; // input
    cout<<shortestPalindrome(s)<<endl; // output:"abbaabba"
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
    string rs(s.rbegin(),s.rend());
    string t=rs+'#'+s;
    int l=KMP(t);
    string tmp=s.substr(0,l);
    reverse(tmp.begin(),tmp.end());
    return s+tmp;
}