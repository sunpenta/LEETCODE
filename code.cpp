#include <bits/stdc++.h>
using namespace std;
int numSimilarGroups(vector<string>& strs);
bool checkSimilar(string s, string t);
int main()
{
     vector<string> strs ={"tars","rats","arts","star"};
     cout<<checkSimilar(strs[2],strs[3])<<" ";
     cout<<numSimilarGroups(strs)<<endl;
     return 0;
}

    bool checkSimilar(string s, string t)
    {
        int n=s.length();
        for (int i=0; i<n-1; ++i) // [i,j] C(n,2)
        {
            for (int j=i+1; j<n; ++j)
            {
                if (s[i]==t[j] && s[j]==t[i])
                    return true;
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