// 验证密码
#include <bits/stdc++.h>
using namespace std;
string isValid(string s);

int main()
{
    string s;
    while(cin>>s)
        cout<<isValid(s)<<endl;
    system("pause");
}
string isValid(string s)
{
    if (s.length()<=8) return "NG";

    int lowerflag=0, upperflag=0, digitflag=0, otherflag=0;
    for (char ch:s)
    {
        if (islower(ch)) lowerflag=1;
        else if (isupper(ch)) upperflag=1;
        else if (isdigit(ch)) digitflag=1;
        else if (isgraph(ch)) otherflag=1;
    }
    if (lowerflag+upperflag+digitflag+otherflag<3) return "NG";

    // repeat string(len>2)
    unordered_set<string>all_strs;
    for (int i=0;i<s.length()-3;i++)
    {
        for (int len=3;i+len<=s.length();len++)
        {
            if (all_strs.count(s.substr(i,len))) return "NG";
            all_strs.emplace(s.substr(i,len));
        }
    }
    return "OK";
}