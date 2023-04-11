// reverse words in string - 原地修改 l-557
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string reverseWords(string s);

int main()
{
    string s="Let's take LeetCode contest"; // input
    cout<<reverseWords(s)<<endl; // output
    system("pause");
}

string reverseWords(string s)
{
    int n=s.length();
    for (int i=0; i<n; i++)
    {
        if (s[i]!=' ')
        {
            int j=i; // next space or end
            for (; s[j]!=' ' && j<n; j++) {};
            reverse(s.begin()+i, s.begin()+j);
            i=j-1;
        }
    }
    return s;
}