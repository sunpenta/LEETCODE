// 复原ip地址-回溯  l-93
// 有效IP地址由4个整数组成，每个整数∈[0,255]，且无前导0，整数之间用 '.' 分隔；1 <= s.length <= 20
#include<bits/stdc++.h>
using namespace std;
vector<string> restoreIpAddresses(string s);

int main()
{
    string s="101023"; // 输入
    vector<string> ips=restoreIpAddresses(s); // 输出:
    for (auto ip:ips) // {"1.0.10.2.3","1.0.102.3",10.1.0.23","10.10.2.3","101.0.2.3"}
        cout<<ip<<endl;
    return 0;
}

// ips:所有ip组合；ip:1个ip地址; count:ip的第？个部分；index:s的搜索下标
void dfs(vector<string>& ips, string ip, string& s, int count, int index)
{
    if (index+3*(4-count)<s.length()) return; // 剪枝，剩余count部分，超过3位数字
    if (count==4 && index==s.length())
    {
        ip.pop_back(); // 把最后1个'.'删掉
        ips.emplace_back(ip); // 前面多1个'.'
        return;
    }

    for (int len=1; len<=3 && index+len<=s.length(); len++) // ip的每一部分取1-3位数
    {
        if (s[index]=='0' && len>1) break; // 无前导0
        if (len==3 && s.substr(index,len)>"255") break; // [0,255]
        dfs(ips,ip+s.substr(index,len)+'.',s,count+1,index+len); // ip不可是&; 无需撤销，更快
    /*  ip+=(s.substr(index,len)+'.'); // '.'+ [index,index+len)
        dfs(ips,ip,s,count+1,index+len);
        ip=ip.substr(0,index+count);  // ip可是&*/
    }
}

vector<string>restoreIpAddresses(string s)
{
    int n=s.length();
    vector<string> ips; string ip;
    if (n<4 || n>16) return ips;
    dfs(ips,ip,s,0,0);
    return ips;
}
