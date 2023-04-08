// 有效的括号组合-回溯法 l-22
#include<bits/stdc++.h>
using namespace std;
vector<string>parenthesis(int n);//子函数在主函数后时，声明，否则报错

int main()
{
    int n=3; //输入
    vector<string>ans=parenthesis(n); //输出
    for (auto str:ans) 
        cout<<str<<endl;
    system("pause");
}

//回溯法+剪枝
//left:当前字符串左括号数；right:当前字符串右括号数
void backtrack(vector<string> &ans,string &cur,int n,int left,int right)
{
    //终止条件
    if (cur.size()==2*n)
    {
        ans.push_back(cur);
        return;
    }   
    //判断左括号
    if (left<n)
    {
        cur.push_back({'('});
        backtrack(ans,cur,n,left+1,right);
        cur.pop_back(); //删除cur的最后一个字符,下次循环要用
    }
    //判断右括号
    if (left>right)
    {
        cur.push_back({')'});
        backtrack(ans,cur,n,left,right+1);
        cur.pop_back();
    }
}
// 生成有效括号
vector<string>parenthesis(int n)
{
    vector<string> ans;string cur;
    backtrack(ans,cur,n,0,0);
    return ans;
}