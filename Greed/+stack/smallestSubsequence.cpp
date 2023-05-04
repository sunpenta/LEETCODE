// 字典序最小,固定长度,包含某重复字母的子序列 - greedy+stack  l-2030
// 时间复杂度:O(n), 空间复杂度:O(n); s.length⋿[1,5e4], stack<char> TLE, 用string模拟stack
#include <iostream>
#include <stack>
using namespace std;
string smallestSubsequence(string s, int k, char letter, int repetition);

int main()
{
    string s="leet"; int k=3, repetition=1; char letter='e'; // input
    cout<<smallestSubsequence(s,k,letter,repetition)<<endl; // "eet"
    return 0;
}

string smallestSubsequence(string s, int k, char letter, int repetition)
{
    int cnt=0;
    for (char ch:s)
    {
        if (ch==letter)
            ++cnt;
    }
    int n=s.length();
    string sk="";
    for (int i=0; i<n; ++i)
    {
        char c=s[i];
        while (!sk.empty() && (c<sk.back() && sk.size()+n-i>k && 
        (sk.back()!=letter || sk.back()==letter && cnt>repetition)
        )) 
        {
            char cur=sk.back();
            sk.pop_back();
            if (cur==letter)
                ++repetition;
        }

        if (sk.size()<k)
        {
            if (c==letter || k-(int)sk.size()>repetition) // sk.size()-unsigned int, 不能直接比较，1>-1 false
            {
                sk.push_back(c);
                if (c==letter)
                    --repetition; // -1
            }
        }
        if (c==letter)
            --cnt;
    }
    return sk;
}