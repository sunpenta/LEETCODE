// 字典序最小的 k-length subsequence with Occurrences of a Letter
// 时间复杂度:O(n), 空间复杂度:O(n)
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
    
    vector<deque<int>> ind(26); // 26个字母的下标
    for (int i=0;i<n;i++) 
        ind[s[i]-'a'].emplace_back(i);
    
    int x=repetition, lastInd=-1; // x:need letters
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
            if (ans.length()+n-index>=k && cnt[index]>=x && x-(ch+'a'==letter)+i+1<=k)
            {
                ans+= ch+'a'; // update ans, x, dq,lastInd
                if (ch+'a'==letter) 
                    x--;
                lastInd=index;
                dq.pop_front();
                break; // ?
            }            
        }
    }
    return ans;
}