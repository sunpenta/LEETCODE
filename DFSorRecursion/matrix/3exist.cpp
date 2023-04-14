// 单词搜索-dfs l-79
// 1 <= m, n <= 6; 1 <= word.length <= 15
#include <bits/stdc++.h>
using namespace std;
bool exist(vector<vector<char>>&board,string &word);

int main()
{
    vector<vector<char>>board={
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    }; 
    string word = "eat"; // 输入
    cout<<boolalpha<<exist(board,word)<<endl; // 输出:true
    system("pause");
}

// 从board[row][col]开始搜索，是否可以搜到字符串word
bool dfs(vector<vector<char>>&board,int row,int col,string &word,int index)
{
    int m=board.size(), n=board[0].size(), len=word.length();
    if (index==len) // 满足条件
        return true;
    if (row>=m || row<0 || col>=n || col<0) // 越界
        return false;
    if (board[row][col]!=word[index]) // 与当前字符不相等
        return false;
    if (board[row][col]==' ') // 已搜索过
        return false;
    board[row][col]=' '; // 标记已搜索过；在原矩阵修改，不用visit[][]
    if (dfs(board,row+1,col,word,index+1) // 向下 不能用index++或++index
    ||  dfs(board,row,col+1,word,index+1) // 向右
    ||  dfs(board,row-1,col,word,index+1) // 向上
    ||  dfs(board,row,col-1,word,index+1)) // 向左
        return true;
    board[row][col]=word[index]; // 恢复原状
    return false;
}

bool exist(vector<vector<char>>&board,string &word)
{
    int m=board.size(), n=board[0].size();
    // 找搜索起点board[i,j]
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (board[i][j]==word[0])
            {
                if (dfs(board,i,j,word,0))
                return true;
            }
        }
    }
    return false;
}