// 字典序最小,固定长度,包含某重复字母的子序列 - greedy+stack  l-2030
// 时间复杂度:O(n), 空间复杂度:O(n)
#include <iostream>
#include <stack>
using namespace std;
string smallestSubsequence(string s, int k, char letter, int repetition);

int main()
{
    string s="leetcode"; int k=4, repetition=2; char letter='e'; // input
    cout<<smallestSubsequence(s,k,letter,repetition)<<endl;
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
    stack<char> sk;
    sk.push(s[0]);
    for (int i=0; i<n; ++i)
    {
        char c=s[i];
        while (!sk.empty() && ((c<sk.top() && sk.size()+n-i>k && c!=letter || c==letter && cnt>repetition) 
        || k-sk.size()<repetition))
        {
            sk.pop();
            if (c==letter)
                repetition+=1;
        }
        while (sk.size()<k)
        {
            sk.push(c);
            if (c==letter)
                repetition-=1;
        }
        if (c==letter)
            cnt-=1;
    }
    string res="";
    while (!sk.empty())
    {
        res=sk.top()+res;
        sk.pop();
    }
    return res;
}