// Valid Palindrome - double pointer  l-680
// s.length⋿[]
#include <iostream>
using namespace std;
bool validPalindrome(string s);

int main()
{
    string s="eedede"; // input
    cout<<boolalpha<<validPalindrome(s)<<endl; // true:remove "d", eedee"
    return 0;
}
// s[i,j] is palindrome
bool isPalindrome(string s, int i, int j)
{
    while (i<j)
    {
        if (s[i]==s[j])
        {
            ++i; --j;
        }
        else
            return false;
    }
    return true;
}
bool validPalindrome(string s)
{
    int n=s.length();
    if (n==0 || n==1 || n==2) return true;

    for (int i=0,j=n-1; i<j; ++i,--j)
    {
        if (s[i]!=s[j])
            return isPalindrome(s,i,j-1) || isPalindrome(s,i+1,j);
    }
    return true;
}