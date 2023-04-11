// 解N皇后-回溯  l-51   
// 同一行，同一列，同一对角线不能有俩皇后
#include <bits/stdc++.h>
using namespace std;
vector<vector<string>>solveNQueens(int n);

int main()
{
    int n=4; // 输入
    vector<vector<string>> ans=solveNQueens(n); // 输出
    for (int i=0;i<ans.size();i++) // {{".Q..",     {"..Q.", 
    {                              //   "...Q",      "Q...",
        for (auto s:ans[i])        //   "Q...",      "...Q",
            cout<<s<<endl;         //   "..Q."},     ".Q.."}
        cout<<endl;
    }
    system("pause");
}

// 判断当前行列的棋局符合规则
bool isValid(vector<string>& board,int n,int row,int col)
{
    // 向上,同一列(dfs按列循环，同一行符合规则)
    for (int i=0;i<row;i++)
    {
        if (board[i][col]=='Q') return false;
    }
    // 左上斜对角
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q') return false;
    }
    // 右上斜对角
    for (int i=row,j=col;i>=0 && j<n;i--,j++)
    {
        if (board[i][j]=='Q') return false;           
    }
    return true;
}

// 按行回溯 ans:返回所有可能皇后位置；board:皇后位置（注：每个递归的棋盘都是单独的，不能用&board,容易造成数据错误）；row:行
void dfs(vector<vector<string>>& ans,vector<string>& board,int n,int row)
{
    if (row==n) // 满足条件
    {
        ans.emplace_back(board);
        return;
    }

    for (int col=0;col<n;col++) // 遍历row行
    {
        if (isValid(board,n,row,col)) //如果当前布局符合N皇后规则
        {
            board[row][col]='Q'; // 放置皇后
            dfs(ans,board,n,row+1);
            board[row][col]='.'; // 回溯
        }
    }
}

vector<vector<string>>solveNQueens(int n)
{
    vector<vector<string>>ans;
    vector<string>board(n,string(n,'.')); // 棋盘初始化为'.'
    dfs(ans,board,n,0);
    return ans;
}