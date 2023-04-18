// 单词接龙 - hashTable + bfs  l-127  -l-433|-dfs/matrix/3.exist|-Tree/traveral/2.1levelOrder
// ladder:最短转换序列:beginWord->s1->...->endWord(每对相邻单词间仅单个字母不同)
#include <bits/stdc++.h>
using namespace std;
int ladderLength(string beginWord,string endWord,vector<string>& wordList);

int main()
{
    string beginWord="hit", endWord = "cog";
    vector<string>wordList = {"hot","dot","dog","lot","log","cog"}; // 输入
    cout<<ladderLength(beginWord,endWord,wordList)<<endl; // 输出:5 {}
    return 0;;
}

unordered_map<string,int>wordId; // <word，id>
int id=0; // 编号; 全局
vector<vector<int>>edges; // 无向图
// 对单词编号
void addWord(string word)
{
    if (!wordId.count(word))
    {
        wordId[word]=id++; // suffix; 最终id:所有单词个数
        edges.emplace_back();
    }
}
// 连边，建无向图
void addEdge(string word)
{
    addWord(word);
    int id1=wordId[word];
    for (char &ch:word)
    {
        char tmp=ch;
        ch='*'; // 虚拟节点
        addWord(word);
        int id2=wordId[word];
        edges[id1].emplace_back(id2); // 无向图连边
        edges[id2].emplace_back(id1);
        ch=tmp; // 恢复原状
    }
}
int ladderLength(string beginWord,string endWord,vector<string>& wordList)
{
    addEdge(beginWord); // hash的最终排序不保证是插入顺序
    for (string word:wordList)
        addEdge(word);
    if (!wordId.count(endWord)) return 0; // 不在字典里

    vector<int>dist(id,INT_MAX); // 当前单词到beginWord的距离
    int beginId=wordId[beginWord], endId=wordId[endWord];
    dist[beginId]=0;
    
    queue<int>q; // 存单词编号
    q.emplace(beginId);
    while (!q.empty())
    {
        int cur=q.front();
        q.pop();
        if (cur==endId)
        {
            for (int dis:dist) cout<<dis<<endl;
            return dist[endId]/2+1;  
        }
        for (int id:edges[cur])
        {
            if (dist[id]==INT_MAX) // 未访问过
            {
                dist[id]=dist[cur]+1;
                q.emplace(id);
            }
        }
    }
    return 0;
}


