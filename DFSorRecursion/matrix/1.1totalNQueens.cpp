// N皇后 - 回溯  l-51
// 同一行，同一列，同一对角线不能有俩皇后; 'Q':皇后，'.':空格; 1<=n<= 9
#include <bits/stdc++.h>
using namespace std;
int totalNQueens(int n);

int main()
{
    int n=4; // 输入：n*n
    cout<<totalNQueens(n)<<endl; // 输出:2
    return 0;
}

// 是否符合N皇后规则
bool isValid(vector<string>&board,int n,int row,int col)
{
    // 检查同一列，同一行已在dfs()中检查过
    for (int i=0;i<row;i++)
    {
        if (board[i][col]=='Q') return false;
    }
    // 检查左上角
    for (int i=row,j=col;i>=0 && col>=0;i--,j--)
    {
        if (board[i][j]=='Q') return false;
    }
    // 检查右上角
    for (int i=row,j=col;i>=0 && j<n;i--,j++)
    {
        if (board[i][j]=='Q') return false;
    }
    return true;
}
// 从第row行开始搜索，按规则放'Q';board:棋盘,count:放置方案数，一定用&
int ways=0;
int dfs(vector<string> &board, int n, int row)
{
    if (row==n) ++ways;

    // 遍历第row行的所有列
    for (int i=0;i<n;i++)
    {
        if (isValid(board,n,row,i))
        {
            board[row][i]='Q';
            dfs(board,n,row+1);
            board[row][i]='.';
        }
    }
    return ways;
}
int totalNQueens(int n)
{
    vector<string>board(n,string(n,'.')); // 初始化为全是'.'
    return dfs(board,n,0);
}