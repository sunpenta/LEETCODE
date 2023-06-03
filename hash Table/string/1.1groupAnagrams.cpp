// 字母异位词分组 - hash l-49
#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs);

int main()
{   
    vector<string>strs={"eat", "tea", "tan", "ate", "nat", "bat"};  // 输入        
    vector<vector<string>>ans=groupAnagrams(strs); // 输出:{{"bat"},{"nat","tan"},{"ate","eat","tea"}}
    for (int i=0;i<ans.size();i++)
    {
        for (auto str:ans[i])
            cout <<str<< " ";
        cout<<endl;
    }        
    system("pause");
}

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    vector<vector<string>>ans;
    unordered_map<string,int>map;
    int index=0; // 当前字符串的下标
    for (auto &str:strs)
    {
        string tmp=str;
        sort(tmp.begin(),tmp.end()); // *排序*
        if (!map.count(tmp)) // map中没有字符串tmp
        {
            map[tmp]=index++;
            ans.push_back({str}); // 不可用emplace_back()?; 加{}
        }
        else // map中有字符串str
        {
            ans[map[tmp]].emplace_back(str);
        }
    }    
    return ans;
}