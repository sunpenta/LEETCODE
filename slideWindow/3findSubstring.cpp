// 串联所有字符串的子串开始索引-滑动窗口+map  l-30
// 1 <= s.length <= 1e4; 1 <= words.length <= 5000; 1 <= words[i].length <= 30
#include <bits/stdc++.h>
using namespace std;
vector<int> findSubstring(string s,vector<string>&words);

int main()
{   
    string s="barfoofoobarthefoobarman";
    vector<string> words{"bar","foo","the"}; //输入        
    vector<int> ans=findSubstring(s,words); // 输出:[6,9,12]
    for (auto c:ans) 
        cout <<c<< " ";
    cout<<endl;
    system("pause");
}

vector<int> findSubstring(string s,vector<string>&words)
{
    vector<int> ans; // 存放所有目标开始下标
    int n = s.size();
    int numwords = words.size(), sizeword = words[0].size();

    //words单词到次数映射
    unordered_map<string,int>targetmap;
    for (auto word:words)
    {
        ++targetmap[word];
    }

    for (int i=0;i<sizeword;i++) // 这样循环可覆盖所有s
    {   
        int left=i,right=i; // 滑动窗口:left right:左右下标
        int cnt=0; // 当前单词数
        unordered_map<string,int>curmap; // 记录当前单词到次数的映射
        while (right+sizeword<=n)
        {
            string curword=s.substr(right,sizeword);
            right+=sizeword; // 更新right
            // 若当前单词在words中
            // if (targetmap.find(curword) != targetmap.end())
            if (targetmap.count(curword)) // 对象是targetmap而不是curmap
            {
                ++curmap[curword];
                ++cnt;  
                // 若当前map单词多于words中单词,更新curmap,cnt,left
                while (curmap[curword]>targetmap[curword]) // 注意while
                {
                    string tmp=s.substr(left,sizeword); // 右边不要写成left+sizeword
                    --curmap[tmp];
                    --cnt;
                    left+=sizeword;
                }

                if (cnt==numwords)
                {
                    ans.emplace_back(left);
                }
            }
            else
            {
                left=right;
                curmap.clear();
                cnt=0;
            }
        }
    }
    return ans;
}
