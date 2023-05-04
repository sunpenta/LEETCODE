// 字典序最小,固定长度,包含某重复字母的子序列 - greedy+stack  l-2030
// 时间复杂度:O(n), 空间复杂度:O(n); s.length⋿[1,5e4]容易TLE
#include <iostream>
#include <stack>
using namespace std;
string smallestSubsequence(string s, int k, char letter, int repetition);

int main()
{
    string s="leet"; int k=3, repetition=1; char letter='e'; // input
    //cout<<smallestSubsequence(s,k,letter,repetition)<<endl; // "eet"
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
    for (int i=0; i<n; ++i)
    {
        char c=s[i];
        
        bool flag2=(k-sk.size()<repetition);
        while (!sk.empty() && ((c<sk.top() && sk.size()+n-i>k && 
        (sk.top()!=letter || sk.top()==letter && cnt>repetition)) 
        || k-(int)sk.size()<repetition)) // sk.size() - unsigned int
        {
            char cur=sk.top();
            sk.pop();
            if (cur==letter)
                ++repetition;
        }

        if (sk.size()<k)
        {
            sk.push(c);
            if (c==letter)
                --repetition; // -1
        }
        if (c==letter)
            --cnt;
    }

    string res="";
    while (!sk.empty())
    {
        res=sk.top()+res;
        sk.pop();
    }
    return res;
}