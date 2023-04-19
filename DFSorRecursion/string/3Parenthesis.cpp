// 有效的括号组合 - 回溯  l-22
#include<bits/stdc++.h>
using namespace std;
vector<string> generateParenthesis(int n);

int main()
{
    int n=3; // 输入
    vector<string>ans=generateParenthesis(n); // 输出
    for (auto str:ans)
        cout<<str<<endl;
    return;
}

// 回溯+剪枝; left:当前字符串左括号数；right:当前字符串右括号数
void backtrack(vector<string> &ans,string &cur,int n,int left,int right){
    if (cur.size()==2*n) // 终止条件
    {
        ans.push_back(cur);
        return;
    }   
    // 判断左括号
    if (left<n)
    {
        cur.push_back({'('});
        backtrack(ans,cur,n,left+1,right);
        cur.pop_back(); // 删除cur的最后一个字符,下次循环要用
    }
    // 判断右括号
    if (left>right)
    {
        cur.push_back({')'});
        backtrack(ans,cur,n,left,right+1);
        cur.pop_back(); // 撤销
    }
}

vector<string>generateParenthesis(int n)
{
    vector<string>ans; 
    string cur; // 当前字符串
    backtrack(ans,cur,n,0,0); // 回溯
    return ans;
}