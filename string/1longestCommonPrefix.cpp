// 最长公共前缀 l-14
#include <bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>& strs);

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    string ans=longestCommonPrefix(strs);
    for (auto a:ans)
        cout << a;
    cout<<endl;
    system("pause");
}

string longestCommonPrefix(vector<string>& strs)
{
    string ans;
    if (strs.empty()) return ans;
    //排序
    sort(strs.begin(), strs.end()); 
    // 比较头尾
    string s1 = strs.front();
    string s2 = strs.back();
    int ll;
    ll = min(s1.size(), s2.size());
    int i;
    for (i = 0; i < ll && s1[i] == s2[i]; i++) ;
    return s1.substr(0, i);   
}