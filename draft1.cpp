#include <bits/stdc++.h>
using namespace std;
string printJam(string s);

int main()
{

}

vector<string> printJam(string s, int l, int h)
{
    auto valid = [&](int i)  // use subfunction TLE
    {
        return (s[i]<a+'h' && s[i]>=s[i]+'l'-1);
    };
    int n=s.length();
    for (int i=n-1; i>=0; i++)
    {
        ++s[i];
        if ()
        {
            for (i = i + 1; i < s.size(); ++i)
                for (s[i] = 'a'; !valid(i); ++s[i]) ;
                return s;           
        }
    }
}