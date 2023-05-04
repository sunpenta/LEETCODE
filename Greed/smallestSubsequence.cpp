// 字典序最小,固定长度,包含某重复字母的子序列 - greedy+stack  l-2030
// 时间复杂度:O(n), 空间复杂度:O(n)
#include <iostream>
#include <stack>
using namespace std;
string smallestSubsequence(string s, int k, char letter, int repetition);

int main()
{
    string s="leet"; int k=3, repetition=1; char letter='e'; // input
    cout<<smallestSubsequence(s,k,letter,repetition)<<endl; // 
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
        bool flag1=(c<sk.top() && sk.size()+n-i>k && (sk.top()!=letter || sk.top()==letter && cnt>repetition));
        bool flag2=(k-sk.size()<repetition);
        while (!sk.empty() && ((c<sk.top() && sk.size()+n-i>k && (sk.top()!=letter || sk.top()==letter && cnt>repetition)) 
        || k-sk.size()<repetition))
        {
            char cur=sk.top();
            sk.pop();
            if (cur==letter)
                repetition+=1;
        }

        if (sk.size()<k)
        {
            sk.push(c);
            if (c==letter)
                repetition-=1; // -1
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