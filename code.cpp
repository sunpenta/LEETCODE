#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2)
{
    int m = s1.length(), n = s2.length();
    if (n < m)
        return false;
    array<int, 26> mp1{0};
    for (char ch : s1)
        mp1[ch - 'a']++;
    array<int, 26> mp2;
    for (int i = 0; i + m <= n; i++)
    {
        mp2 = mp1;
        bool flag = true;
        for (char ch : s2.substr(i, m))
        {
            if (find(mp2.begin(), mp2.end(), ch) == mp2.end()) // not find
            {
                flag = false;
                break;
            }
            else
                mp2[ch - 'a']--;
        }
        if (flag)
            return true;
    }
    return false;
}
int main()
{
    string s1 = "ab", s2 = "eidbaooo"; 
    system("pause");
}
