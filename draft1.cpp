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
    // while (t--)
    // {
    //     string t=printJam(s,l,h);
    //     if (t!="")
    //         cout<<t<<endl;
    //     else
    //         break;
    // }
    return 0;
}

string printJam(string s, int l, int h)
{
    auto valid = [&](int i)
    {
        return (s[i]<'a'+h && s[i]>='a'+l-1);
    };
    int n=s.length();
    for (int i=n-1; i>=0; i--)
    {
        ++s[i];
        if (valid(i))
        {
            for (i = i + 1; i < n; ++i)
                s[i]='a'+l-1;
            return s;           
        }
    }
    return "";
}