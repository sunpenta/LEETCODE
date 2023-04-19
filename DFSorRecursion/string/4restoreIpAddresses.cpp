// 复原ip地址 - 回溯  l-93 -DP\numDecodings
// 有效IP地址由4个整数组成，每个整数∈[0,255]，且无前导0，整数之间用 '.' 分隔；1 <= s.length <= 20
#include<bits/stdc++.h>
using namespace std;
vector<string>restoreIpAddresses(string s);

int main()
{
    string s="101023"; // 输入
    vector<string>ips=restoreIpAddresses(s); // 输出:
    for (auto ip:ips) // {"1.0.10.23","1.0.102.3",10.1.0.23","10.10.2.3","101.0.2.3"}
        cout<<ip<<endl;
    system("pause");
}

// ips:所有ip组合; ip:ip地址,包含4个部分; index:s的搜索下标
void dfs(vector<vector<string>>& ips, vector<string>& ip, string &s, int index)
{
    if (ip.size()==4 && index==s.length())
    {
        ips.emplace_back(ip);
        return;
    }

    for (int i=index; i<s.length(); i++)
    {
        if (s[index]=='0' && i-index>=1) break; // 无前导0
        if (stoi(s.substr(index,i-index+1))>255) break; // [0,255]
        ip.emplace_back(s.substr(index,i-index+1)); // [index,i]
        dfs(ips,ip,s,i+1);
        ip.pop_back();
    }
}
// 更好理解
vector<string>restoreIpAddresses(string s) 
{
    vector<vector<string>> ips; vector<string> ip;
    int n=s.length();
    if (n<4 || n>16) return ip;
    dfs(ips,ip,s,0);
    // 用'.'把ip里的4部分拼起来
    vector<string> res;
    for (int i=0; i<ips.size(); i++)
    {
        string t=ips[i][0]; // ip的第1part
        for (int j=1;j<4;j++)
            t+='.'+ips[i][j];
        res.emplace_back(t);
    }
    return res;
}
