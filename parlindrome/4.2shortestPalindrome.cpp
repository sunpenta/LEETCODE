// 最短回文串 - recursion  l-214
// 在string前加字母，使它成为最短回文串；length⋿[0,5e4]
#include <iostream>
#include <algorithm>
using namespace std;
string shortestPalindrome(string s);

int main()
{

}

string shortestPalindrome(string s)
{
    int n=s.length();
    int i=0;
    for (int j=n-1; j>=0; --j)
    {
        if (s[i]==s[j])
            ++i;
    }
    
}