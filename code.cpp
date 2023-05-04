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
        int R=0,D=0;
        for (int k=0; k<n; ++k) // first R
        {
            if (senate[k]=='R') 
            {
                R=k;
                break;
            }
        }
        for (int k=0; k<n; ++k) // first D
        {
            if (senate[k]=='D') 
            {
                D=k;
                break;
            }
        }        
        while (count_R>0 && count_D>0)
        {
            int i=R , j=D;
            for (; i<n && j<n; ++i,++j)
            {
            while (!vote[i] || senate[i]!='R' && i<n) ++i;
            while (!vote[j] || senate[j]!='D' && j<n) ++j;

                vote[j]=false;
                if (senate[j]=='R') --count_R;
                else --count_D;               
                if (j==n-1 && vote[j]) 
                {
                    vote[i]=false;
                if (senate[i]=='R') --count_R;
                else --count_D;
                }              
            }
            //if (count_D==0) return "Radiant";
            //else if (count_R==0) return "Dire";
        }
        return count_D==0? "Radiant":"Dire";
    }
int main()
{
     string senate="DDRRRR";
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