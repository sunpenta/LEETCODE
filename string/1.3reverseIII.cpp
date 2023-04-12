// reverse words in string - 原地 l-557
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string reverseWords(string s);

int main()
{
    string s="Let's take LeetCode contest"; // input
    cout<<reverseWords(s)<<endl; // output
}

string reverseWords(string s)
{
    int n=s.length();
    for (int i=0; i<n; i++)
    {
        if (s[i]!=' ')
        {
            int j=i;
            for (; s[j]!=' ' && j<n; j++) {}; // next space or end
            reverse(s.begin()+i, s.begin()+j);
            i=j;
        }
    }
    return s;
}