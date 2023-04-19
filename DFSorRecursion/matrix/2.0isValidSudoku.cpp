// 有效的数独  l-36
#include <bits/stdc++.h>
using namespace std;
bool isValidSudoku(vector<vector<char>>& board);

int main()
{
    vector<vector<char>> board={
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, 
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, 
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, 
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, 
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, 
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, 
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, 
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, 
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    }; // input
    cout << boolalpha<< isValidSudoku(board) << endl; // output
    system("pause");
}

bool isValidSudoku(vector<vector<char>>& board)
{
    int row[9][10]={0}; // 将数组所有元素赋值为0
    int col[9][10]={0}; // 列坐标代表0-9 10个数字，只使用1-9
    int box[9][10]={0}; // (i/3)*3+j/3转换成九宫格编号

    // 遍历board
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board.size(); j++)
        {
            if(board[i][j]!='.') // !='.'比isdigit()更快
            {  
                int cur=board[i][j]-'0'; // 减去字符'0',转换成int型
                row[i][cur]++;
                col[j][cur]++;
                box[(i/3)*3+j/3][cur]++; // box行的坐标从左到右，从上到下为0-8
                if(row[i][cur]>1 || col[j][cur]>1 || box[(i/3)*3+j/3][cur]>1)
                    return false; // cur出现次数大于1次
            }
        }
    }
    return true;
}