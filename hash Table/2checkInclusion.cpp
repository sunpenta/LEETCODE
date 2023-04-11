// Permutation in string - hash table  l-567
// s2 include s1's permutation
#include <iostream>
#include <string>
#include <array>
using namespace std;
bool checkInclusion(string s1, string s2);

int main()
{
    string s1="hello", s2="oohelabe"; // input
    cout<<boolalpha<<checkInclusion(s1,s2)<<endl; // output:false
    system("pause");
}

bool checkInclusion(string s1, string s2)
{
    int m=s1.length(), n=s2.length();
    array<int, 26> mp1, mp2;
    for (char ch:s1) mp1[ch-'a']++;

    for (int i=0; i<m; i++) ++mp2[s2[i]-'a'];
    if (mp1==mp2) return true; // int[]不能判==
    for (int i=m; i<n; i++)
    {
        --mp2[s2[i-m]-'a'];
        ++mp2[s2[i]-'a'];
        if (mp1==mp2) return true;
    }
    return false;
}
