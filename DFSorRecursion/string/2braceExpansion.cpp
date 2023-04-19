// 花括号展开 - 字符流+set+递归  l-1096
// 无重复组合结果；1 <= expression.length <= 60
#include <bits/stdc++.h>
using namespace std;
vector<string> braceExpansion(string expression);

int main()
{
    string expression = "{{a,z},a{b,c},{ab,z}}"; // 输入
    vector<string> res=braceExpansion(expression); // 输出: a z ab ac
    for (auto str:res)
        cout<<str<<endl;
    return 0;
}

// res:存所有花括号展开字符串，set保证无重复
void dfs(set<string>& res, string expression)
{
    int n=expression.length();
    int j=expression.find('}'); // '}'的第1个下标; .find():string类内find(), ->pos
    if (j==string::npos) // 找不到'}',即已找完最后1个'}'
    {
        res.emplace(expression);
        return;
    }
    int i=expression.rfind('{',j); // 从后向前找j前的第1个'{'
    string s1,s2,s3;
    s1=expression.substr(0,i); // '{'左边(不包含'{')的字符串:[0,i-1]
    s3=expression.substr(j+1); // '}'右边(不包含'}')的字符串:[j+1,n-1]
    stringstream ss(expression.substr(i+1,j-i-1)); // [i+1,j-1]
    while (getline(ss,s2,',')) // 把ss读入s2,忽略','
    {
        dfs(res,s1+s2+s3);
    }
}

vector<string>braceExpansion(string expression)
{
    set<string> res;
    dfs(res,expression);
    return vector<string>(res.begin(),res.end());
}