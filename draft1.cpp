#include <bits/stdc++.h>
using namespace std;
string printJam(string s, int l, int h);

int main()
{
    // int l, h, w;
    // cin>>l>>h>>w;
    // string s;
    // cin>>s;
    int t=5;
    string s="bdfij"; int l=2, h=10;
    cout<<s<<endl;
    cout<<printJam(s,l,h)<<endl;
    while (t--)
    {
        s=printJam(s,l,h);
        if (s!="")
            cout<<s<<endl;
        else
            break;
    }
    return 0;
}

string printJam(string s, int l, int h)
{
    auto valid = [&](int i)
    {
        return (s[i]<'a'+h && s[i]>='a'+l-1 && s[i]>s[i-1]);
    };
    int n=s.length();
    for (int i=n-1; i>=0; i--)
    {
        ++s[i];     
        if (s[i]<'a'+h && s[i]>='a'+l-1)
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