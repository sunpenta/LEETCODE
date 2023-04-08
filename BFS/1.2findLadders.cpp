// 单词接龙-哈希bfs+dfs  l-126
// beginWord.length∈[1,10], wordList.length∈[1,5000]
#include <bits/stdc++.h>
using namespace std;
vector<vector<string>>findLadders(string beginWord,string endWord,vector<string>& wordList);

int main()
{
    string beginWord="a", endWord="c";//string beginWord="hit", endWord = "cog";
    vector<string>wordList = {"a","b","c"};//vector<string>wordList = {"hot","dot","dog","lot","log","cog"}; // 输入
    vector<vector<string>>ans=findLadders(beginWord,endWord,wordList); // 输出
    for (auto path:ans)
    {
        for (string str:path)
            cout<<str<<" ";
        cout<<endl;
    }
    system("pause");
}
// 从单词s开始搜索，直到找到beginWord
void dfs(vector<vector<string>>&ans,vector<string>&path,unordered_map<string,int>&dist,string beginWord,string s)
{
    if (s==beginWord) // 倒着搜索
    {
        reverse(path.begin(),path.end());
        ans.emplace_back(path);
        reverse(path.begin(),path.end());
        return;
    }
    string tmp=s;
    for (char &ch:s)
    {
        for (char c='a';c<='z';c++)
        {
            ch=c;
            if (dist.count(s) && dist[s]+1==dist[tmp])
            {
                path.emplace_back(s);
                dfs(ans,path,dist,beginWord,s);
                path.pop_back();
            }
        }
        s=tmp;
    }
}
vector<vector<string>>findLadders(string beginWord,string endWord,vector<string>&wordList)
{
    unordered_set<string>words(wordList.begin(),wordList.end()); // 快速查找
    unordered_map<string,int>dist; // 当前单词到beginWord的距离
    dist[beginWord]=0;
    queue<string>q; // 存单词
    q.emplace(beginWord);
    while (!q.empty())
    {
        string cur=q.front();
        q.pop();
        string next=cur;
        for (char &ch:next)
        {
            char tmp=ch;
            for (char c='a';c<='z';c++)
            {
                ch=c;
                if (ch==tmp) continue;
                if (words.count(next) && !dist.count(next)) // 在wordList里,且未计算过距离
                {
                    dist[next]=dist[cur]+1;
                    if (next==endWord) break;
                    q.emplace(next);
                }
            }
            ch=tmp; // 恢复原状
        }
    }
    for (auto it:dist) cout<<it.first<<" "<<it.second<<endl;
    vector<vector<string>>ans; vector<string>path;
    if (!words.count(endWord)) return ans;
    path.emplace_back(endWord);
    dfs(ans,path,dist,beginWord,endWord);
    return ans;
}