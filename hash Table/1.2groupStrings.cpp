// 移位字符串分组-hash
#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> groupStrings(vector<string>& strs);

int main()
{   
    vector<string>strs={"abc", "bcd", "xyz", "nat", "bat"};  // 输入        
    vector<vector<string>>ans=groupStrings(strs); // 输出: {{"abc", "bcd", "xyz"}, {"nat"}, {"bat"}}
    for (int i=0;i<ans.size();i++)
    {
        for (auto str:ans[i])
            cout <<str<< " ";
        cout<<endl;
    }    
    system("pause");
}

vector<vector<string>> groupStrings(vector<string>& strs)
{
    vector<vector<string>>ans;
    unordered_map<string,int>map; // <偏移量,编号>
    int index=0;
    for (string &str:strs)
    {
        string tmp=str;
        for (int i=0;i<tmp.length();i++)
            tmp[i]=(str[i]-str[0]+26)%26; // 当>z或者<a时，+26取模处理防止越界; 
        if (!map.count(tmp))
        {
            map[tmp]=index++;
            ans.push_back({str});
        }
        else
        {
            ans[map[tmp]].emplace_back(str);
        }      
    }
    return ans;
} 

/*
vector<vector<string>> groupStrings(vector<string>& strings) {
    // 根据函数返回值定义存储结果的变量 
    vector<vector<string>> result;
    unordered_map<string, vector<string>> map;
    for(auto & str : strings){
        string key = str;
        //将输入的字符串都转为第一个字符为a的字符串，以此为key
        for(int i = 0; i < key.length(); i++)
            // 当超过z或者小于a时，取模处理防止越界+26 
            key[i] = (str[i] - str[0] + 26) % 26+'a';
        //cout<<key<<endl;
        map[key].push_back(str);
    }
    for(auto it = map.begin(); it != map.end(); it++)
        result.push_back(it->second);
    return result;
}
*/