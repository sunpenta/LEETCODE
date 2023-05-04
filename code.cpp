#include <bits/stdc++.h>
using namespace std;
int numSimilarGroups(vector<string>& strs);
bool checkSimilar(string s, string t);
    string predictPartyVictory(string senate) {
        int n=senate.length();
        vector<bool> vote(n,true);
        int count_R=0, count_D=0;
        for (char ch:senate)
        {
            if (ch=='R') ++count_R;
            else ++count_D;
        }
        while (count_R>0 && count_D>0)
        {
            int i=0,j=1;
            for (; i<n && j<n; ++i,++j)
            {
                while (!vote[i]) ++i;
                while (!vote[j]) ++j;
                while (senate[i]==senate[j]) ++j;
                if (vote[i] && senate[i]!=senate[j] && vote[j])
                {
                    vote[j]=false;
                    if (senate[j]=='R') --count_R;
                    else --count_D;
                }
            }
            if (j>n && vote[j])
            {
                j=n-1;
                while (!vote[--j]){}
                if (j!=n-1) 
                {
                    vote[j]=false;
                    if (senate[j]=='R') --count_R;
                    else --count_D;
                }
            }
        }
        return count_D==0? "Radiant":"Dire";
    }
int main()
{
     string senate="DDRRR";
     cout<<predictPartyVictory(senate)<<endl;
     return 0;
}

    bool checkSimilar(string s, string t)
    {
        int n=s.length();
        for (int i=0; i<n-1; ++i) // [i,j] C(n,2)
        {
            for (int j=i+1; j<n; ++j)
            {
               string tmp=s;
               swap(s[i],s[j]);
               if (s==t)
                    return true;
               s=tmp;
            }
        }
        return false;
    }
    int numSimilarGroups(vector<string>& strs) {
        int groups=0;
        queue<string> q;
        int n=strs.size();
        vector<int> visited(n,0);
        for (int i=0; i<n; ++i)
        {
            if (visited[i]==0)
            {
                q.push(strs[i]);  
                visited[i]=1;
                groups++;
            }    
            while (!q.empty())
            {
                string word=q.front(); q.pop();
                for (int j=0; j<n; ++j)
                {   
                    string str=strs[j];
                    if (visited[j]==0 && checkSimilar(word,str))
                    {
                        q.push(str);
                        visited[j]=1;
                    }
                }
            }
        }
        return groups;
    }