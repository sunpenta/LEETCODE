// 字典序最小的 k-length subsequence with Occurrences of a Letter
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
string smallestSubsequence(string s, int k, char letter, int repetition);

int main()
{
    string s="leetcode"; int k = 4; char letter = 'e'; int repetition = 2; // input
    cout<<smallestSubsequence(s,k,letter,repetition)<<endl; // output:"ecde"
    return 0;
}


string smallestSubsequence(string s, int k, char letter, int repetition) 
{
    int n=s.length();
    int cnt[n]; // number of letter in s[i,n-1]
    cnt[n-1]=(s[n-1]==letter);
    for (int i=n-2;i>=0;--i) 
        cnt[i]=cnt[i+1]+(s[i]==letter);
    
    vector<deque<int>> ind(26);
    for (int i=0;i<n;i++) 
        ind[s[i]-'a'].push_back(i);
    
    int countr=repetition, lastInd=-1;
    string ans="";
    for (int i=0; i<k; i++)
    {
        for (int ch=0; ch<26; ch++)
        {
            auto& dq=ind[ch];           
            while (!dq.empty() && dq.front()<=lastInd) // remove invalid index
                dq.pop_front();
            if (dq.empty()) continue;
            // satisfy k,rep
            int index=dq.front();
            if (ans.length()+n-index>=k && cnt[index]>=countr && countr-(ch+'a'==letter)+i+1<=k)
            {
                ans+= ch+'a'; // update ans, countr, dq,lastInd
                if (ch+'a'==letter) countr--;
                lastInd=index;
                dq.pop_front();
                break; // ?
            }            
        }
    }
    return ans;
}