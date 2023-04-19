// 解数独 - 回溯+按位运算（状态压缩）  l-37
/*  ~1000 & 0xf(1111) // 1变0、0变1
    mask & (-mask) // 只保留最低位的1
    mask ^= (mask & (-mask)) // 消掉最低位的1
等价于  mask &= (mask - 1) // 消掉最低位的1   */
#include <bits/stdc++.h>
using namespace std;
void solveSudoku(vector<vector<char>>& board);
int main()
{
    vector<vector<char>>board=    
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    }; // 输入

    solveSudoku(board); // 输出
    for(int i=0; i<9; ++i) // 输出
    {
        for (int j=0; j<9; ++j)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

int row[9];
int column[9];
int box[3][3];
bool valid;
vector<pair<int, int>> spaces;
//  把1从低到高数移到第digit+1位
void flip(int i, int j, int digit) 
{
    row[i] ^= (1 << digit); // ^=,异或赋值，不同取1，相同取0
    column[j] ^= (1 << digit); // 1左移digit位
    box[i / 3][j / 3] ^= (1 << digit);
}

void dfs(vector<vector<char>>& board, int pos) 
{
    if (pos == spaces.size()) 
    {
        valid = true;
        return;
    }
    auto [i, j] = spaces[pos];
    int mask = ~(row[i] | column[j] | box[i / 3][j / 3]) & 0x1ff;//9位二进制记录没出现数字  & 0x1ff？多余
    // 1.当且仅当mask!=0时才有没出现过的digit
    // 2.mask &= (mask - 1)代表移除mask中最低位的1,表示已经被搜索 如:10100 & 10011 = 10000
    for (; mask && !valid; mask &= (mask - 1)) 
    {
        int digitMask = mask & (-mask); // 等价mask & (~mask + 1)，获取某个二进制数的 LowBit，lowbit(x)是x的二进制表达式中最低位的1所对应的值
        int digit = __builtin_ctz(digitMask); // 返回digitMask的二进制末尾0的个数
        flip(i, j, digit);
        board[i][j] = digit + '0' + 1;
        dfs(board, pos + 1);
        flip(i, j, digit); //// 撤回标记+恢复现场
    }
}

void solveSudoku(vector<vector<char>>& board) 
{
    memset(row, 0, sizeof(row)); // 以字节为单位赋值0
    memset(column, 0, sizeof(column)); // 0 0000 0000
    memset(box, 0, sizeof(box)); //  0 0001 0000
    valid = false;
    for (int i = 0; i < 9; ++i) 
    {
        for (int j = 0; j < 9; ++j) 
        {
            if (board[i][j] == '.') 
            {
                spaces.emplace_back(i, j); // 记录空格坐标
            }
            else 
            {
                int digit = board[i][j] - '0' - 1; // 1-9 char转换成0-8 int
                flip(i, j, digit);
            }
        }
    }
    dfs(board, 0);
}