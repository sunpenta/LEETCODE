#include <bits/stdc++.h>
using namespace std;
string printJam(string s, int l, int h);

int main()
{
    int l, h, w;
    cin>>l>>h>>w;
    string s;
    cin>>s;    
    int t=5;           
    while (t--)
    {
        s=printJam(s,l,h);
        if (s=="")
            break;
        cout<<s<<endl;           
    }
    return 0;
}

string printJam(string s, int l, int h)
{
    int n=s.length();
    for (int i=n-1; i>=0; i--)
    {
        ++s[i];     
        if (s[i]<'a'+h)
        {
            int j=i+1;
            for (; j < n; ++j)
            {                
                s[j] = s[j-1]+1;
                if (s[j]>='a'+h) break;
            }
            if (j==n)           
                return s;                   
        }
    }
    return "";
}