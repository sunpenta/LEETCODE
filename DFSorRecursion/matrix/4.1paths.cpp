// 不同路径-dfs(dp)  l-62 -DP/matrix/1.1
// 从左上角到右下角；只能向右或向下（即，只能进不能退); -> 2d array
#include <bits/stdc++.h>
using namespace std;
vector<vector<string>>Paths(int m, int n);

int main()
{
    int m=4; int n=4; // 输入
    vector<vector<string>> ans=Paths(m,n); // 输出
    for (int i=0; i<ans.size(); i++)
    {
        for (auto row:ans[i])
        {
            for (int i:row)
                cout<<i<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}

void dfs(vector<vector<string>>&maps, vector<string>map, int m, int n, int row, int col)
{
    if (row>=m || col>=n) return; // 超过界限
    
    if (row==m-1 && col==n-1 ) // 终止条件
    {
        maps.emplace_back(map);
        return;
    }

    if (map[row][col]=='0')
    {
        map[row][col]='1';
    }
    dfs(maps,map,m,n,row+1,col);
    dfs(maps,map,m,n,row,col+1);
}

vector<vector<string>> Paths(int m, int n) 
{
    vector<vector<string>> maps; 
    vector<string> map(m,string(n,'0'));
    dfs(maps,map,m,n,0,0); // [0,0]
    return maps;
}