// 解数独 - hash+回溯  l-37
// 初始值设位置不同，leco和此处输出不同; '.': space
#include <bits/stdc++.h>
using namespace std;
void solveSudoku(vector<vector<char>>&board);

int main()
{
    vector<vector<char>>board={
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    }; // input
    solveSudoku(board); 
    for(int i=0; i<9; ++i) // 输出
    {
        for (int j=0; j<9; ++j)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

bool row[9][9]={false}; // 数组声明时能初始化，后不能
bool col[9][9]={false};
bool box[9][9]={false};
bool valid; // 标记当前查找的结果是否有效
vector<pair<int,int>> spaces; // 存储空格坐标
// pos:第pos个空格
void dfs(vector<vector<char>>& board, int pos)
{
    if(pos==spaces.size()) // 终止条件:遍历完最后一个空格
    {
        valid=true;
        return;
    }
    auto [i,j]=spaces[pos];
    // 遍历1-9 9个数字
    for(int digit=0; digit<9 && !valid; digit++) // 变量不能设为i,与行i重复
    { 
        // 如果digit没在第i行，第j列和第(i/3)*3+j/3个九宫格里出现，添加到board
        if(!row[i][digit] && !col[j][digit] && !box[(i/3)*3+j/3][digit]) // 崩溃定位:digit写成i
        { 
            board[i][j]=digit+'0'+1; // 0-8 转换成 '1'-'9'
            row[i][digit]=col[j][digit]=box[(i/3)*3+j/3][digit]=true;
            dfs(board,pos+1); // 继续以pos+1为起始坐标查找
            row[i][digit]=col[j][digit]=box[(i/3)*3+j/3][digit]=false; // 撤回标记，恢复现场
        }  
    }    
}

void solveSudoku(vector<vector<char>>& board){
    valid=false; 
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(board[i][j]=='.')
            {
                spaces.emplace_back(i,j); // 记录空格坐标
            }
            else
            {
                int digit=board[i][j]-'0'-1; // '1'-'9'-> 0-8
                row[i][digit]=col[j][digit]=box[(i/3)*3+j/3][digit]=true; 
            }
        }
    }
    dfs(board,0);
}

/*
    bool line[9][9];
    bool column[9][9];
    bool block[3][3][9]; // 三维数组
    bool valid;
    vector<pair<int, int>> spaces;
void dfs(vector<vector<char>>& board, int pos) {
    if (pos == spaces.size()) {
        valid = true;
        return;
    }

    auto [i, j] = spaces[pos];
    for (int digit = 0; digit < 9 && !valid; ++digit) {
        if (!line[i][digit] && !column[j][digit] && !block[i / 3][j / 3][digit]) {
            line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
            board[i][j] = digit + '0' + 1;
            dfs(board, pos + 1);
            line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = false;
        }
    }
}

void solveSudoku(vector<vector<char>>& board) {
    memset(line, false, sizeof(line));
    memset(column, false, sizeof(column));
    memset(block, false, sizeof(block));
    valid = false;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.') {
                spaces.emplace_back(i, j);
            }
            else {
                int digit = board[i][j] - '0' - 1;
                line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
            }
        }
    }

    dfs(board, 0);
}
*/