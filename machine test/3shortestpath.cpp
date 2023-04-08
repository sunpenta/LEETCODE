// 迷宫最短路径
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>shortestPath(vector<vector<int>>& matrix);

int main()
{
    int row, col; 
    while(cin>>row>>col)
    {
        vector<vector<int>>matrix(row,vector<int>(col));
        for (int i=0;i<row;i++)
        {
            for (int j=0;j<col;j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        vector<vector<int>>ans=shortestPath(matrix);
        for (auto loc:ans)
        {
            cout<<"("<<loc[0]<<","<<loc[1]<<")"<<endl;
        }
    }
    system("pause");
}
bool dfs(vector<vector<int>>&ans,vector<vector<int>>& matrix, int row,int col)
{
    int m=matrix.size(), n=matrix[0].size();
    if (row>=m || col>=n || matrix[row][col]==1) return false;
    if (row==m-1 && col==n-1)
    {
        ans.push_back({m-1,n-1});
        return true;
    }
    ans.push_back({row,col});
    if (dfs(ans,matrix,row+1,col) || dfs(ans,matrix,row,col+1))
     return true;

    ans.pop_back();
    return false;
}

vector<vector<int>>shortestPath(vector<vector<int>>& matrix)
{
    vector<vector<int>>ans;
    dfs(ans,matrix,0,0);
    return ans;
}