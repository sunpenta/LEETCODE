#include <iostream>
#include <vector>
using namespace std;
bool reach(vector<vector<int>>& maze, int rowStart, int colStart, int rowEnd, int colEnd);
int main()
{
     vector<vector<int>> maze={
          {0,0,1,0,0},
          {0,0,0,0,0},
          {0,0,0,1,0},
          {1,1,0,1,1},
          {0,0,0,0,0}
     };
     int rowStart=0, colStart=4, rowEnd=4, colEnd=4;
     cout<<boolalpha<<reach(maze,rowStart,colStart,rowEnd,colEnd)<<endl;
     return 0;
}

bool dfs(vector<vector<int>>& maze, int rowEnd, int colEnd, int i, int j)
{
     int m=maze.size(), n=maze[0].size();
     if (i<0 || i>=m || j<0 || j>=n) return false; // 越界
     if (i==rowEnd && j==colEnd) return true;
     if (maze[i][j]==-1) return false; // 已访问
     maze[i][j]=-1; // 标记
     if (maze[i][j]==1) return false;
     int dx[4]={1,-1,0,0};
     int dy[4]={0,0,1,-1};
     for (int d=0; d<4; ++d)
     {
          int nx=i+dx[d], ny=j+dy[d];
          if (dfs(maze,rowEnd,colEnd,nx,ny))
               return true;
     }
     return false;
}
bool reach(vector<vector<int>>& maze, int rowStart, int colStart, int rowEnd, int colEnd)
{
     return dfs(maze,rowEnd,colEnd,rowStart,colStart);
}